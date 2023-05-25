#include "pitches.h"
#include <Keypad.h>

const byte ROWS = 4;
const byte COLS = 4;

char sounds[ROWS][COLS] = {
{'1', '2', '3', '4'},
{'5', '6', '7', '8'},
{'9', 'A', 'B', 'C'},
{'D', 'E', 'F', 'G'}
};

int melody[] = {
  NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4, 
  NOTE_G4, NOTE_A4, NOTE_B4, NOTE_C5,
  NOTE_D5, NOTE_E5, NOTE_F5, NOTE_G5,
  NOTE_A5, NOTE_B5, NOTE_C6, NOTE_D6
};

byte rowp[ROWS] = {2, 3, 4, 5};
byte colp[COLS] = {9, 8, 7, 6};

Keypad keypad = Keypad( makeKeymap(sounds), rowp, colp, ROWS, COLS );

int sp = 13;
int bp = 12;
int gp = 11;
int rp = 10;

void setup() {
  // put your setup code here, to run once:
  pinMode(sp, OUTPUT);
  pinMode(bp, OUTPUT);
  pinMode(gp, OUTPUT);
  pinMode(rp, OUTPUT);
  for (int i = 2; i <= 9;i++){
    pinMode(i, INPUT);
  }
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  char sound = keypad.getKey();

  if (sound != NO_KEY){
    analogWrite(rp, random(0, 255));
    analogWrite(gp, random(0, 255));
    analogWrite(bp, random(0, 255));
    if (sound == '1'){
      tone(sp, melody[0], 300);
   }

   if (sound == '2'){
      tone(sp, melody[1], 300);
   }

   if (sound == '3'){
      tone(sp, melody[2], 300);
   }

   if (sound == '4'){
      tone(sp, melody[3], 300);
   }

   if (sound == '5'){
      tone(sp, melody[4], 300);
   }

   if (sound == '6'){
      tone(sp, melody[5], 300);
   }

   if (sound == '7'){
      tone(sp, melody[6], 300);
   }
   
   if (sound == '8'){
      tone(sp, melody[7], 300);
   }

   if (sound == '9'){
      tone(sp, melody[8], 300);
   }

   if (sound == 'A'){
      tone(sp, melody[9], 300);
   }

   if (sound == 'B'){
      tone(sp, melody[10], 300);
   }

   if (sound == 'C'){
      tone(sp, melody[11], 300);
   }

   if (sound == 'D'){
      tone(sp, melody[12], 300);
   }

   if (sound == 'E'){
      tone(sp, melody[13], 300);
   }

   if (sound == 'F'){
      tone(sp, melody[14], 300);
   }

   if (sound == 'G'){
      tone(sp, melody[15], 300);
   }

  }
}
