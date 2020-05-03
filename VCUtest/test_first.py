import pytest
import serial

launchpad = serial.Serial('COM8', 9600)
print("connected to: " + launchpad.portstr)

# vcu = serial.Serial('COM16',9600)

print('Commands to run automated tests on launchpad')

print('1: BSE Test')
print('2: APPS Test')
while True:
    var = input("Please enter something: ")
    print("You entered: " + var)

    launchpad.write(var.encode())  # start APPS test

    # this will store the line
    seq = []
    count = 1


    for c in launchpad.read():
        seq.append(chr(c))  # convert from ANSII
        joined_seq = ''.join(str(v) for v in seq)  # make a string from array

        if chr(c) == '\n':
            print("Line " + str(count) + ': ' + joined_seq)
            seq = []
            count += 1
            break


launchpad.close()


def test_bse():

    # command the launchpad to start BSE tests

    launchpad.write('1'.encode())  # start BSE short to GND

    # now wait for VCU to give a reply for BSE failure

    # this will store the line
    seq = []
    count = 1

    for c in vcu.read():
        seq.append(chr(c))  # convert from ANSII
        joined_seq = ''.join(str(v) for v in seq)  # make a string from array

        if chr(c) == '\n':
            print("Line " + str(count) + ': ' + joined_seq)
            seq = []
            count += 1
            break

    assert "BSE Fault short to GND" == joined_seq, "BSE Test Failed"

    # also check for state switch to tractive on?? what is the fault handling case?

    # x = 5
    # y = 6
    # assert x+1 == y, "test failed"

def test_file1_method2():
    x = 5
    y = 6
    assert x+1 == y, "test failed"
    assert x == y, "test failed"