

/**
 * main.c
 */
#include "tiny-json.h"
#include "main.h"

// Static Function Declaration
static Result_t initUARTandModeHandler(TestBoardState_t *stateptr);
static void bms_mode_process(TestBoardState_t *stateptr);
static void vcu_mode_process(TestBoardState_t *stateptr);

int main(void)
{
    TestBoardState_t testBoardState = { IDLE, {0} };
    Result_t res = SUCCESS;

    res = initUARTandModeHandler(&testBoardState);

    while(1)
    {
        switch(testBoardState.testMode)
        {
            case IDLE:
                break;
            case BMS_MODE:
                bms_mode_process(&testBoardState);
                break;
            case VCU_MODE:
                vcu_mode_process(&testBoardState);
        }
    }
}

static Result_t initUARTandModeHandler(TestBoardState_t *stateptr)
{
    return SUCCESS;
}

static void bms_mode_process(TestBoardState_t *stateptr)
{
    bms_slaves_process(stateptr->peripheralStateArray[BMS_SLAVES]);
    thermistor_process(stateptr->peripheralStateArray[THERMISTOR_EXPANSION]);
    communications_process(stateptr->peripheralStateArray[BMS_COMMUNICATIONS]);
}

static void vcu_mode_process(TestBoardState_t *stateptr)
{

}
