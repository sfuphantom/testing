import serial
import random
import time
import struct
import threading
from tkinter import *

class BMS_gui:
    def __init__(self, master):
        frame = Frame(master)
        frame.pack()

        self.state_dict = {}

        x = 0
        while x < len(Slave1.battery):
            self.state_dict[('Cell '+str(x))] = Slave1.battery[x].state
            self.runUUU = Checkbutton(frame, text=("Cell "+str(x+1)), variable=self.state_dict[('Cell '+str(x))])
            self.runUUU.grid(row=1, column = x)
            x+=1


class BMS_Slave:
    def __init__(self):
        self.battery = [lionCell(3.25, 0.003), lionCell(3.25, 0.004), lionCell(3.25, 0.0025), lionCell(3.25, 0.0027), lionCell(3.25, 0.0033),
                        lionCell(3.25, 0.0028), lionCell(3.25, 0.0037), lionCell(3.25, 0.0039), lionCell(3.25, 0.0045), lionCell(3.25, 0.0023)]
            
        self.BMSArray = []

    def balanceCells(self, balanceList):
        counter = 0
        for cell in balanceList:
            if cell == 1:
                self.battery[counter].state = 0
            else:
                self.battery[counter].state = 1

            counter += 1


class lionCell:
    def __init__(self, curVol, grad):
        self.CurrentVoltage = curVol
        self.gradient = grad
        self.state = 0
        self.timeOn = 140


    def battCharge(self):
        if self.state == 1 and self.CurrentVoltage <= 4.2:
            self.timeOn -= 1
            self.CurrentVoltage = 4.2 - (2*10**-6)*self.timeOn**3 + (0.000416)*self.timeOn**2 - (0.0265)*self.timeOn
        elif self.state == 0:
            self.timeOn -= 1
            self.CurrentVoltage = 0.9975*(4.2 - (2*10**-6)*self.timeOn**3 + (0.000416)*self.timeOn**2 - (0.0265)*self.timeOn)
        return self.CurrentVoltage

    def VoltageToAV(self):
        return divmod(((self.CurrentVoltage/5)*65535), 256)

def batteryThread():
    print("entering battery thread")
    x = 0
    while True:
        Slave1.BMSArray.append(0)
        while x < len(Slave1.battery):
            Slave1.battery[x].battCharge()
            Slave1.BMSArray.append(int(Slave1.battery[x].VoltageToAV()[0]))
            Slave1.BMSArray.append(int(Slave1.battery[x].VoltageToAV()[1]))
            print(Slave1.battery[x].CurrentVoltage)
            x += 1

        print("")
        x = 0

        print(Slave1.battery[1].timeOn)

        values = bytes(Slave1.BMSArray)
        Slave1.BMSArray.clear()



        #bmsMaster.write(values)
        time.sleep(1)

def BalanceThread():
    print("entering balance thread")
    sensorLine = ''
    balMask = []
    while True:
        print("balancing")
        sensorLine =((bmsMaster.readline()).decode("latin1"))
        try:
            print(str(bin(int(sensorLine))))
            balMask = [int(d) for d in str(bin(int(sensorLine)))[2:].zfill(10)]

            Slave1.balanceCells(balMask)
            print(balMask)

            balMask.clear()
        except Exception as e:
            print(e)

# def displayThread():
#     while True:
#         root = Tk()
#         bmsGUI = BMS_gui(root)
#         #root.after(100, displayThread)


bmsMaster = serial.Serial('COM15', 115200)
print("connected to: " + bmsMaster.portstr)

Slave1 = BMS_Slave() 

slave_thread = threading.Thread(target=batteryThread, args = ())
slave_thread.start()

bal_thread = threading.Thread(target=BalanceThread, args = ())
#bal_thread.start()

#gui_thread = threading.Thread(target=displayThread, args = ())
#gui_thread.start()