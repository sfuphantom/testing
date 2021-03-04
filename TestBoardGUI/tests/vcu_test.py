#File to hold unit tests for the VCU using pytest

#include pytest in file: import pytest
# to run tests, call pytest.main() to run as if called on the commandline.
# can pass pytest.main() arguments - used to pass selected tests 

#in future to decode test board response, consult https://www.w3schools.com/python/python_json.asp

#implement tests as an integration test or test fully encompassing all vcu states to create a json

include pytest

normal_vcu = '{"Mode": "VCU", "APPS": NORMAL, "BSE": NORMAL, "IMD": NORMAL, "HV_VOLTAGE": NORMAL, "HV_CURRENT": NORMAL, "TSAL": NORMAL, "LOW_VOLTAGE": NORMAL, "COMMUNICATIONS": NORMAL, "REPEAT": 1}'

def build_json()
    vcu_json= '{"Mode": "VCU", "APPS": NORMAL, "BSE": NORMAL, "IMD": NORMAL, "HV_VOLTAGE": NORMAL, "HV_CURRENT": NORMAL, "TSAL": NORMAL, "LOW_VOLTAGE": NORMAL, "COMMUNICATIONS": NORMAL, "REPEAT": 1}'
    return vcu_json

def test_vcu_json()
    assert normal_vcu == build_json()