#include "FastLED.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#define switch_pin 12
#define switch_pin2 11
#define NUM_LEDS 60
#define NUM_LEDS2 60
#define DATA_PIN 8
#define DATA_PIN2 9
#define b_pin 7
#define led 6

CRGB leds[NUM_LEDS];
CRGB leds2[NUM_LEDS2];

const int buttonPin2 = 4;   
const int buttonPin3 = 5;
int buttonState2 = 0;   
int buttonState3 = 0;
const int buttonPin4 = 2;   
const int buttonPin5 = 3;
int buttonState4 = 0;   
int buttonState5 = 0;
int bstate=0;
int switchState = 0;
int switchState2 = 0;
int currentbuttonstate1;
int lastbuttonstate1;
int currentbuttonstate2;
int lastbuttonstate2;
int currentbuttonstate3;
int lastbuttonstate3;
int currentbuttonstate4;
int lastbuttonstate4;
int c1,c2,c3,c4=0;   
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  

void setup() {
Serial.begin(9600);

pinMode(buttonPin2, INPUT_PULLUP);
pinMode(buttonPin3, INPUT_PULLUP);
pinMode(buttonPin4, INPUT_PULLUP);
pinMode(buttonPin5, INPUT_PULLUP);
pinMode(switch_pin, INPUT);
pinMode(switch_pin2, INPUT);
pinMode(b_pin, INPUT_PULLUP);
pinMode(led, OUTPUT);
lcd.begin(20,4);
lcd.clear();
currentbuttonstate1 = digitalRead(buttonPin2);
currentbuttonstate2 = digitalRead(buttonPin3);
currentbuttonstate3 = digitalRead(buttonPin4);
currentbuttonstate4 = digitalRead(buttonPin5);
FastLED.addLeds<WS2812B, DATA_PIN, RGB>(leds, NUM_LEDS);
FastLED.addLeds<WS2812B, DATA_PIN2, RGB>(leds2, NUM_LEDS2);


}

int TurnSignal() {

for(int i = 0; i < NUM_LEDS; i++) {
leds[i] = CRGB(80, 255, 0);
FastLED.setBrightness (200);
FastLED.show();
delay(4);

}

delay(100);                               
FastLED.clear();
FastLED.show();                           
delay(350);   
switchState = digitalRead(switch_pin);
return switchState;                              
}

int TurnSignal2() {

for(int i = 0; i < NUM_LEDS2; i++) {
leds2[i] = CRGB(66, 255, 0);
FastLED.setBrightness (255);
FastLED.show();
delay(4);
}

delay(100);                               
FastLED.clear();
FastLED.show();                           
delay(350);   
switchState2 = digitalRead(switch_pin2);
return switchState2;                              
}

void DRL() {

FastLED.showColor(CRGB (66, 255, 0));
FastLED.setBrightness (95);                                   
}

int brake() {

for(int i = 0; i < NUM_LEDS2; i++) {
leds[i] = CRGB(0, 255, 0);
leds2[i] = CRGB(0, 255, 0);
FastLED.setBrightness (255);
FastLED.show();
delay(4);
}                            
}



