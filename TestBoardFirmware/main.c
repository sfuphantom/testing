

/**
 * main.c
 */
#include "tiny-json.h"
#include "main.h"
#include "Phantom_sci.h"
#include "hwConfig.h"
#include "gio.h"
#include "het.h"
#include "common.h"

//Drivers
#include "bse.h"
#include "apps.h"
#include "MCP48FV_DAC_SPI.h"
#include "timer.h"
#include "bms_slaves.h"

#include "validation.h"

#define TIMER_PERIOD 1000

static unsigned char UARTBuffer[200];
static unsigned char testMode[3];
static json_t mem[100];
//static bool initGUI = false;

// Static Function Declaration
static Result_t initUARTandModeHandler(TestBoardState_t *stateptr);
static Result_t bms_mode_process(TestBoardState_t *stateptr);
static void vcu_mode_process(TestBoardState_t *stateptr);
static void setPeripheralTestCases(TestBoardState_t* stateptr, json_t* json);
static json_t * JSONHandler(unsigned char *jsonstring);

//Timer functions
static void initializeTimers();

// Static global variables
static TestBoardState_t testBoardState = { IDLE, {0,0,0,0,0,0,0,0,0,0,} };
static bool tests_received;

int main(void){

    //initialization
    gioInit();
    gioSetDirection(hetPORT1, 0xFFFFFFFF);
    
    MCP48FV_Init();

   // sciInit();
    timerInit();

    Result_t res = SUCCESS;
    //res = MCP48FV_Init(); 

    res = initUARTandModeHandler(&testBoardState);

    initializeTimers();

    UARTprintf(" Ready to initialize GUI \n\r");
    sciReceive(PC_UART, 3, (unsigned char *)&testMode);
    if (testMode == 'BMS'){
        testBoardState.testMode = BMS_MODE;
    } else {
        testBoardState.testMode = VCU_MODE;
    }
    UARTprintf("Mode detected: ");
    UARTSend(PC_UART, testMode);
    if (testMode == "BMS"){
        sciReceive(PC_UART, 141, (unsigned char *)&UARTBuffer); // change 100 to actual value

    }
    else if (testMode == "VCU") {
        sciReceive(PC_UART, 173, (unsigned char *)&UARTBuffer);
    }

    //* test code *//
    setPeripheralTestCases(&testBoardState, JSONHandler(UARTBuffer));

    while(true){

        startGlobalTimer(); //potentially needs to be ON for CAN communications...expects message every 50 ms?

        switch(testBoardState.testMode){

            case IDLE:

                continue;

            case BMS_MODE:

                res = bms_mode_process(&testBoardState);

                if(res != SUCCESS)
                    UARTprintf("Failed to Initialize BMS Test board\n\r");

                testBoardState.testMode = IDLE;

                //read bms shutdown pin; display results
                is_bms_slave_test_passed(testBoardState.peripheralStateArray[BMS_SLAVES]);

                break;

            case VCU_MODE:

                vcu_mode_process(&testBoardState);
                break;

        }//switch case

        while(!timers_complete()); //wait for tests to finish

        stopGlobalTimer(); //potentially needs to remain active for other peripherals, eg CAN communications...expects message every 50 ms?

        //send a single pass/result to PC (for CLI, uncomment VALID_DEBUG in common.h to display results)


        delayms(5000);

    }//superloop

}//main

static Result_t initUARTandModeHandler(TestBoardState_t *stateptr)
{
    sciInit(); // replace with UARTInit() to set baudrate
    sciSetBaudrate(PC_UART, 9600);
   // sciEnableNotification(PC_UART, SCI_RX_INT);

    UARTprintf("hello world\n\r");

    stateptr->peripheralStateArray[BMS_SLAVES] = 0;
    stateptr->peripheralStateArray[THERMISTOR_EXPANSION] = 0;
    stateptr->peripheralStateArray[BMS_COMMUNICATIONS] = 0;

    stateptr->testMode = VCU_MODE;

    return SUCCESS;
}

static json_t * JSONHandler(unsigned char *jsonstring){
    
    json_t const* json = json_create( jsonstring, mem, sizeof mem / sizeof *mem );
    // error checking the JSON
    if(!json){
        UARTprintf("Error creating JSON\n\r");
    }
    return json;
}

static void setPeripheralTestCases(TestBoardState_t *stateptr, json_t* json){

    //VCU Tests
    json_t * appsProperty = json_getProperty(json, "APPS"); 
    stateptr->peripheralStateArray[APPS] = (uint8_t) json_getInteger(appsProperty);
    json_t * bseProperty = json_getProperty(json, "BSE"); 
    stateptr->peripheralStateArray[BSE] = (uint8_t) json_getInteger(bseProperty);

    stateptr->peripheralStateArray[TSAL] = 0;

    stateptr->peripheralStateArray[IMD] = 0;

    stateptr->peripheralStateArray[LV] = 0;

    stateptr->peripheralStateArray[VCU_COMMUNICATIONS] = 0;


    //BMS Tests
    json_t * bmsProperty = json_getProperty(json, "BMS_SLAVES");
    stateptr->peripheralStateArray[BMS_SLAVES] = (uint8_t) json_getInteger(bmsProperty);

    stateptr->peripheralStateArray[THERMISTOR_EXPANSION] = 0;

    stateptr->peripheralStateArray[BMS_COMMUNICATIONS] = 0;

}


//pass timer ptr to each pointer peripheral. timer to periodically call test function you want
//inner state machines for each BMS peripheral and three outer state machines -Meeting with Amneet
static Result_t bms_mode_process(TestBoardState_t *stateptr)
{
    Result_t ret = FAIL;

    ret = bms_slaves_process(stateptr->peripheralStateArray[BMS_SLAVES]);

    if(ret != SUCCESS)
    {
        UARTprintf("BMS SLAVE FAIL %d\n\r", ret);
        return FAIL;
    }

    ret = thermistor_process(stateptr->peripheralStateArray[THERMISTOR_EXPANSION]);

    if(ret != SUCCESS)
    {
        UARTprintf("THERMISTOR FAIL %d\n\r", ret);
        return FAIL;
    }

    ret = communications_process(stateptr->peripheralStateArray[BMS_COMMUNICATIONS]);

    if(ret == FAIL)
    {
        UARTprintf("CAN COMMUNICATIONS FAIL %d\n\r", ret);
        return FAIL;
    }

    return SUCCESS;
}

static void vcu_mode_process(TestBoardState_t *stateptr)
{

    //eg Constant outputs don't need periodic timers should

    bse_process(stateptr->peripheralStateArray[BSE]);

    apps_process(stateptr->peripheralStateArray[APPS]);


}

void initializeTimers(){

    xTimerSet(
                "BSE", // name

                BSE, // peripheral

                bse_timer, // callback function

                0 // ID
             );

    xTimerSet(
                "APPS", // name

                APPS, // peripheral

                apps_timer, // callback function

                0 // ID
             );


    //add more peripheral timers here...


}


