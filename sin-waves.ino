#include <FastLED.h>
#define joyX A0
#define joyY A1

CRGB leds[300];
const int stripSize = 52;

int x, y, selection, watch, r, g, b;
double sinX;
bool delaying;

void setup() {
  // put your setup code here, to run once:
  delay(2000);
  Serial.begin(9600);
  FastLED.addLeds<SM16703, 3, RGB>(leds, 300);
  x = 0;
  y = 0;
  selection = 0;
  watch = 0;
  r = 0;
  g = 0;
  b = 0;
  delaying = false;
  sinX = 0;
  
}

void loop() {
  // store joystick values
  //x = analogRead(joyX);
  //y = analogRead(joyY);

  /*r = map(x, 0, 1023, 1, 255);
  b = map(y, 0, 1023, 1, 255);
  Serial.print(" test: ");
  Serial.println(String(r) + " " + String(b));
  delay(100);
  */
  /*changeSelection(x);

  int newVal = map(y, 0, 1023, 1, 255);
  if(selection == 0){
    r = newVal;
  } else if (selection == 1){
    g = newVal;
  } else {
    b = newVal;
  }
  */
  b = 127 * sin(0.01 * sinX) + 127;
  g = 127 * sin(0.03 * sinX + 2) + 127;
  r = 127 * sin(0.05 * sinX + 4) + 127;
  sinX++;
  delay(50);
  
  setAll(CRGB(b, r, g));
}

void changeSelection(int x){
  // check if we are switching selection
  if(x > 600 && watch < 500){
    // increment selection and wrap it around if it is too high
    selection = (selection == 2) ? 0 : selection + 1;
    delaying = true;
  } else if(x < 400 && watch < 500){
    // decrement selection and wrap it around if it is too low
    selection = (selection == 0) ? 2 : selection - 1;
    delaying = true;
  } else if(watch >= 500){ // if the timer is up
    delaying = false;
  }

  if(delaying){
    watch++;
  }
}

void setAll(CRGB vals){
  for(int i = 0; i < stripSize; i++){
    leds[i] = vals;
  }
  FastLED.show();
}

void clear(){
  // clear leds
  for(int i = 0; i < 300; i++){
    leds[i] = CRGB(0,0,0);
  }
  FastLED.show();
  Serial.println("cleared");
}

void find(){
  clear();
  
  // run test
  for(int i = 0; i < 300; i++){
    leds[i] = CRGB(255, 255, 255);
    Serial.println(i);
    FastLED.show();
    delay(1000);
  }
}
