#include <SoftwareSerial.h>
#include <ArduinoJson.h>
SoftwareSerial s(D3,D2);
//int sensor1 = A0; 
//int sensor2 = A1; 
//int sensor3 = A2; 
//int sensor4 = A3; 
//int sensor5 = A4; 
//int sensor6 = A5; 
//int sensor7 = A6;
//int sensor8 = A7; 
//int sensor9 = A8; 
//int sensor10 = A9; 
//int sensor11 = A10;
//int sensor12 = A11; 
//int sensor13 = A12; 
//int sensor14 = A13; 
//int sensor15 = A14;  
int value1 = 0;
int value2 = 0;
int value3= 0;
int value4 = 0;
int value5 = 0;
int value6 = 0;
int value7 = 0;
int value8 = 0;
int value9 = 0;
int value10 = 0;
int value11 = 0;
int value12 = 0;
int value13 = 0;
int value14 = 0;
int value15 = 0;



void setup() {

s.begin(9600);
}
 
void loop() {
//   value1 = analogRead(sensor1);
//value2 = analogRead(sensor2);
//value3 = analogRead(sensor3);
//value4 = analogRead(sensor4);
//value5 = analogRead(sensor5);
//value6 = analogRead(sensor6);
//value7 = analogRead(sensor7);
//value8 = analogRead(sensor8);
//value9 = analogRead(sensor9);
//value10 = analogRead(sensor10);
//value11 = analogRead(sensor11);
//value12 = analogRead(sensor12);
//value13 = analogRead(sensor13);
//value14 = analogRead(sensor14);
//value15 = analogRead(sensor15);
   

 StaticJsonBuffer<1000> jsonBuffer;
 JsonObject& root = jsonBuffer.createObject();
root["sensor1"] = value1;
  root["sensor2"] = value2;
  root["sensor3"] = value3;
  root["sensor4"] = value4;
  root["sensor5"] = value5;
  root["sensor6"] = value6;
  root["sensor7"] = value7;
  root["sensor8"] = value8;
  root["sensor9"] = value9;
  root["sensor10"] = value10;
  root["sensor11"] = value11;
  root["sensor12"] = value12;
  root["sensor13"] = value13;
  root["sensor14"] = value14;
  root["sensor15"] = value15;
 

 root.printTo(s);
 delay(1000);
}
