#include "BluetoothSerial.h"

// Only for M5Stack Core 2
#include <M5Core2.h>

BluetoothSerial SerialBT; //Object for Bluetooth

int incoming;
int bytecount;

void setup() {
// Only for M5Stack Core 2
  M5.begin();

// If not using M5Stack Core 2
//  Serial.begin(115200); 

  Serial.println("ID: Spark 40 Audio");
  Serial.println("Starting Bluetooth...");

  if (!SerialBT.begin("Spark 40 Audio")) 
    Serial.println("Bluetooth init failed"); 
  else
    Serial.println("Bluetooth Device is Ready to Pair");
}


void loop() {
  bytecount = 0;  
  while (SerialBT.available()) //Check if we receive anything from Bluetooth
  {
    incoming = SerialBT.read(); //Read what we recevive 
    if (incoming < 16) Serial.print ("0");
    Serial.print(incoming, HEX);
    Serial.print(" ");
    
    bytecount += 1;
    if (bytecount % 20 == 0) Serial.println(); 
  };
  
  if ((bytecount % 20) != 0) Serial.println();
  Serial.print("That message had ");
  Serial.print(bytecount);
  Serial.println(" bytes");
  Serial.println("====================================");

  while (!SerialBT.available())
  {
    delay(200);
  }
}
