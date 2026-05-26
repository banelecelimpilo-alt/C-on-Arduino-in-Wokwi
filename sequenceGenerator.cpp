#include "Arduino.h" 
#include "sequenceGenerator.h"

  SequenceGenerator::SequenceGenerator(int led1, int led2, int led3, int led4, int led5, int led6, int led7, int led8)
  {
    diode1 = led1;
    diode2 = led2;
    diode3 = led3;
    diode4 = led4;
    diode5 = led5;
    diode6 = led6;
    diode7 = led7;
    diode8 = led8;
  }// SequenceGenerator constructor

  void SequenceGenerator::pinSetup()
  {
   pinMode(diode1, OUTPUT);
   pinMode(diode2, OUTPUT);
   pinMode(diode3, OUTPUT);
   pinMode(diode4, OUTPUT);
   pinMode(diode5, OUTPUT);
   pinMode(diode6, OUTPUT);
   pinMode(diode7, OUTPUT);
   pinMode(diode8, OUTPUT);
  }// setting of LED pins to OUTPUT


  void SequenceGenerator::beginLevel() {
   // All LEDs are lit to indicate a level will begin.

   for(int i = 2; i < 6; i++) digitalWrite(i, HIGH);// write to digital pins

   for(int i = 16; i < 20; i++) digitalWrite(i, HIGH);// write to analog pins
   delay(5000);

   for(int i = 2; i < 6; i++) digitalWrite(i, LOW);// write to digital pins

   for(int i = 16; i < 20; i++) digitalWrite(i, LOW); // write to analog pins
   delay(2000);// wait 2 seconds before starting level

  }// begin level for lighting LEDS


  void SequenceGenerator::sequence() {
    for(int i = 0; i < 8; i++) {// loop that lightathe LEDs in the sequence of the pins given by the array "ledSequenceArray" 
        digitalWrite(ledSequenceArray[i], HIGH); // 
        delay(2000);// wait 2 seconds before lighting next LED
    }// write to digital pins

    for(int i = 2; i < 6; i++) {
        digitalWrite(i, LOW);// write to digital pins
    }
    for(int i = 16; i < 20; i++) {
        digitalWrite(i, LOW); // write to analog pins
    }
  }// sequence of LED lighting


void SequenceGenerator::resetSequence(bool &isCorrectButtonPressed) {
  while(!isCorrectButtonPressed) {
   for(int i = 2; i < 6; i++) digitalWrite(i, HIGH); // write to digital pins
   delay(500);

   for(int i = 2; i < 6; i++) digitalWrite(i, LOW);// write to digital pins 
   delay(500);

   for(int i = 16; i < 20; i++)digitalWrite(i, HIGH);// write to analog pins
   delay(500);

   for(int i = 16; i < 20; i++)digitalWrite(i, LOW);// write to analog pins
   delay(500);
  }
}//resetSequence


void SequenceGenerator::completedLevelSequence() {
  // Turn off all LEDs
  for(int i = 2; i < 6; i++) {
    digitalWrite(i, LOW);
  }// write to digital pins 

  for(int i = 16; i < 20; i++) {
    digitalWrite(i, LOW); // write to analog pins
  }

  for(int i = 2; i < 6; i++) {
    digitalWrite(i, HIGH);
    delay(200);
   }// write to digital pins

    for(int i = 6; i > 1 ; i--) {
      digitalWrite(i, LOW);
      delay(200);
   }// write to digital pins 
    
   for(int i = 20; i > 15; i--) {
     digitalWrite(i, HIGH);
     delay(200);
   }// write to analog pins
    
    for(int i = 16; i < 20; i++) {
     digitalWrite(i, LOW);
     delay(200);
   }// write to analog pins
  
}//completed level sequence


void SequenceGenerator::randomiseLedSequenceArray(int& level) {
    int num = sizeof(ledSequenceArray) / sizeof(ledSequenceArray[0]);

    if (level == 2) {
    for (int i = 0; i < 8; i += 2) {
      if (random(2) == 1) {
        int temp = ledSequenceArray[i];
        ledSequenceArray[i] = ledSequenceArray[i + 1];
        ledSequenceArray[i + 1] = temp;
      }
    }
    }
    else if (level == 3) {
        for (int i = 0; i < num / 2; i++) {
            int j = random(0, num / 2);
            int temp = ledSequenceArray[i];
            ledSequenceArray[i] = ledSequenceArray[j];
            ledSequenceArray[j] = temp;
        }

        for (int i = num / 2; i < num; i++) {
            int j = random(0, (num - num / 2)) + (num / 2);
            int temp = ledSequenceArray[i];
            ledSequenceArray[i] = ledSequenceArray[j];
            ledSequenceArray[j] = temp;
        }
    }
    else if (level == 4) {
        for (int i = 0; i < num; i++) {
            int j = random(0, num);
            int temp = ledSequenceArray[i];
            ledSequenceArray[i] = ledSequenceArray[j];
            ledSequenceArray[j] = temp;
        }
    }
}



void SequenceGenerator::gameFinishedSequence(int &level) {
   while(level == 4)
   { 
    for(int i = 2; i < 6; i++) digitalWrite(i, HIGH); // write to digital pins
    for(int i = 16; i < 20; i++)digitalWrite(i, HIGH);// write to analog pins
    delay(500);

    for(int i = 2; i < 6; i++) digitalWrite(i, LOW);// write to digital pins 
    for(int i = 16; i < 20; i++)digitalWrite(i, LOW);// write to analog pins
    delay(500);
   }//while level == 4
 }//gameFinishedSequence