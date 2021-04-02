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
#import serial

selectedTest_example = [{'Test Name': 'x', 'Test Case': 'x', 'Repeat': None, 'Test Index': None}, {'Test Name': 'y', 'y': 'y', 'Repeat': None, 'Test Index': None}]

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

    for x in selectedTest_example:
        selectedJson.update({selectedTest_example[x].get('Test Name'), "TEST_ENUM"})
    
    #Serial Stuff

    return selectedJson

#testing functions
def test_bms_json():
    assert normal_bms != build_json()






