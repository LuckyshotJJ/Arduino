void setup() {
  // put your setup code here, to run once:
  for (int i = 13 ; i > 5; i--){
  pinMode(i,OUTPUT);
  }
  
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 13 ; i > 5; i--){
  digitalWrite(i,HIGH);
  delay(500);
  digitalWrite(i,LOW);
  }
  
}
