#include <FastLED.h>

CRGB leds[50];

int r, g, b = 0;
const int size = 52;
int delayAmt = 20;

void setup() {
  
  delay(2000);
  Serial.begin(9600);
  FastLED.addLeds<SM16703, 3, RGB>(leds, size);
  
}

void loop() {
  redChase();
  greenChase();
  blueChase();
}

void redChase(){
    for(int j = 5; j <= 255; j +=30){
    for(int i = 0; i < size; i++){
      leds[i] = CRGB(b, r, g);
      FastLED.show();
      Serial.print(i);
      Serial.print(" rgb value: ");
      Serial.print(r);
      Serial.println();
      delay(delayAmt);  
      }
    r=j;
  }
  r=0;
}

void greenChase(){
    for(int j = 5; j <= 255; j +=30){
    for(int i = 0; i < size; i++){
      leds[i] = CRGB(b, r, g);
      FastLED.show();
      Serial.print(i);
      Serial.print(" rgb value: ");
      Serial.print(g);
      Serial.println();
      delay(delayAmt);  
      }
    g=j;
  }
  g=0;
}

void blueChase(){
   for(int j = 5; j <= 255; j +=30){
    for(int i = 0; i < size; i++){
      leds[i] = CRGB(b, r, g);
      FastLED.show();
      Serial.print(i);
      Serial.print(" rgb value: ");
      Serial.print(b);
      Serial.println();
      delay(delayAmt);  
      }
    b=j;
  }
  b=0;
}
