# SemtechLoRaSX1278ChatTTL

There is how to setup a "chat" with a Semtech LoRa SX1278 Data Radio Modem DRF1278DM

The file "tr.ino" should be uploaded on the two arduinos.

#/!\ THIS WORKS ONLY WITH ARDUINO UNO, NANO FOR OTHERS ARDUINO SCROLL THE FILE

LoRa -> Arduino 

GND -> GND
VCC -> 5V
EN -> GND
TX -> Digital 10
RX -> Digital 11

You need to open the serial console with arduino on one computer, and open the serial console of the other arduino on another computer.
Then you can send your messages between the two computers, BUT the messages should end by a '$' : if you want to send "hello", your command in the serial console should look like this : hello$

You can also send many messages in 1 command like : hello$how are you ?$ok right$

#Arduino mega here :3
On arduino mega you should edit the code a bit :
We don't need "SoftwareSerial.h" because the aruino mega has 4 serial ports, use "Serial1" instead of "LORA".

LoRa -> Arduino mega

GND -> GND
VCC -> 5V
EN -> GND
TX -> RX1
RX -> TX1

Hope this little piece of code will help you :)
