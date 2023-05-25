int bs7;
int bs6;
int bs5;

void setup() {
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(7,INPUT);
  pinMode(6,INPUT);
  pinMode(5,INPUT);
  Serial.begin(9600);
}

void loop() {
  bs7 = digitalRead(7);
  bs6 = digitalRead(6);
  bs5 = digitalRead(5);
 //------------按下SW1：單燈左移3次後回預設狀態
  if(bs7 == LOW){
    for (int i = 0; i<3;i++){
    digitalWrite(13,HIGH);
    delay(500);
    digitalWrite(13,LOW);
    digitalWrite(12,HIGH);
    delay(500);
    digitalWrite(12,LOW);
    digitalWrite(11,HIGH);
    delay(500);
    digitalWrite(11,LOW);
    digitalWrite(10,HIGH);
    delay(500);
    digitalWrite(10,LOW);
    }
  }
//-------------按下SW2：單燈右移3次後回預設狀態
  else if(bs6 == LOW){
    for (int i = 0; i<3;i++){
    digitalWrite(10,HIGH);
    delay(500);
    digitalWrite(10,LOW);
    digitalWrite(11,HIGH);
    delay(500);
    digitalWrite(11,LOW);
    digitalWrite(12,HIGH);
    delay(500);
    digitalWrite(12,LOW);
    digitalWrite(13,HIGH);
    delay(500);
    digitalWrite(13,LOW);
    }
  }
//-------------按下SW3：左右交互閃爍3次後回預設狀態
  else if(bs5 == LOW){
    for (int i = 0; i<3;i++){
    digitalWrite(10,HIGH);
    digitalWrite(11,HIGH);
    digitalWrite(12,LOW);
    digitalWrite(13,LOW);
    delay(500);
    digitalWrite(10,LOW);
    digitalWrite(11,LOW);
    digitalWrite(12,HIGH);
    digitalWrite(13,HIGH);
    delay(500);
    }
  }
//-------------預設：4燈不停閃爍
  else if(bs7 == HIGH && bs6 == HIGH && bs5 == HIGH){
    digitalWrite(13,HIGH);
    digitalWrite(12,HIGH);
    digitalWrite(11,HIGH);
    digitalWrite(10,HIGH);
    delay(500);
    digitalWrite(13,LOW);
    digitalWrite(12,LOW);
    digitalWrite(11,LOW);
    digitalWrite(10,LOW);
    delay(500);
  }
}
