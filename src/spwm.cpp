#include <Arduino.h>
#include <Servo.h>

Servo bldc;
int Val = 1;
int Val2 = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  bldc.attach(11,1000,2000);
  bldc.write(0);
  delay(1000);
  bldc.write(6);
  delay(800);
  bldc.write(8);
  delay(300);
  bldc.write(10);
  delay(300);
  bldc.write(15);
  delay(300);
  bldc.write(20);
  delay(2000);
  bldc.write(15);
  delay(300);
  bldc.write(10);
  delay(300);
  bldc.write(6);
  delay(300);
  bldc.write(4);
  delay(200);
}
void loop() {
    if (Serial.available()>0){
        Val = Serial.parseInt();
        if (Val!=Val2 && Val!=0){
          Serial.println(Val);
          bldc.write(Val);
          Val2=Val;
        }
    }
    delay(50);
}