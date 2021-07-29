
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
import time

from PySide2.QtCore import (QFile, QObject, Signal, Slot, Qt)


# example list of what might be received from front end
selectedTest_example = [{'Test Name': 'APPS', 'Test Case': 'Test 2: 10% Difference', 'Repeat': None, 'Test Index': None, 'Enum': 2}, {'Test Name': 'BSE', 'Test Case': 'Test 3: Open/Short Circuit', 'Repeat': None, 'Test Index': None, 'Enum': 1}]

# dictionary object of VCU in default state (NORMAL enums, 1 repetition for all key-value pairs) 
normal_vcu = {
    "Mode": "VCU",
    "APPS": 0,
	"BSE": 0,
	"IMD": 0,
	"HV_VOLTAGE_SENSOR": 0,
	"HV_CURRENT_SENSOR": 0,
	"TSAL": 0,
	"LV_POWER_SENSOR": 0,
	"COMMUNICATIONS": 0,
	"repeat": 1

}

# @Slot(list)
def build_json(info):

    selectedTests = info[0]
    portNumber = info[1]

    selectedJson = copy.deepcopy(normal_vcu)
    counter = 0
    print()
    for x in selectedTests:
        # print(selectedTests[counter])
        selectedJson.update({selectedTests[counter].get('Test Name'): int(selectedTests[counter].get('enum'))})
        counter += 1
        
    jsonStr = json.dumps(selectedJson, indent="\t")
    length = len(jsonStr)
    # print(jsonStr)

    launchpad= serial.Serial(port = portNumber, baudrate = 9600, stopbits = serial.STOPBITS_TWO)
    launchpad.write(bytes("VCU", encoding='utf8'))
    time.sleep(8)
    launchpad.write(bytes(jsonStr, encoding='utf8'))
    launchpad.read() # this will read 1 byte. To read multiple, use read_until()
    result = launchpad.read()
    launchpad.close()

    return result

#beginning of tests
def test_vcu_json():
    assert build_json() == True

# test_vcu_json()
