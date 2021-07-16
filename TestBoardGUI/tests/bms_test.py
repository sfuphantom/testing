# File to hold unit tests for the BMS using pytest

#   Written by:
#   Khail Alibhai & Courtenay Huffman
#   Date: May 28 2021

import copy
import serial
import time
import json

from PySide2.QtCore import (QFile, QObject, Signal, Slot, Qt)


# Constants to be changed based on Launchpad Settings
# PORT = "COM3"
BAUDRATE = 9600
TIMEOUT = 0.1

#Example of Tests to be chosen by UI
selectedTest_example = [{'Test Name': 'communications', 'Test Case': 'y', 'Repeat': None, 'Test Index': None, 'Enum': 0}, {'Test Name': 'thermistor_exp', 'Test Case': 'v', 'Repeat': None, 'Test Index': None, 'Enum': 0}]

# Dictionary object of BMS in normal state
normal_bms = {
    "Mode": "BMS",
	"BMS/VCU CAN": 0,
	"Thermistor Expansion": 0,
	"BMS_SLAVES": 0,
	"repeat": 1
}

# Build Test Information to be Sent to Launchpad
def build_json(selectedTest):
    
    selectedJson = copy.deepcopy(normal_bms)

    counter = 0
    for x in selectedTest:
        selectedJson.update({selectedTest_example[counter].get('Test Name'): selectedTest_example[counter].get('Enum')})
        counter += 1
    
    jsonStr = json.dumps(selectedJson, indent="\t")

    return jsonStr

# Encode and Send Test Information to Launchpad, Receive Response
def send_and_receive(selectedJson, serialPort):

    # Encode Test Information and Send it to Launchpad
    serialPort.write(bytes(selectedJson, 'utf-8'))

    # Wait 50 milliseconds for a response
    time.sleep(.05)

    # Read the most recent line of the Serial, return it as bytes
    receivedData = serialPort.read_until(expected='}')
    
    return receivedData

# Receive Response from Launchpad containing Test Results
@Slot(list)
def main(info):
    selectedTests = info[0]
    portNumber = info[1]
    
    # Initalize Serial
    serialPort = serial.Serial(port = portNumber, baudrate = BAUDRATE, timeout = TIMEOUT, stopbits = serial.STOPBITS_TWO)

    # Prepare Test Infomation
    selectedJson = build_json(selectedTests)

    # Prepare Launchpad to Receive BMS test Information
    serialPort.write(bytes('BMS', 'utf-8'))
    time.sleep(1)

    # Repeatedly Send Test Info to Launchpad until Test Results are Received
    data = b''
    while data == b'':
        data = send_and_receive(selectedJson, serialPort)
        #data = send_and_receive(json.dumps(normal_bms, indent="\t"), serialPort)
    
    # Close Serial
    serialPort.close()

    return data

# Test Function for PyTest Use, Passed: Test Results match Normal BMS State, Failed: Test Results do not match Normal BMS State
def test_bms_json():

    # Compare Test Results to Normal BMS State
    assert bytes(json.dumps(normal_bms, indent="\t"), 'utf-8') == main()

