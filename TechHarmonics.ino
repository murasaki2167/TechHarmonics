/*
Mega - CS: 53, SCK: 52, MOSI: 51, MISO: 50
UNO - CS: 10, SCK: 13, MOSI: 11, MISO: 12, 
sound signal: 12

*/
#include <SD.h>
#define SD_ChipSelectPin 53
#include <TMRpcm.h>

int button_1 = 11;
int IR_1 = 31;
int IR_2 = 33;
int IR_3 = 35;
int IR_4 = 37;
int IR_5 = 39;
int IR_6 = 41;
int IR_7 = 43;
int IR_8 = 45;
int mode = 1;


TMRpcm tmrpcm;
bool buttonState_1 = false;
bool IRState_1 = false;
bool IRState_2 = false;
bool IRState_3 = false;
bool IRState_4 = false;
bool IRState_5 = false;
bool IRState_6 = false;
bool IRState_7 = false;
bool IRState_8 = false;

void setup() {
  Serial.begin(9600);
  tmrpcm.speakerPin = 12;
  if (!SD.begin(SD_ChipSelectPin)){
    Serial.println("SD failed");
  } else {
    Serial.println("SD OK");
  }
  tmrpcm.setVolume(5);
  pinMode(button_1,INPUT_PULLUP);
 // digitalWrite(button_1, HIGH);
  pinMode(IR_1,INPUT);
  pinMode(IR_2,INPUT);
  pinMode(IR_3,INPUT);
  pinMode(IR_4,INPUT);
  pinMode(IR_5,INPUT);
  pinMode(IR_6,INPUT);
  pinMode(IR_7,INPUT);
  pinMode(IR_8,INPUT);
}

void loop() {

  int IR_1_Detected = digitalRead(IR_1);
  int IR_2_Detected = digitalRead(IR_2);
  int IR_3_Detected = digitalRead(IR_3);
  int IR_4_Detected = digitalRead(IR_4);
  int IR_5_Detected = digitalRead(IR_5);
  int IR_6_Detected = digitalRead(IR_6);
  int IR_7_Detected = digitalRead(IR_7);
  int IR_8_Detected = digitalRead(IR_8);

if (digitalRead(button_1) == LOW){
    if (buttonState_1 == false){
      buttonState_1 = true;
      if(mode == 1){
         mode = 2;
         Serial.write('B');
      } else {
        mode = 1;
        Serial.write('A');
      }
      delay(100);
    }
  } 
  else {
    buttonState_1 = false;
  }

if (IR_1_Detected == LOW){
    delay(20); // wait for 50ms to make sure it's a legitimate trigger
    if (digitalRead(IR_1) == LOW) { // check the sensor state again
        if (IRState_1 == false){
          IRState_1 = true;
          switch(mode) {
            case 1:
              tmrpcm.play("music1.wav");
              break;
            case 2:
              tmrpcm.play("1.wav");
              Serial.write('c');
              break;
          }
        }
    }
} else {
    IRState_1 = false;
}

if (IR_2_Detected == LOW){
    delay(20); // wait for 50ms to make sure it's a legitimate trigger
    if (digitalRead(IR_2) == LOW) { // check the sensor state again
        if (IRState_2 == false){
          IRState_2 = true;
          switch(mode) {
            case 1:
              tmrpcm.play("music2.wav");
              break;
            case 2:
              tmrpcm.play("2.wav");
              Serial.write('d');
              break;
          }
        }
    }
} else {
    IRState_2 = false;
}

  if (IR_3_Detected == LOW){
    delay(20); 
    if (digitalRead(IR_3) == LOW) { 
        if (IRState_3 == false){
          IRState_3 = true;
          switch(mode) {
            case 1:
              tmrpcm.play("music3.wav");
              break;
            case 2:
              tmrpcm.play("3.wav");
              Serial.write('e');
              break;
          }
        }
    }
  } else {
    IRState_3 = false;
  }

  if (IR_4_Detected == LOW){
    delay(20); 
    if (digitalRead(IR_4) == LOW) { 
        if (IRState_4 == false){
          IRState_4 = true;
          switch(mode) {
            case 1:
              tmrpcm.play("music4.wav");
              break;
            case 2:
              tmrpcm.play("4.wav");
              Serial.write('f');
              break;
          }
        }
    }
  } else {
    IRState_4 = false;
  }

  // For IR_5
  if (IR_5_Detected == LOW){
    delay(20); 
    if (digitalRead(IR_5) == LOW) { 
      if (IRState_5 == false){
        IRState_5 = true;
          switch(mode) {
            case 1:
              tmrpcm.play("music5.wav");
              break;
            case 2:
              tmrpcm.play("5.wav");
              Serial.write('g');
              break;
          }
      }
    }
  } else {
    IRState_5 = false;
  }

  // For IR_6
  if (IR_6_Detected == LOW){
    delay(20); 
    if (digitalRead(IR_6) == LOW) { 
      if (IRState_6 == false){
        IRState_6 = true;
          switch(mode) {
            case 1:
              tmrpcm.play("music6.wav");
              break;
            case 2:
              tmrpcm.play("6.wav");
              Serial.write('a');
              break;
          }
      }
    }
  } else {
    IRState_6 = false;
  }

  // For IR_7
  if (IR_7_Detected == LOW){
    delay(20); 
    if (digitalRead(IR_7) == LOW) { 
      if (IRState_7 == false){
        IRState_7 = true;
          switch(mode) {
            case 1:
              tmrpcm.play("music7.wav");
              break;
            case 2:
              tmrpcm.play("7.wav");
              Serial.write('b');
              break;
          }
      }
    }
  } else {
    IRState_7 = false;
  }

  // For IR_8
  if (IR_8_Detected == LOW){
    delay(20); 
    if (digitalRead(IR_8) == LOW) { 
      if (IRState_8 == false){
        IRState_8 = true;
          switch(mode) {
            case 1:
              tmrpcm.play("music8.wav");
              break;
            case 2:
              tmrpcm.play("8.wav");
              Serial.write('C');
              break;
          }
      }
    }
  } else {
    IRState_8 = false;
  }




}