void loop() {


switchState = digitalRead(switch_pin);
switchState2 = digitalRead(switch_pin2);
lastbuttonstate1    = currentbuttonstate1;   
lastbuttonstate2    = currentbuttonstate2;  
lastbuttonstate3    = currentbuttonstate3;   
lastbuttonstate4    = currentbuttonstate4;     // save the last state
currentbuttonstate1 = digitalRead(buttonPin2);
currentbuttonstate2 = digitalRead(buttonPin3);   // save the last state
currentbuttonstate3 = digitalRead(buttonPin4);
currentbuttonstate4 = digitalRead(buttonPin5);
  if(lastbuttonstate1 == HIGH && currentbuttonstate1 == LOW  ) {
    
    while(c1<4 )
    {
      lcd.setCursor(0,0);
      lastbuttonstate2    = currentbuttonstate2;  
      currentbuttonstate2 = digitalRead(buttonPin3);
      lcd.println("--USER COMMUNICATING--");
      lcd.setCursor(0,1);
      lcd.println("--GO FASTER-------");
      lcd.setCursor(0,3);
      lcd.println("!!!!!!!!!!!!!!!!!!!!");
      delay(500);
      lcd.clear();
      delay(500);
      c1=c1+1;
    }
    lcd.clear();
    c1=0;
    }
  if(lastbuttonstate2 == HIGH && currentbuttonstate2 == LOW ) {
    
    while(c2<4)
    {

      lcd.setCursor(0,0);
      lcd.println("--USER COMMUNICATING--");
      lcd.setCursor(0,1);
      lcd.println("--STOP IMMEDIATELY--");
      lcd.setCursor(0,3);
      lcd.println("!!!!!!!!!!!!!!!!!!!!");
      delay(500);
      lcd.clear();
      delay(500);
      c2=c2+1;
    }
    lcd.clear();
    c2=0;
    }
 if(lastbuttonstate3 == HIGH && currentbuttonstate3 == LOW  ) {
    
    while(c3<4 )
    {
      lcd.setCursor(0,0);
      lcd.println(">>>>>>>>>>>>>>>>>>>>");
      lcd.setCursor(0,1);
      lcd.println("------GO RIGHT------");
      lcd.setCursor(0,3);
      lcd.println(">>>>>>>>>>>>>>>>>>>>");
      delay(500);
      lcd.clear();
      delay(500);
      c3=c3+1;
    }
    lcd.clear();
    c3=0;
    }

    if(lastbuttonstate4 == HIGH && currentbuttonstate4 == LOW ) {
    
    while(c4<4 )
    {
      lcd.setCursor(0,0);
      lcd.println("<<<<<<<<<<<<<<<<<<<<");
      lcd.setCursor(0,1);
      lcd.println("------GO LEFT------");
      lcd.setCursor(0,3);
      lcd.println("<<<<<<<<<<<<<<<<<<<<");
      delay(500);
      lcd.clear();
      delay(500);
      c4=c4+1;
    }
    lcd.clear();
    c4=0;
    }
switchState = digitalRead(switch_pin);
switchState2 = digitalRead(switch_pin2);
bstate=digitalRead(b_pin);
Serial.println(bstate);
if (bstate== LOW){
  brake();
}
else{
  FastLED.clear();
  FastLED.show();
}
switchState = digitalRead(switch_pin);
switchState2 = digitalRead(switch_pin2);
while (switchState == HIGH ) //if it is,the state is HIGH
{
  switchState = digitalRead(switch_pin);
  bstate=digitalRead(b_pin);
  if(bstate==LOW){
  digitalWrite(led, HIGH);
  }
  else{
     FastLED.clear();
  FastLED.show();
  }
  Serial.println(bstate);
  lcd.setCursor(0,0);
  lcd.println("<<<<<<<<<<<<<<<<<<<<");
  lcd.setCursor(0,1);
  lcd.println("----GOING LEFT------");
  lcd.setCursor(0,3);
  lcd.println("<<<<<<<<<<<<<<<<<<<");
  delay(500);
  lcd.clear();
TurnSignal(); 
switchState = digitalRead(switch_pin);
}
lcd.clear();
FastLED.clear();
FastLED.show();
while (switchState2 == HIGH ) //if it is,the state is HIGH
{
  switchState2 = digitalRead(switch_pin2);
  bstate=digitalRead(b_pin);
  if(bstate==LOW){
    digitalWrite(led, HIGH);
    }
  else{
    digitalWrite(led, LOW);
  }
  Serial.println(bstate);
  lcd.setCursor(0,0);
  lcd.println(">>>>>>>>>>>>>>>>>>>>");
  lcd.setCursor(0,1);
  lcd.println("----GOING RIGHT------");
  lcd.setCursor(0,3);
  lcd.println(">>>>>>>>>>>>>>>>>>>>");
  delay(500);
  lcd.clear();
TurnSignal2();
switchState2 = digitalRead(switch_pin2);
}
lcd.clear();
FastLED.clear();
FastLED.show();

}
