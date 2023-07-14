#include<Arduino.h>

//https://www.keuwl.com/electronics/rduino/bluet/02-pwm-leds/

int Blue_LED_Pin = 3; // PWM Pin for Blue LED

int Blue_value=0;

char BluetoothData; // the data received from bluetooth serial link

void setup() {
  

  pinMode(Blue_LED_Pin, OUTPUT);

  Serial.begin(9600);
}

void loop() {

  
  if (Serial.available()){
    BluetoothData=Serial.read(); //Get next character from bluetooth
 
    if(BluetoothData=='B') Blue_value=Serial.parseInt(); //Read Blue Value
  }
  

  analogWrite(Blue_LED_Pin, Blue_value);
  
  delay(10);
  
}
