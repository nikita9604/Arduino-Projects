//Automatic Car Parking System by NIKITA RATH//



#include <Servo.h>

Servo gate;                                                             //Open and close gate using Servo motor

int slot1 = 5;                                                          //Slot1 on digital pin 5

int slot2 = 4;                                                          //Slot2 on digital pin 4

int gateSensor = 3;                                                     //IR sensor of gate to digital pin 3

int slot1_l = 13;

int slot2_l = 12;

int gate_grn = 11;

int gate_red = 10;



void setup() 

{

  gate.attach(7); 

  pinMode(slot1,INPUT);                                                 //slot1 pin set as input to arduino

  pinMode(slot2,INPUT);                                                 //slot2 pin set as input to arduino

  pinMode(gateSensor,INPUT);                                            //gate IR sensor set as input to arduino

  pinMode(slot1_l,OUTPUT);

  pinMode(slot2_l,OUTPUT);

  pinMode(gate_grn,OUTPUT);

  pinMode(gate_red,OUTPUT);

  Serial.begin(9600);                                                   //initialize Serial monitor

}



void loop() 

{

    if( !(digitalRead(gateSensor)) && digitalRead(slot1) && digitalRead(slot2))

       {

          Serial.println("Available: Slot1, Slot2");                           //slot1 and slo2 available

          digitalWrite(slot1_l,HIGH);

          digitalWrite(slot2_l,HIGH);

          delay(1000);

          digitalWrite(gate_grn,HIGH);

          gate.write(100); 

       }

  if( !(digitalRead(gateSensor)) && !(digitalRead(slot1)) && digitalRead(slot2)) 

       {

          Serial.println("Available: Slot2");                                // slot2 available only

          digitalWrite(slot1_l,LOW);

          digitalWrite(slot2_l,HIGH);

          delay(1000);

          digitalWrite(gate_grn,HIGH);

          gate.write(100);

       }

      

   if( !(digitalRead(gateSensor)) && digitalRead(slot1) && !(digitalRead(slot2)))     

       {

          Serial.println("Available: Slot1");                                // slot1 available only

          digitalWrite(slot1_l,HIGH);

          digitalWrite(slot2_l,LOW);

          delay(1000);

          digitalWrite(gate_grn,HIGH);

          gate.write(75); 

          delay(100);                                                    //gate will open after 1 sec delay

       }

      

   if( !(digitalRead(gateSensor)) && !(digitalRead(slot1)) && !(digitalRead(slot2)))

       {

          Serial.println("No Parking (FULL)");                               // slot not available

          digitalWrite(slot1_l,LOW);

          digitalWrite(slot2_l,LOW);

          delay(1000);

          digitalWrite(gate_red,HIGH);

          delay(100);

          digitalWrite(gate_red,LOW);

          delay(100);

          digitalWrite(gate_red,HIGH);

          delay(100);

          digitalWrite(gate_red,LOW);  

       }            

  if( digitalRead(gateSensor))            

       { 

          Serial.println("Parking Available");                                // slot available

          gate.write(5);

          digitalWrite(slot1_l,LOW);

          digitalWrite(slot2_l,LOW);

          digitalWrite(gate_red,LOW);

          digitalWrite(gate_grn,HIGH);

          delay(100);

          digitalWrite(gate_grn,LOW);

          delay(100);

       }
