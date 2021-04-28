

/**
 * main.c
 */
#include "tiny-json.h"
#include "main.h"
#include "Phantom_sci.h"
//#include "FreeRTOS.h"
//#include "FreeRTOSConfig.h"
//#include "os_task.h"
//#include "os_timer.h"

#include "common.h"

//Drivers
#include "bse.h"
#include "apps.h"

#include "MCP48FV_DAC_SPI.h"

#include "timer.h"

#define TIMER_PERIOD 1000

// Static Function Declaration
static Result_t initUARTandModeHandler(TestBoardState_t *stateptr);
static Result_t bms_mode_process(TestBoardState_t *stateptr);
static void vcu_mode_process(TestBoardState_t *stateptr);
static void setPeripheralTestCases(TestBoardState_t* stateptr);
static void createTimers();

static void test_complete_timer(Timer, int);

// Static global variables
static TestBoardState_t testBoardState = { IDLE, {0,0,0,0,0,0,0,0,0,0,} };
static bool isTestComplete = false;

static void createTimers();

int main(void)
    {

    //initialization

    MCP48FV_Init();


    sciInit();
    timerInit();

    createTimers();


    Result_t res = SUCCESS;

    res = initUARTandModeHandler(&testBoardState);

    // TODO: Interrupt based wait to get test mode from PC
//    while(!initGUI) need a way to know where start and end of message is (startbyte..,.,..endbyte)

    //parse JSON and set states

    //* test code *//
    setPeripheralTestCases(&testBoardState);

    startAllTimers();

    startGlobalTimer();

    isTestComplete = false;

    //determine the expected state of VCU/BMS

    while(1)
    {

        startTimer(TEST_COMPLETE_TIMER);

        isTestComplete = false;

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


        while(!isTestComplete);

        stopTimer(TEST_COMPLETE_TIMER);

        //validate test cases (through timer and send to PC)
        //send a single pass/result to PC

        delayms(5000);

    }

    //process functions for constant output vs variable output
}

static Result_t initUARTandModeHandler(TestBoardState_t *stateptr)
{
    sciInit();

    UARTprintf("hello world\n\r");

    stateptr->peripheralStateArray[BMS_SLAVES] = 0;
    stateptr->peripheralStateArray[THERMISTOR_EXPANSION] = 0;
    stateptr->peripheralStateArray[BMS_COMMUNICATIONS] = 0;

    stateptr->testMode = BMS_MODE;

    return SUCCESS;
}

static void setPeripheralTestCases(TestBoardState_t *stateptr){

    //TestBoard Mode
    stateptr->testMode = VCU_MODE;


    //VCU Tests
    stateptr->peripheralStateArray[APPS] = APPS_BSE_ACTIVATED;

    stateptr->peripheralStateArray[BSE] = BSE_SWEEP;

    stateptr->peripheralStateArray[TSAL] = 0;

    stateptr->peripheralStateArray[IMD] = 0;

    stateptr->peripheralStateArray[LV] = 0;

    stateptr->peripheralStateArray[VCU_COMMUNICATIONS] = 0;


    //BMS Tests
    stateptr->peripheralStateArray[BMS_SLAVES] = 0;

    stateptr->peripheralStateArray[THERMISTOR_EXPANSION] = 0;

    stateptr->peripheralStateArray[BMS_COMMUNICATIONS] = 0;

}


//pass timer ptr to each pointer peripheral. timer to periodically call test function you want
//inner state machines for each BMS peripheral and three outer state machines -Meeting with Amneet
static Result_t bms_mode_process(TestBoardState_t *stateptr)
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

    bse_process(stateptr->peripheralStateArray[BSE]);

    apps_process(stateptr->peripheralStateArray[APPS]);


}

static void test_complete_timer(Timer timer, int ID){

    #ifdef TIMER_DEBUG
    UARTprintf("Tests Complete!\r\n\n");
    #endif

    isTestComplete = true;

    stopAllTimers();

}

void createTimers(){


    xTimerSet(
                "Test_Complete", // name

                TEST_COMPLETE_TIMER, // index

                test_complete_timer, // callback function

                10000, // period in ms

                0 // ID
             );

    xTimerSet(
                "BSE_Sweep_Timer", // name

                BSE_SWEEP_TIMER, // index

                bse_sweep_timer, // callback function

                TIMER_PERIOD, // period in ms

                0 // ID
             );

    xTimerSet(
                "APPS_Short_Timer", // name

                APPS_SHORT_TIMER, // index

                apps_short_timer, // callback function

                TIMER_PERIOD, // period in ms

                0 // ID
             );

    xTimerSet(
                "APPS_Open_Timer", // name

                APPS_OPEN_TIMER, // index

                apps_open_timer, // callback function

                TIMER_PERIOD, // period in ms

                0 // ID
             );

    xTimerSet(
               "APPS_BSE_Activated_Timer", // name

               APPS_BSE_ACTIVATED_TIMER, // index

               apps_bse_activated_timer, // callback function

               TIMER_PERIOD, // period in ms

               0 // ID
            );

    xTimerSet(
               "APPS_Sweep_Timer", // name

               APPS_SWEEP_TIMER, // index

               apps_sweep_timer, // callback function

               TIMER_PERIOD, // period in ms

               0 // ID
            );

    //add more timers here...


}


//void set_testboard_state(uint8_t *state_array, TestBoardModes_t mode)
//{
//    memcpy(&testBoardState.peripheralStateArray[0], state_array, sizeof(*state_array));
//    testBoardState.testMode = mode;
//}
