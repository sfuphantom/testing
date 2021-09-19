# File to hold unit tests for the BMS using pytest

#   Written by:
#   Khail Alibhai & Courtenay Huffman
#   Date: May 28 2021

import copy
from typing import ByteString
import serial
import time
import json

from PySide2.QtCore import (QFile, QObject, Signal, Slot, Qt)

#Example of Tests to be chosen by UI
# selectedTest_example = [{'Test Name': 'BMS_SLAVES', 
# 'Test Case': 'y', 
# 'Repeat': None, 
# 'Test Index': None, 'Enum': 1}]

#{'Test Name': 'thermistor_exp', 'Test Case': 'v', 'Repeat': None, 'Test Index': None, 'Enum': 0}]

# Dictionary object of BMS in normal state
normal_bms = {
    "Mode": "BMS",
	"COMMUNICATIONS": 0,
	"THERMISTOR_EXPANSION": 0,
	"BMS_SLAVES": 0,
	"repeat": 1
}

# Build Test Information to be Sent to Launchpad
def build_json(info):

    selectedTests = info[0]
    portNumber = info[1]
    selectedJson = copy.deepcopy(normal_bms)

    counter = 0
    for x in selectedTests:
        selectedJson.update({selectedTests[counter].get('Test Name'): selectedTests[counter].get('enum')})
        counter += 1
    
    jsonStr = json.dumps(selectedJson, indent="\t")
    # used for debugging purposes
    length = len(jsonStr)
    bytelength = len(bytes(jsonStr, encoding = 'utf8'))
    # print(jsonStr)

    launchpad= serial.Serial(port = portNumber, baudrate = 9600, bytesize = serial.EIGHTBITS, stopbits = serial.STOPBITS_TWO, timeout = 10)
    launchpad.write(bytes("BMS", encoding='utf8'))
    time.sleep(2)
    launchpad.write(bytes(jsonStr, encoding='utf8'))
    result = launchpad.read(size=50)
    launchpad.close()

    return result


# Test Function for PyTest Use, Passed: Test Results match Normal BMS State, Failed: Test Results do not match Normal BMS State
def test_bms_json():
    assert build_json() == True