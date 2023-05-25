int s5 = 5;
int s6 = 6;
int sp = A0;
int digit1 = 2;
int digit2 = 3;
int digit3 = 4;
int i = 0, c = 1;
byte seven_seg[10][7] = { { 1,1,1,1,1,1,0 },  // = 0
                                 { 0,1,1,0,0,0,0 },  // = 1
                                 { 1,1,0,1,1,0,1 },  // = 2
                                 { 1,1,1,1,0,0,1 },  // = 3
                                 { 0,1,1,0,0,1,1 },  // = 4
                                 { 1,0,1,1,0,1,1 },  // = 5
                                 { 1,0,1,1,1,1,1 },  // = 6
                                 { 1,1,1,0,0,0,0 },  // = 7
                                 { 1,1,1,1,1,1,1 },  // = 8
                                 { 1,1,1,0,0,1,1 }   // = 9
                             };
void setup() {
  pinMode(6,INPUT);
  pinMode(5,INPUT);
  for(int i = 7; i <= 13; i++){
    pinMode(i,OUTPUT);
  }
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  Serial.begin(9600);
  displayNumber(0);
}

void loop() {
  s5 = digitalRead(5);
  s6 = digitalRead(6);
  displayNumber(i);
  if (s5 == LOW){
    c = 0;
  }
  if (c == 0){
    for(int j = 0; j <= 50;j++){
      displayNumber(i);
    }
    
    i = i + 1;
    if (i == 30){
     c = 1;
     tone(sp, 500, 300);
     
   }
   
   }
   if(i == 30){
   displayNumber(i);
   delay(100);
   }
   if (s6 == LOW){
    i = 0;
    displayNumber(i);
    }
  }

 void displayNumber(int toDisplay){
  for (int digit = 1; digit < 4; digit++){
    switch(digit){
      case 1:
        digitalWrite(digit2,HIGH);
        lightNumber(toDisplay % 10);
        toDisplay /= 10;
        break;
    
      case 2:
        digitalWrite(digit1,HIGH);
        lightNumber(toDisplay % 6);
        toDisplay /= 6;
        break;
      case 3:
        digitalWrite(digit3,HIGH);
        lightNumber(toDisplay % 6);
        toDisplay /= 6;
        break;
    }
    delayMicroseconds(6000);
    lightNumber(10);
    digitalWrite(digit1,LOW);
    digitalWrite(digit2,LOW);
    digitalWrite(digit3,LOW);
  }
 }

void lightNumber(int numberToDisplay){
  int pin = 7;
  for(int seg = 0; seg < 7; seg++){
    digitalWrite(pin, seven_seg[numberToDisplay][seg]);
    ++pin;
  }
}
