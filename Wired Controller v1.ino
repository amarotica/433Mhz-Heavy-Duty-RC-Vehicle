//Potentiometer center pin is conneceted with analog input A0 of arduino uno
//Potentiometer other two terminal are connecetd with 5V and ground



#include <SoftwareSerial9.h>
/*#define MOSI1 11
  #define MISO1 12
  #define TX1 MOSI1
  #define RX1 MISO1

  #define MOSI2 11
  #define MISO2 12
  #define TX2 MOSI2
  #define RX2 MISO2

  #define LEDPIN 13
*/
SoftwareSerial9 driverOne(9, 10);
SoftwareSerial9 driverTwo(11, 12);

void setup() {
  driverOne.begin(26315);
  driverTwo.begin(26315);
  //  Serial.begin(115200);
}

char c = ' ';
signed int val1 = 0;
signed int val2 = 0;

void loop() {

  int sensorValue1 = analogRead(A0);
  int sensorValue2 = analogRead(A1);
  int val1 = map(sensorValue1, 0, 1023, -250, 250);
  int val2 = map(sensorValue2, 0, 1023, -250, 250);// map the vlaues to new values
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  //  Serial.print("speed ");
  //  Serial.println(val);
  //  Serial.print(" low byte ");
  //  Serial.print((val & 0xFF), HEX);
  //  Serial.print(" high byte ");
  //  Serial.println((val >> 8) & 0xFF, HEX);
  //*******************************************
  //**********motor1 controlling***************
  driverOne.write9(256);
  driverOne.write9(val1 & 0xFF);
  driverOne.write9((val1 >> 8) & 0xFF);
  driverOne.write9(val1 & 0xFF);
  driverOne.write9((val1 >> 8) & 0xFF);
  driverOne.write9(85);
  driverOne.write9(128);
  driverOne.write9(128);
  delayMicroseconds(300);
  //**********motor2 controlling***************
  driverTwo.write9(256);
  driverTwo.write9(val2 & 0xFF);
  driverTwo.write9((val2 >> 8) & 0xFF);
  driverTwo.write9(val2 & 0xFF);
  driverTwo.write9((val2 >> 8) & 0xFF);
  driverTwo.write9(85);
  driverTwo.write9(128);
  driverTwo.write9(128);
  delayMicroseconds(300);
}
