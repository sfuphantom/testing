# File to hold unit tests for the BMS using pytest

#   Written by:
#   Khail Alibhai
#   Date: March 28 2021

import copy
import serial
import time

# Constants to be changed based on Launchpad Settings
PORT = "COM3"
BAUDRATE = 115200
TIMEOUT = 0.1

#Example of Tests to be chosen by UI
selectedTest_example = [{'Test Name': 'x', 'Test Case': 'y', 'Repeat': None, 'Test Index': None}, {'Test Name': 'u', 'Test Case': 'v', 'Repeat': None, 'Test Index': None}]

# Dictionary object of BMS in normal state
normal_bms = {
    "Mode": "BMS",
	"bms_slave": "NORMAL",
	"thermistor_exp": "NORMAL",
	"communications": "NORMAL",
	"repeat": 1
}

# Initalize Serial
serialPort = serial.Serial(port = PORT, baudrate = BAUDRATE, timeout = TIMEOUT)

# Build Test Information to be Sent to Launchpad
def build_json():
    selectedJson = copy.deepcopy(normal_bms)

    for x in range(len(selectedTest_example)):
        selectedJson.update({selectedTest_example[x].get('Test Name'): "TEST_ENUM"})
    
    return selectedJson

# Encode and Send Test Information to Launchpad, Receive Response
def send_and_receive(selectedJson):

    # Encode Test Information and Send it to Launchpad
    # (Arduino is Setup to Use '\n' to know when the message is done, that's why it is added to the end of the string below)
    serialPort.write(bytes(str(selectedJson)+'\n', 'utf-8'))

    # Wait 50 milliseconds for a response
    time.sleep(.05)

    # Read the most recent line of the Serial, return it as bytes
    receivedLine = serialPort.readline()
    return receivedLine

# Receive Response from Launchpad containing Test Results
def decode_results():

    # Prepare Test Infomation
    selectedJson = build_json()

    # Prepare Launchpad to Receive BMS test Information
    serialPort.write(bytes('bms', 'utf-8'))
    time.sleep(1)
    # Repeatedly Send Test Info to Launchpad until Test Results are Received
    data = b''
    while data == b'':
        data = send_and_receive(selectedJson)
        #data = send_and_receive(normal_bms)
    
    # Decode Test Results and Return Test Results as String
    data_str = data.decode('utf-8')[:-1]
    return data_str

# Test Function for PyTest Use, Passed: Test Results match Normal BMS State, Failed: Test Results do not match Normal BMS State
def test_bms_json():

    # Compare Test Results to Normal BMS State
    assert str(normal_bms) == decode_results()





