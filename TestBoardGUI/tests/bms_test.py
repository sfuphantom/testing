# File to hold unit tests for the BMS using pytest

#   Written by:
#   Khail Alibhai & Courtenay Huffman
#   Date: May 28 2021

import copy
from typing import ByteString
import serial
import time
import json


# Constants to be changed based on Launchpad Settings
PORT = "COM8"
BAUDRATE = 9600
TIMEOUT = 0.1

#Example of Tests to be chosen by UI
selectedTest_example = [{'Test Name': 'BMS_SLAVES', 
'Test Case': 'y', 
'Repeat': None, 
'Test Index': None, 'Enum': 1}]

#{'Test Name': 'thermistor_exp', 'Test Case': 'v', 'Repeat': None, 'Test Index': None, 'Enum': 0}]

# Dictionary object of BMS in normal state
normal_bms = {
    "Mode": "BMS",
	"BMS/VCU CAN": 0,
	"Thermistor Expansion": 0,
	"BMS_SLAVES": 0,
	"repeat": 1
}

# Build Test Information to be Sent to Launchpad
def build_json():
    selectedJson = copy.deepcopy(normal_bms)

    counter = 0
    for x in selectedTest_example:
        selectedJson.update({selectedTest_example[counter].get('Test Name'): selectedTest_example[counter].get('Enum')})
        counter += 1
    
    jsonStr = json.dumps(selectedJson, indent="\t")

    return jsonStr

# Encode and Send Test Information to Launchpad, Receive Response
def send_and_receive(selectedJson, serialPort):

    # print(bytes(selectedJson, 'utf-8'))

    # Encode Test Information and Send it to Launchpad
    print(len(bytes(selectedJson, 'utf-8')))
    serialPort.write(bytes(selectedJson, 'utf-8'))

    # Wait 50 milliseconds for a response
    time.sleep(.05)


    # Read the most recent line of the Serial, return it as bytes
    receivedData = serialPort.read_until(expected='}')
    # receivedData = serialPort.read_all()

    return receivedData

# Receive Response from Launchpad containing Test Results
def main():
    
    # Initalize Serial
    serialPort = serial.Serial(port = PORT, baudrate = BAUDRATE, timeout = TIMEOUT, stopbits = serial.STOPBITS_TWO)

    # Prepare Test Infomation
    selectedJson = build_json()

    # Prepare Launchpad to Receive BMS test Information
    serialPort.write(bytes('BMS', 'utf-8'))
    time.sleep(1)
    print(serialPort.read_until(expected='}'))
    # assert False

    # Repeatedly Send Test Info to Launchpad until Test Results are Received
    data = ''
    while data == '':
        data = send_and_receive(selectedJson, serialPort)
        #data = send_and_receive(json.dumps(normal_bms, indent="\t"), serialPort)
    
    # Close Serial
    serialPort.close()

    return data

# Test Function for PyTest Use, Passed: Test Results match Normal BMS State, Failed: Test Results do not match Normal BMS State
def test_bms_json():

    # Compare Test Results to Normal BMS State
    # assert bytes(json.dumps(normal_bms, indent="\t"), 'utf-8') == main()
    temp_byte = bytes(json.dumps(normal_bms, indent="\t"), 'utf-8')
    temp_main = main()
    # with open("tempB.bin", "wb") as file:
    #     file.write(temp_byte)
    # with open("tempM.bin", "wb") as file:
    #     file.write(temp_main)
    print(temp_byte)
    print(temp_main)
    assert temp_byte == temp_main
    #assert bytes(json.dumps(normal_bms, indent="\t"), 'utf-8') == main()