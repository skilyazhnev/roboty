#!/bin/python3

import serial
import struct
import crc8
from sys import argv
import sys


script, first, second = argv

try:
   ser = serial.Serial(first, 115200)
except:
   sys.exit(1)


ser.reset_input_buffer()


sor = 0


while int(sor) <  int(second):
        # Ждём начало пакета
        s = ser.read()
        if s == b'\x0c':

           # Читаем Длинну данных + команда
           b = ser.read()
           lens = int.from_bytes(b, byteorder='big')

           # Читаем СRC8
           crc8s = ser.read()

           # Читаем командный байт в пакете
           command = ser.read()

           # Читаем массив данных
           data = ser.read(lens-1)

           # Считаем и проверяем CRC
           hash = crc8.crc8()
           hash.update(data)
           csum = hash.digest()
           if (csum != crc8s):
                 continue


           sor += 1

           # Получаем вектор int с данными датчиков
           od = []
           for i in range(0,lens-1,2):
              post = struct.unpack( "h", data[i:i+2] )
              od.append(post[0])
          # for i in range(24):
          #     od[i]=(od[i]-73.68429361)/1.5872402

           od[0]=(od[0]-73.68429361)/1.5872402

           # Выведем значения В OUTPUT
           print("Значения с АЦП: "+ str(od[0]))

ser.close()
