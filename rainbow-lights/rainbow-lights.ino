#include <FastLED.h>
#define NUM_LEDS 300
#define LED_PIN 6
#define LED_TYPE WS2811
#define COLOR_ORDER RGB

CRGB leds[NUM_LEDS];

void setup() {
  delay(3000); // sanity delay
  FastLED.addLeds<LED_TYPE,LED_PIN,COLOR_ORDER>(leds,NUM_LEDS);
}

void loop() 
{

    for(int offset = 0 ; offset < NUM_LEDS ; offset++){
      for(int i = 0; i < NUM_LEDS; i++ ) {
        CRGB color = CHSV((i + offset) % 255,255,255);
        leds[i] = color;
      }
      FastLED.show();
      delay(1000);
    }  
}
