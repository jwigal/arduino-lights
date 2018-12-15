/*
  Rainbow Lights 
  Jeff Wigal, December 2018

  Repeat the full spectrum of colors every 255 lights on a string. 
  Shift colors forward 1 light every second. 
  For shorter strings, change COMPRESSION to something bigger than 1
  
*/
#include <FastLED.h>
#define NUM_LEDS 300
#define LED_PIN 6
#define LED_TYPE WS2811
#define COLOR_ORDER RGB
#define COMPRESSION 1
CRGB leds[NUM_LEDS];

void setup() {
  delay(3000);
  FastLED.addLeds<LED_TYPE,LED_PIN,COLOR_ORDER>(leds,NUM_LEDS);
}

void loop() 
{
    for(int offset = 0 ; offset < 255 ; offset++){
      for(int i = 0; i < NUM_LEDS; i++ ) {
        CRGB color = CHSV(((i + offset) * COMPRESSION) % 255,255,255);
        leds[i] = color;
      }
      FastLED.show();
      delay(1000);
    }  
}
