#include <ESP32Servo.h>
#include <BluetoothSerial.h>
BluetoothSerial BT;
Servo kicker;
const int IN1 = 33;
const int IN2 = 27;
const int IN3 = 13;
const int IN4 = 14;
const int servokicker = 32;
void move(int s1,int s2,int s3,int s4){
  digitalWrite(IN1,s1);
  digitalWrite(IN2,s2);
  digitalWrite(IN3,s3);
  digitalWrite(IN4,s4);
}
void setup() {
  BT.begin("FINAL_V");
  kicker.attach(servokicker);
  kicker.write(10);
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
}

void loop() {
  if (BT.available()){
    char cmd = BT.read();
    if (cmd = 'F') move(HIGH,LOW,HIGH,LOW);
    else if (cmd = 'B')move(LOW,HIGH,LOW,HIGH);
    else if (cmd = 'L')move(LOW,HIGH,HIGH,LOW);
    else if (cmd = 'R')move(HIGH,LOW,LOW,HIGH);
    else if (cmd = 'S')move(LOW,LOW,LOW,LOW);
    else if (cmd = 'Y'){kicker.write(130); delay(300);kicker.write(60);}
  }

}
