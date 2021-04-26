

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

// Static Function Declaration
static Result_t initUARTandModeHandler(TestBoardState_t *stateptr);
static Result_t bms_mode_process(TestBoardState_t *stateptr, TimerHandle_t *timerptr);
static void vcu_mode_process(TestBoardState_t *stateptr);
static void UARTTest();
static void JSONHandler();

// Static global variables
static TestBoardState_t testBoardState = { IDLE, {0} };

unsigned char UARTBuffer[100];

int main(void)
{
    Result_t res = SUCCESS;

    res = initUARTandModeHandler(&testBoardState);

    // UART test function
    UARTTest();

    // TODO: Interrupt based wait to get test mode from PC
    // while(!initGUI) need a way to know where start and end of message is (startbyte..,.,..endbyte)
    // receive UART from GUI
    // need length - what ways could difference be handled?
    sciReceive(PC_UART, 1,  (unsigned char *)&UARTBuffer); //fix length params for GUI data

    //parse JSON and set states
    // tiny-json stuff
    // check formatting of string sent by GUI - may need to adjust string for compatibility
    JSONHandler();

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
                vcu_mode_process(&testBoardState);
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
    sciSetBaudrate(PC_UART, 10000);
    sciEnableNotification(PC_UART, SCI_RX_INT);

    UARTprintf("hello world\n\r");

    stateptr->peripheralStateArray[BMS_SLAVES] = 0;
    stateptr->peripheralStateArray[THERMISTOR_EXPANSION] = 0;
    stateptr->peripheralStateArray[BMS_COMMUNICATIONS] = 0;

    stateptr->testMode = BMS_MODE;

    return SUCCESS;
}

static void UARTTest(){
    UARTprintf("Enter character\n\r");
    sciReceive(PC_UART, 1, (unsigned char *)&UARTBuffer);
    UARTprintf("This is your character:\n\r");
    UARTSend(PC_UART, UARTBuffer);
    return;
}

static void JSONHandler(){
    // json_t array[]
    // json_t = json_create()
    // error checking the JSON
    return;
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

static void vcu_mode_process(TestBoardState_t *stateptr)
{

    //eg Constant outputs don't need periodic timers should

}

void set_testboard_state(uint8_t *state_array, TestBoardModes_t mode)
{
    memcpy(&testBoardState.peripheralStateArray[0], state_array, sizeof(*state_array));
    testBoardState.testMode = mode;
}
