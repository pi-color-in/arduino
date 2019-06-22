import serial

# data='2000100020001000'
# dataB=''

#use ttyUSB0 se for o caso, ou se for Windows, COMx.
arduino = serial.Serial('/dev/ttyACM0',9600,timeout=2)

# dataB=bytes.encode(data)
# print(type(dataB))
arduino.write(bytes(b'2000100020001000'))
arduino.read()
