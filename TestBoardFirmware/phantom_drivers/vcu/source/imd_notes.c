// ENUMS FOR IMD MESSAGE MAPPING

// IMD State Enum
// message names are taken from IMD Datasheet
typedef enum{
    Short_Circuit, //*
    Normal_Condition, //*
    Undervoltage_Condition, //default is 0 volts in the device datasheet unless programmed otherwise
    Speed_Start_Measurement_Good, // related to start-up
    Speed_Start_Measurement_Bad, // related to start-up
    Device_Error, //*
    Connection_Fault_Earth, //*
    Bad_Info, //* 
    Undefined_Fault //*
}IMDStateEnum;

// Isolation State Enum
typedef enum{
    Normal, // When Duty Cycle 5-10% *
    Normal_75, // Usually when Duty Cycle 10-30%
    Normal_50, // Usually when Duty Cycle 30-60%
    Normal_25, // Usually when Duty Cycle 60-90%
    Isolation_Failure, //When Duty Cycle is 90-95% *
    Unknown // Duty Cycle is outside of range (5-95%) *
}IsolationStateEnum;


// IMDData Struct which contains the status of the IMD and Isolation
typedef struct{
    IMDStateEnum IMDState;
    IsolationStateEnum IsolationState;
}IMDData_t;

