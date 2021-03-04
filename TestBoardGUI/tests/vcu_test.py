#File to hold unit tests for the VCU using pytest

#include pytest in file: import pytest
# to run tests, call pytest.main() to run as if called on the commandline.
# can pass pytest.main() arguments - used to pass selected tests 

#in future to decode test board response, consult https://www.w3schools.com/python/python_json.asp

#implement tests as an integration test or test fully encompassing all vcu states to create a json

import pytest
import json

# dictionary object of VCU in default state (NORMAL enums, 1 repetition for all key-value pairs)
normal_vcu = {
    "Mode": "VCU",
    "apps": "NORMAL",
	"bse": "NORMAL",
	"imd": "NORMAL",
	"hvvoltage": "NORMAL",
	"hvcurrent": "NORMAL",
	"tsal": "NORMAL",
	"lv": "NORMAL",
	"communications": "NORMAL",
	"repeat": 1

}

def build_json():
    return normal_vcu

def test_vcu_json():
    assert normal_vcu == build_json()

def test_appsval():
    assert "NORMAL" == normal_vcu.get("apps")

def test_apps_implausibility():
    normal_vcu.update({"apps": "IMPLAUSIBILITY"})
    assert "IMPLAUSIBILITY" == normal_vcu.get("apps")
