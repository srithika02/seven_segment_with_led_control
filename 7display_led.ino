#include <SevSeg.h>

SevSeg S;

byte Commonpin[] = {12};      // Change to your COM pin
byte Segpins[] = {2,3,4,5,6,7,8};

int red = 10;
int yellow = 9;
int green = 11;

void setup() {

  S.begin(COMMON_ANODE, 1, Commonpin, Segpins, true);

  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);

  digitalWrite(red, HIGH);
}

void loop() {

  digitalWrite(red, HIGH);
  digitalWrite(green, LOW);

  for(int i=9; i>=0; i--) {
    display(i);
    delay(1000);

    if(i<=3){
      digitalWrite(yellow, HIGH);
      digitalWrite(red, LOW);
    }
  }

  digitalWrite(green, HIGH);
  digitalWrite(yellow, LOW);

  for(int i=9; i>=0; i--) {
    unsigned long start=millis();
    while(millis()-start<1000){
      S.setNumber(i);
      S.refreshDisplay();
    }

    if(i<=3){
      digitalWrite(yellow, HIGH);
      digitalWrite(green, LOW);
    }
  }

  digitalWrite(red, HIGH);
  digitalWrite(yellow, LOW);
  digitalWrite(green, LOW);
}

void display(int num)
{
  S.setNumber(num);
  S.refreshDisplay();
}
