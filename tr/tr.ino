#include <SoftwareSerial.h>

SoftwareSerial LORA(10, 11); // RX, TX
int send_char = 36; //$

String cmd = "";

void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
 while (!Serial){}
 LORA.begin(9600);
 
}

void loop() {
  // put your main code here, to run repeatedly:
if (LORA.available()){
  char SerialInByte;
  SerialInByte = LORA.read();
   if(SerialInByte==13) //carriage return \n
   { 
          Serial.print("Received message : ");
          Serial.println(cmd);
          cmd = "";
   }
   else
   {
    cmd += String(SerialInByte);
          /*
          // Uncomment this for debug
          Serial.print( "SerialInByte: " );
          Serial.print( SerialInByte, DEC );
          Serial.print( ", Buffer " );
          Serial.println( cmd ); */
   }
}
 if(Serial.available() > 0)
  {
    char SerialInByte;
    SerialInByte = Serial.read();
   if(SerialInByte==send_char) //$
   {
          Serial.print("Message sent : ");
          Serial.println(cmd);
          LORA.println(cmd);
          cmd = "";
   }
   else
   {
    cmd += String(SerialInByte);
          /*
          // Uncomment this for debug
          Serial.print( "SerialInByte: " );
          Serial.print( SerialInByte, DEC );
          Serial.print( ", Buffer " );
          Serial.println( cmd ); )*/
   }
  }
}
