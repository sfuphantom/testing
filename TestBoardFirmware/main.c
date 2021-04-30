

/**
 * main.c
 */
#include "tiny-json.h"
#include "main.h"
#include "Phantom_sci.h"
#include "FreeRTOS.h"
#include "FreeRTOSConfig.h"
#include "os_task.h"
#include "os_timer.h"
#include "hwConfig.h"

#include "common.h"


#define NUM_TIMERS 1

#define SWEEP_PERIOD 500

//Drivers
#include "bse.h"

#include "MCP48FV_DAC_SPI.h"

static unsigned char UARTBuffer[100];
static unsigned char UARTchar;

// Static Function Declaration
static Result_t initUARTandModeHandler(TestBoardState_t *stateptr);
static Result_t bms_mode_process(TestBoardState_t *stateptr, TimerHandle_t *timerptr);
static void vcu_mode_process(TestBoardState_t *stateptr,TimerHandle_t *timerptr);
static void setPeripheralTestCases(TestBoardState_t* stateptr);
static void timerInit();
static void UARTTest();
static void JSONHandler();

// Static global variables
static TestBoardState_t testBoardState = { IDLE, {0,0,0,0,0,0,0,0,0,0,} };
static TimerHandle_t xTimers[NUM_TIMERS];

static void timerInit(){

    xTimers[BSE_SWEEP_TIMER] = xTimerCreate(

                                "BSE_Sweep_Timer",

                                pdMS_TO_TICKS(SWEEP_PERIOD),

                                pdTRUE,

                                (void* ) 0,

                                bse_sweep_timer

   ); 



}

int main(void)
{

    //initialization

    Result_t res = SUCCESS;
    res = MCP48FV_Init(); 

    //timerInit();

    res = initUARTandModeHandler(&testBoardState);

    // UART test function
    UARTTest();
UARTprintf("test complete");
    // TODO: Interrupt based wait to get test mode from PC
    // while(!initGUI) need a way to know where start and end of message is (startbyte..,.,..endbyte)
    // receive UART from GUI
    // need length - what ways could difference be handled?

    //parse JSON and set states
    // tiny-json stuff
    // check formatting of string sent by GUI - may need to adjust string for compatibility
    JSONHandler();

    //* test code *//
    setPeripheralTestCases(&testBoardState);



    //start timer
//    xTimerStart(xTimers[BSE_SWEEP_TIMER],pdMS_TO_TICKS(500));

//    vTaskStartScheduler();
    //determine the expected state of VCU/BMS

    while(1)
    {
        switch(testBoardState.testMode)
        {
            case IDLE:
            {
                break;
            }
            case BMS_MODE:
            {
//                res = bms_mode_process(&testBoardState);

                if(res != SUCCESS)
                {
                    UARTprintf("Failed to Initialize BMS Test board\n\r");
                    break;
                }

                int i;

                testBoardState.testMode = IDLE;
                break;
            }
            case VCU_MODE:
            {
                vcu_mode_process(&testBoardState, &xTimers);
            }
        }

        delayms(5000);


        //validate test cases (through timer and send to PC)
        //send a single pass/result to PC

    }

    //process functions for constant output vs variable output
}

static Result_t initUARTandModeHandler(TestBoardState_t *stateptr)
{
    sciInit(); // replace with UARTInit() to set baudrate
    sciSetBaudrate(PC_UART, 9600);
    sciEnableNotification(PC_UART, SCI_RX_INT);

    UARTprintf("hello world\n\r");

    stateptr->peripheralStateArray[BMS_SLAVES] = 0;
    stateptr->peripheralStateArray[THERMISTOR_EXPANSION] = 0;
    stateptr->peripheralStateArray[BMS_COMMUNICATIONS] = 0;

    stateptr->testMode = BMS_MODE;

    return SUCCESS;
}

static void UARTTest(){
    UARTprintf("UART Test Begin:\n\r");
    char n[] = {'a', 'r', 'r', 'a', 'y', 'd', 'a', 't', 'a'};
    UARTSend(PC_UART, n);
    UARTprintf("\n\r");
    UARTprintf("Enter character \n\r");
    //sciReceive(PC_UART, 1, (unsigned char *)&UARTBuffer);
    UARTprintf("This is your character:\n\r");
    UARTSend(PC_UART, UARTBuffer);
    UARTprintf("character received\n\r");
    return;
}

static void JSONHandler(){
    // json_t array[]
    // json_t = json_create()
    // error checking the JSON
    return;
}

static void setPeripheralTestCases(TestBoardState_t *stateptr){

    //TestBoard Mode
    stateptr->testMode = VCU_MODE;


    //VCU Tests
    stateptr->peripheralStateArray[APPS] = 0;

    stateptr->peripheralStateArray[BSE] = BSE_OPEN_CIRCUIT;

    stateptr->peripheralStateArray[TSAL] = 0;

    stateptr->peripheralStateArray[IMD] = 0;

    stateptr->peripheralStateArray[LV] = 0;

    stateptr->peripheralStateArray[VCU_COMMUNICATIONS] = 0;


    //BMS Tests
    stateptr->peripheralStateArray[BMS_SLAVES] = 0;

    stateptr->peripheralStateArray[THERMISTOR_EXPANSION] = 0;

    stateptr->peripheralStateArray[BMS_COMMUNICATIONS] = 0;

    return SUCCESS;

}


//pass timer ptr to each pointer peripheral. timer to periodically call test function you want
//inner state machines for each BMS peripheral and three outer state machines -Meeting with Amneet
static Result_t bms_mode_process(TestBoardState_t *stateptr, TimerHandle_t *timerptr)
{
//    Result_t ret = FAIL;
//
//    ret = bms_slaves_process(stateptr->peripheralStateArray[BMS_SLAVES]);
//
//    if(ret != SUCCESS)
//    {
//        UARTprintf("BMS SLAVE FAIL %d\n\r", ret);
//        return FAIL;
//    }
//
//    ret = thermistor_process(stateptr->peripheralStateArray[THERMISTOR_EXPANSION]);
//
//    if(ret != SUCCESS)
//    {
//        UARTprintf("THERMISTOR FAIL %d\n\r", ret);
//        return FAIL;
//    }
//
//    ret = communications_process(stateptr->peripheralStateArray[BMS_COMMUNICATIONS]);
//
//    if(ret == FAIL)
//    {
//        UARTprintf("CAN COMMUNICATIONS FAIL %d\n\r", ret);
//        return FAIL;
//    }
//
    return SUCCESS;
}

static void vcu_mode_process(TestBoardState_t *stateptr,TimerHandle_t *timerptr)
{

    //eg Constant outputs don't need periodic timers should

    bse_process(stateptr->peripheralStateArray[BSE],timerptr);


}

//void set_testboard_state(uint8_t *state_array, TestBoardModes_t mode)
//{
//    memcpy(&testBoardState.peripheralStateArray[0], state_array, sizeof(*state_array));
//    testBoardState.testMode = mode;
//}

//change this function as necessary
void sciNotification(sciBASE_t *sci, unsigned flags){
    //echoes character received
    UARTprintf("sciNotification \n\r");
    sciSend(PC_UART, 1, (unsigned char *)&UARTchar);
    // waits for new character
    sciReceive(PC_UART, 1, (unsigned char *)&UARTchar);
}

//not used but must be present for SCI notifications to work
void esmGroup1Notification(int bit){
    return;
}

void esmGroup2Notification(int bit){
    return;
}
