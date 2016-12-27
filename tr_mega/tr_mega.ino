#include <SoftwareSerial.h>

SoftwareSerial LORA(10, 11); // RX, TX

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
   if(SerialInByte==13) //carriae return
   { 
          Serial.print("Message recu : ");
          Serial.println(cmd);
          cmd = "";
   }
   else
   {
    cmd += String(SerialInByte);
          /*
          // et afficher un message de déboggage
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
   if(SerialInByte==36) //Cariage return \n
   {
          Serial.print("Message envoye : ");
          Serial.println(cmd);
          LORA.println(cmd);
          cmd = "";
   }
   else
   {
    cmd += String(SerialInByte);
          /*
          // et afficher un message de déboggage
          Serial.print( "SerialInByte: " );
          Serial.print( SerialInByte, DEC );
          Serial.print( ", Buffer " );
          Serial.println( cmd ); )*/
   }
  }
}
