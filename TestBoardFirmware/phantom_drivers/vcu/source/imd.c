/*
 * imd.c
 *
 *  Created on: Nov 10, 2020
 *      Author: Sumreen Rattan
 */
#include "imd.h"

// Global Variables
const int NORMAL_FREQUENCY = 10; //10hz
const float NORMAL_DUTY_CYCLE = 5.0; // 5% duty cycle
const float BAD_DUTY_CYCLE = 92.0; // 60-95% is bad - can create a sweep function for this
const int ZERO_FREQ = 0; //0hz
const float ZERO_DUTY_CYCLE = 0.0; // 0% duty cycle
const int MAX_DUTY_CYCLE = 100.0; // 100% duty cycle


enum operation
{
    IMD_NORMAL_OPERATION, // When Duty Cycle 5-10%, Freq is 10hz
    IMD_LOW_ISO_FAULT, // dataIMD.IMDState == Normal_25 or dataIMD.IMDState == Isolation_Failure, When Duty Cycle is 90-95%
    IMD_SHORT_CIRCUIT_FAULT, // IMDState == Short_Circuit, 0hz Frequency, 0% Duty Cycle
    IMD_DEVICE_ERR_FAULT, // IMDState == Device_Error, 40Hz, 47-53% Duty Cycle
    IMD_BAD_INFO_FAULT, // dataIMD.IMDState == Bad_Info, Frequency outside 10-50Hz
    IMD_UNDEF_ERR, // dataIMD.IMDState == Undefined_fault, Frequency within 10-50hz, Duty Cycle off (ex. 10hz, 40% Duty Cycle)
    IMD_GARBAGE_DATA_FAULT, // dataIMD.IMDState == Unknown, Duty Cycle is outside of range (below 5% or above 95%)

    //DEVICE_SWEEP, // 0-50hz Frequency, Expected corresponding duty cycle // how to test? - add later
    //ISOLATION_SWEEP, //10hz Frequency, 5-95% duty cycle // how to test? - add later
};



// Static function definitions
static void normal_operation();
static void low_isolation();
static void short_circuit();
static void device_error();
static void bad_info();
static void undefined_error();
static void garbage_data();
static float set_pin(int freq, float duty_cycle);


void imd_process(uint8_t state)
{
    switch(state)
    {
        case IMD_NORMAL_OPERATION:
            normal_operation();
            break;
        case IMD_LOW_ISO_FAULT:
            low_isolation();
            break;
        case IMD_SHORT_CIRCUIT_FAULT:
            short_circuit();
            break;
        case IMD_DEVICE_ERR_FAULT:
            device_error();
            break;
        case IMD_BAD_INFO_FAULT:
            bad_info();
            break;
        case IMD_UNDEF_ERR:
           undefined_error();
            break;
        case IMD_GARBAGE_DATA_FAULT:
           garbage_data();
            break;
        default:
            normal_operation();
    }
}

/*
* Fn: initalize_IMD
* Purpose: to initalize IMD pin
*/
void initalize_IMD()
{
    // initalize + configure pin
    hetInit();

}

/*
* Fn: set_pin
* Purpose: to be able to send any freq and duty cycle
* ex. 10hz Frequency, 5-95% duty cycle
*/
// TODO: Pretty sure we only care about period? Duty cycle will be constant probably 50%?
static float set_signal(float64 freq, uint32 duty_cycle)
{

    hetSIGNAL_t signal = {
      .duty   = duty_cycle,
      .period = 1 / freq
    };

    pwmSetSignal(IMD_PORT, IMD_PIN, signal);


    hetSIGNAL_t signal_out = {};
    hetSIGNAL_t* signal_out_ptr = &signal;
    pwmGetSignal(IMD_PORT, IMD_PIN, signal_out_ptr);

    return signal_out_ptr->period;
}


/*
* Fn: normal_imd_operation
* Purpose: Sends a square wave to the VCU that indicates normal IMD operation
* ex. 10hz frequency, 8% Duty Cycle,
* The Normal Range is when the Duty Cycle 5-10%
*/
static void normal_operation()
{

    // set duty cycle and freq
    set_signal(NORMAL_FREQUENCY, NORMAL_DUTY_CYCLE);

    // output values to pin
    pwmStart(IMD_PORT, IMD_PIN);
}

/*
* Fn: low_isolation
* Purpose: Sends a square wave to the VCU that indicates HV isolation failure
* Triggers a IMD_LOW_ISO_FAULT
* dataIMD.IMDState == Normal_25 or dataIMD.IMDState == Isolation_Failure, When Duty Cycle is 60-95%
* ex. 10hz Frequency, 60% Duty cycle
*/
static void low_isolation()
{
    // initalize + configure pin

    // set duty cycle and freq
    set_signal(NORMAL_FREQUENCY,BAD_DUTY_CYCLE); // can create a sweep function for this

    // output values to pin
    pwmStart(IMD_PORT, IMD_PIN);
}

