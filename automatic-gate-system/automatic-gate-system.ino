#include <LiquidCrystal.h>
#include <Servo.h>
int count=0;
#define LIMIT 5
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
Servo entryServo,exitServo;
bool entryState,exitState;
#define entrySensor A0
#define exitSensor A1
void setup() {
 lcd.begin(16,2);
 lcd.setCursor(3,0);
 lcd.print("Sci-COPATH");
 lcd.setCursor(0,1);
 lcd.print("count : ");
 lcd.print("0");
 pinMode(entrySensor,INPUT);
 pinMode(exitSensor,INPUT);
 entryServo.attach(10);
 exitServo.attach(9);
 Serial.begin(9600);
 
}

void loop() {
  if(count==LIMIT){
    lcd.setCursor(0,0);
    lcd.print("  LIMIT EXIST   ");
  }else{
    lcd.setCursor(0,0);
    lcd.print("   Sci-COPATH   ");
  }
  if(digitalRead(entrySensor)==HIGH&&count<LIMIT){
     entryServo.write(90);
     count=count+1;
     lcd.setCursor(0,1);
     lcd.print("count : ");
     lcd.print(count);
     delay(1500);
  }else if(digitalRead(entrySensor)==LOW){
    entryServo.write(0);
  }
  if(digitalRead(exitSensor)==HIGH){
     exitServo.write(90);
     count=count-1;
     lcd.setCursor(0,1);
     lcd.print("count : ");
     lcd.print(count);
     delay(1500);
  }else if(digitalRead(exitSensor)==LOW){
    exitServo.write(0);
  }
} 