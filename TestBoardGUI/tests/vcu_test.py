# File to hold unit tests for the VCU using pytest

#   Written by:
#   Courtenay Huffman
#   Date: March 4 2021

# to run tests, call pytest.main() to run as if called on the commandline.
# can pass pytest.main() arguments - used to pass selected tests?
# or can use sys.path to import
# implement tests as an integration test or test fully encompassing all vcu states to create a json?

import pytest
import json
import copy
import serial

# example list of what might be received from front end
selectedTest_example = [{'Test Name': 'APPS', 'Test Case': 'Test 2: 10% Difference', 'Repeat': None, 'Test Index': None}, {'Test Name': 'BSE', 'Test Case': 'Test 3: Open/Short Circuit', 'Repeat': None, 'Test Index': None}]

# dictionary object of VCU in default state (NORMAL enums, 1 repetition for all key-value pairs) 
normal_vcu = {
    "Mode": "VCU",
    "APPS": "NORMAL",
	"BSE": "NORMAL",
	"IMD": "NORMAL",
	"HV_VOLTAGE_SENSOR": "NORMAL",
	"HV_CURRENT_SENSOR": "NORMAL",
	"TSAL": "NORMAL",
	"LV_POWER_SENSOR": "NORMAL",
	"COMMUNICATIONS": "NORMAL",
	"repeat": 1

}

def build_json():
    selectedJson = copy.deepcopy(normal_vcu)

    for x in selectedTest_example
        selectedJson.update({selectedTest_example[x].get('Test Name'), "TEST_ENUM"})
        
    # send UART
    # serialPort = serial.Serial(port = 0, baudrate = 0, bytesize = 0, timeout = 0, stopbits = serial.STOPBITS_ONE)

    # receive UART
    # interpret response from test board
    # return result

    return selectedJson

#beginning of tests
def test_vcu_json():
    assert normal_vcu != build_json()

def test_appsval():
    assert "NORMAL" == normal_vcu.get("apps")

def test_apps_implausibility():
    normal_vcu.update({"apps": "IMPLAUSIBILITY"})
    assert "IMPLAUSIBILITY" == normal_vcu.get("apps")
