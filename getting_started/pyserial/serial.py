##
# Depends on pySerial
# 
# On mac, run this first:
#   sudo easy_install pyserial
##

import serial

incoming = serial.Serial(port='/dev/ttys000', baudrate=19200)

incoming.write('text')
incoming.read()
incoming.readline()
