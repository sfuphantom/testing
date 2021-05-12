#File to hold unit tests for the BMS using pytest

#TO DO:
# pip install pytest 
# update README.md with above

#include pytest in file: import pytest
# to run tests, call pytest.main() to run as if called on the commandline.
# can pass pytest.main() arguments - used to pass selected tests 

#implement tests as an integration test or test fully encompassing all vcu states to create a json

import json
import pytest
import copy
import serial

selectedTest_example = [{'Test Name': 'x', 'Test Case': 'y', 'Repeat': None, 'Test Index': None}, {'Test Name': 'u', 'Test Case': 'v', 'Repeat': None, 'Test Index': None}]
# dictionary object of BMS in normal state
normal_bms = {

    "Mode": "BMS",
	"bms_slave": "NORMAL",
	"thermistor_exp": "NORMAL",
	"communications": "NORMAL",
	"repeat": 1

}



def build_json():
    selectedJson = copy.deepcopy(normal_bms)

    for x in range(len(selectedTest_example)):
        selectedJson.update({selectedTest_example[x].get('Test Name'): "TEST_ENUM"})
    
    return selectedJson

def send_json():
    
    selectedJson = build_json()

    # send UART
    # configure Serial
    serialPort = serial.Serial(port = "COMX", baudrate = 9600, bytesize = 8, timeout = 0, stopbits = serial.STOPBITS_ONE)
    # send test to serial
    serialPort.write("bms")
    serialPort.write(json.dumps(selectedJson))

    # receive UART
    #TO DO: interperet the correct line from serial
    receivedTest = serialPort.readline()[:-2] #trims input to get rid of new-line chars
    testResults = json.loads(receivedTest)
    
    return testResults

#testing functions
def test_bms_json():
    assert normal_bms != build_json()






