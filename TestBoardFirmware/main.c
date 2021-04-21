

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

#include "common.h"


#define NUM_TIMERS 1;

#define SWEEP_PERIOD 1000;

//Drivers
#include "BSE.h"



// Static Function Declaration
static Result_t initUARTandModeHandler(TestBoardState_t *stateptr);
static Result_t bms_mode_process(TestBoardState_t *stateptr, TimerHandle_t *timerptr);
static void vcu_mode_process(TestBoardState_t *stateptr);
static void setPeripheralTestCases(TestBoardState_t* stateptr);
static void timerInit();


// Static global variables
static TestBoardState_t testBoardState = { IDLE, {0,0,0,0,0,0,0,0,0,0,} };
static xTimers[NUM_TIMERS];

enum{

    BSE_SWEEP_TIMER


};


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
    Result_t res = SUCCESS;

    res = initUARTandModeHandler(&testBoardState);

    // TODO: Interrupt based wait to get test mode from PC
//    while(!initGUI) need a way to know where start and end of message is (startbyte..,.,..endbyte)

    //parse JSON and set states

    //* test code *//
    setPeripheralTestCases(&testBoardState);



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
    stateptr->peripheralStateArray[APPS] = 0;

    stateptr->peripheralStateArray[BSE] = 0;

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

static void vcu_mode_process(TestBoardState_t *stateptr)
{

    //eg Constant outputs don't need periodic timers should

    bse_process(stateptr->peripheralStateArray[BSE]);


}

//void set_testboard_state(uint8_t *state_array, TestBoardModes_t mode)
//{
//    memcpy(&testBoardState.peripheralStateArray[0], state_array, sizeof(*state_array));
//    testBoardState.testMode = mode;
//}
