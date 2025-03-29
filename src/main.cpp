#include <Arduino.h>
#define RelayPin 10
#define btn1S 9
#define btn2D 8
#define LedPinR 7
#define LedPinG 6
#define BuzzPin 5
 const int countDown= 30;
void setup() {
  pinMode(LedPinR,OUTPUT);
  pinMode(LedPinG,OUTPUT);
  pinMode(BuzzPin,OUTPUT);
  pinMode(btn1S,INPUT_PULLUP);
  pinMode(btn2D,INPUT_PULLUP);
  pinMode(RelayPin, OUTPUT);
  Serial.begin(115200);
  digitalWrite(LedPinG,HIGH);

}

void loop() {
 
  int btn1Stat=digitalRead(btn1S);
  
 if(!btn1Stat){
  Serial.println("defuse the bomb ma boy or it will explode in 30 seconds");
  digitalWrite(LedPinR,HIGH);
  digitalWrite(LedPinG,LOW);
  tone(BuzzPin,1000);
  for(int i=countDown;i >=0;i--){ 
    Serial.println("time remaning: ");
    Serial.println(i);
    delay(1000);
    int btn2Stat=digitalRead(btn2D);
    if(btn2Stat==LOW){
      Serial.println("congrats its defused! ");
      digitalWrite(LedPinG,HIGH);
      digitalWrite(LedPinR,LOW);
      noTone(BuzzPin);
      digitalWrite(RelayPin,LOW);
      return;
    }
  }
  Serial.println("Boooooooooom");
  digitalWrite(RelayPin,HIGH);
  delay(3000);
  noTone(BuzzPin);

 }

 
    digitalWrite(LedPinG,HIGH);
  
}