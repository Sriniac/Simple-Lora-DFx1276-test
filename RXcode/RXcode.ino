#include <SoftwareSerial.h>
SoftwareSerial s(0,1);
#include <ArduinoJson.h>
   String data;

#include "UbidotsESPMQTT.h"

/****************************************
 * Define Constants
 ****************************************/
#define TOKEN "XXXXXXXXXXXXXXXXXXXXXXXXX" // Your Ubidots TOKEN
#define WIFINAME "XXXXXXXXXXXXXX" //Your SSID
#define WIFIPASS "XXXXXXXXXXXXXXXXX" // Your Wifi Pass
Ubidots client(TOKEN);
void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i=0;i<length;i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();
}
void setup() {
  // Initialize Serial port

  s.begin(9600);
  while (!Serial) continue;
    client.setDebug(true); // Pass a true or false bool value to activate debug messages
 
  client.wifiConnection(WIFINAME, WIFIPASS);
  client.begin(callback);
 
}

void loop() {
 StaticJsonBuffer<1000> jsonBuffer;
  JsonObject& root = jsonBuffer.parseObject(s);
  if (root == JsonObject::invalid())
    return;

  //Serial.println("JSON received and parsed");
   root.prettyPrintTo(data);
   Serial.println(data);

 int value1=root["sensor1"];
  int value2=root["sensor2"];
  int value3=root["sensor3"];
  int value4=root["sensor4"];
  int value5=root["sensor5"];
  int value6=root["sensor6"];
  int value7=root["sensor7"];
  int value8=root["sensor8"];
  int value9=root["sensor9"];
  int value10=root["sensor10"];
  int value11=root["sensor11"];
  int value12=root["sensor12"];
  int value13=root["sensor13"];
  int value14=root["sensor14"];
  int value15=root["sensor15"];
 

    if(!client.connected()){
      client.reconnect();
      }

   
   client.add("pot1", value1);
   client.add("pot2", value2);
   client.add("pot3", value3);
   client.add("pot4", value4);
   client.add("pot5", value5);
   client.add("pot6", value6);
   client.add("pot7", value7);
   client.add("pot8", value8);
   client.add("pot9", value9);
   client.add("pot10", value10);
   client.add("pot11", value11);
   client.add("pot12", value12);
   client.add("pot13", value13);
   client.add("pot14", value14);
   client.add("pot15", value15);
  client.ubidotsPublish("sending-end");
  client.loop();
   
  delay(1000);
}
