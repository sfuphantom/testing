import argparse
# These imports come from vcu_test.py to use to generate JSON file
import json
import copy
import serial
import time
from PySide2.QtCore import (QFile, QObject, Signal, Slot, Qt)
import sys

# format is {testName : testNumber} where testName is 0 = HVCS, 1 = HVVS, 2 = BSE etc. and testNumber is normal_hvct, sweep, offline, etc
testOptions = {0: ["NORMAL_HVCT", "SWEEP_HV_CT_RANGE", "OFFLINE_HV_CT", "PROPORTIONAL_APPS", "LOW_APPS", "HIGH_APPS"], 
               1: ["HV_VS_LOWER_BOUND", "HV_VS_UPPER_BOUND", "HV_VS_OUT_OF_LOWERBOUND", "HV_VS_OUT_OF_UPPERBOUND", "HV_VS_AT_ZERO", "HV_VS_SWEEP"]}

parser = argparse.ArgumentParser()
parser.add_argument("-tNa", "--testName", type = int, help = "test name")
parser.add_argument("-tNum", "--testNumber", type = int, help = "test number") #Can get rid of JSON as input to testboard. Use array instead that maps values to corresponding testcases/voltages
args = parser.parse_args()

if not len(sys.argv) > 1 :
    print('No arguments passed.')

else:
    if args.testName >= 0:
        print("test name: ", args.testName)

    else: 
        print("Invalid test name.")
        exit
    
    if args.testNumber >= 0:
        print("test number: ", args.testNumber)
    
    else:
        print("Invalid test number")
        exit
 

# Format the input values to send to testboard. Testboard will need changes for each test to map the input values to the correct tests
# Hardware inputs sent with UART to testboard
# Refer to overview of testboard team powerpoint slides

# Lauchpad is UART and need this to setup connection to launchpad
# For future reference to find UART port, go to Device Manager -> Ports (COM & LPT) -> connection that contain UART
launchpad = serial.Serial(port = "COM4", baudrate = 9600, bytesize = serial.EIGHTBITS, stopbits = serial.STOPBITS_TWO, timeout = 10)
launchpad.write(bytes("BMS", encoding='utf8'))
time.sleep(2)

# Send the test number to the test board
try:
    launchpad.write(bytes(testOptions[args.testName], encoding='utf8'))
except:
    print("Could not write test name to launchpad")

time.sleep(2)

# Send the test state to the testboard
try: 
    launchpad.write(bytes(testOptions[args.testName][args.testNumber], encoding='utf8'))
except:
    print("Could not write test number to launchpad.")

result = launchpad.read(size=50)
launchpad.close()

print("Results are: ", result)