/*
* Fn: short_circuit
* Purpose: Sends a square wave to the VCU that indicates there is a short circuit
* IMDState == Short_Circuit, 0hz Frequency, 0% Duty Cycle
* Send 0hz, 0% Duty cycle
*/
static void short_circuit()
{
    // initalize + configure pin

    // set duty cycle and freq
    set_signal(ZERO_FREQ,ZERO_DUTY_CYCLE);

    // output values to pin

}

/*
* Fn: device_error
* Purpose: Sends a square wave to the VCU that indicates the IMD device is not working
* Triggers a device error fault
* ex. IMDState == Device_Error, 40Hz, 47-53% Duty Cycle
// send 40hz, 50% Duty Cycle
*/
static void device_error()
{

    // set duty cycle and freq
    set_signal(40,48.0); // can create a sweep function for this

    // output values
    pwmStart(IMD_PORT, IMD_PIN);
}


/*
* Fn: bad_info
* Purpose: Sends a square wave to the VCU that is not consistent with expected values
* Triggers a IMD_BAD_INFO_FAULT
* ex. dataIMD.IMDState == Bad_Info, Frequency outside 10-50Hz
* send 60hz Frequency, 10% Duty Cycle,
*/
static void bad_info()
{
    // initalize + configure pin

    // set duty cycle and freq
    set_signal(60, NORMAL_DUTY_CYCLE); // can create a sweep or random function for the frequency

    // output values
    pwmStart(IMD_PORT, IMD_PIN);
}


/*
* Fn: undefined_error
* Purpose: Sends a square wave to the VCU that is not consistent with expected values
* dataIMD.IMDState == Undefined_fault, Frequency within 10-50hz, Duty Cycle is off
* send 10hz, 40% Duty Cycle
*/
static void undefined_error()
{
    // initalize + configure pin

    // set duty cycle and freq
    set_signal(NORMAL_FREQUENCY, 40.0); // can create a random function for the duty cycle

    // output values
    pwmStart(IMD_PORT, IMD_PIN);
}

/*
* Fn: garbage_data
* Purpose: Sends a square wave to the VCU that is not consistent with expected values
* dataIMD.IMDState == Unknown, Duty Cycle is outside of range (below 5% or above 95%)
* send 0hz, 100% duty cycle
*/
static void garbage_data()
{


    // set duty cycle and freq
    set_signal(0,MAX_DUTY_CYCLE); // can create a sweep function for this

    // output values
    pwmStart(IMD_PORT, IMD_PIN);
}



//TO CODE LATER
/*
* Fn: device_sweep
* Purpose: Sends a square wave to the VCU that goes through all possible Device States
* Sweeps through different frequencies
* ex. Send 0-50hz Frequency & the expected corresponding duty cycle for that frequency
*/
/*

static void device_sweep()
{
    // initalize + configure pin

    // initialize timer
    // use timer to cycle through different frequencies
    // output values to pin
    // print expected value to GUI
    // Short_Circuit, //0hz Freq, 0% Duty Cycle


    //Normal_Condition, // 10Hz
    //Undervoltage_Condition, // 20hz
    //Speed_Start_Measurement_Good, // related to startup, 30Hz, 0% Duty Cycle
    //Speed_Start_Measurement_Bad, // related to startup, 30hz, 95% Duty Cycle
    //Device_Error, // 40Hz, 47-53% Duty Cycle
    //Connection_Fault_Earth, // 50Hz, 47-53% Duty Cycle
    //Bad_Info, // Anything else
    //Undefined_Fault // If frequency is between 10-50Hz but Duty Cycle
    is out of range of expected values for that Frequency
}

*/

/*
* Fn: isolation_sweep
* Purpose: Sends a square wave to the VCU that goes through all possible Isolation States
* ex. 10hz Frequency, 5-95% duty cycle
*/
//static void isolation_sweep()
//{
    /* The isolation is at a percentage of of full isolation (ex. 100% is full, Normal_25 is 25% of the isolation)
    Normal, // When Duty Cycle 5-10%
    Normal_75, //Usually when Duty Cycle 10-30%
    Normal_50, // Usually when Duty Cycle 30-60%
    Normal_25, // Usually when Duty Cycle 60-90%
    Isolation_Failure, //When Duty Cycle is 90-95%
    Unknown // Duty Cycle is outside of range (5-95%)
    */
//}


/*
* Fn: serialSendData
* Purpose: prints the current Frequency and Duty Cycle
*/

/*
void serialSendData() {
     // adding this 0.5 and then typecasting to an int (truncating all decimals)
    // basically acts as rounding the float to the nearest integer
    freq_value = (unsigned int) (frequency + 0.5);
    duty_value = (unsigned int) (duty_cycle*100.0 + 0.5);

    NumberofCharsFreq = ltoa(freq_value, (char*) freq_data);
    NumberofCharsDuty = ltoa(duty_value, (char*) duty_data);

    sciSend(scilinREG, NumberofCharsFreq, freq_data);
    sciSend(scilinREG, 4, (unsigned char*)" Hz ");

    sciSend(scilinREG, NumberofCharsDuty, duty_data);
    sciSend(scilinREG, 4, (unsigned char*)" %\r\n");
}
*/
