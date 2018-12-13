#include <FastLED.h>
#define PIN 6
#define NUM_LEDS 300
CRGB leds[NUM_LEDS];

void setup() {
  // put your setup code here, to run once:
 FastLED.addLeds<WS2811, PIN, RGB>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
  setAll(0,0,0);
}

// don't change below here

void showStrip() {
 #ifdef ADAFRUIT_NEOPIXEL_H 
   // NeoPixel
   strip.show();
 #endif
 #ifndef ADAFRUIT_NEOPIXEL_H
   // FastLED
   FastLED.show();
 #endif
}

void setPixel(int Pixel, byte red, byte green, byte blue) {
 #ifdef ADAFRUIT_NEOPIXEL_H 
   // NeoPixel
   strip.setPixelColor(Pixel, strip.Color(red, green, blue));
 #endif
 #ifndef ADAFRUIT_NEOPIXEL_H 
   // FastLED
   leds[Pixel].r = red;
   leds[Pixel].g = green;
   leds[Pixel].b = blue;
 #endif
}

void setAll(byte red, byte green, byte blue) {
  for(int i = 0; i < NUM_LEDS; i++ ) {
    setPixel(i, red, green, blue); 
  }
  showStrip();
}

void loop() {
  for(int offset = 0; offset <= 5; offset++){
    for(int i = 0; i < NUM_LEDS; i++ ) {
      switch( (i + offset) % 6) {
        case 0: // blue
          setPixel(i, 0, 0, 255); 
          break;
        case 1: // red
          setPixel(i, 255, 0, 0); 
          break;
        case 2: //cyan
          setPixel(i, 0, 255, 255); 
          break;
        case 3: // green
          setPixel(i, 0, 255, 0); 
          break;
        case 4: // yellow
          setPixel(i, 255, 255, 0); 
          break;
        case 5: // magenta
          setPixel(i, 255, 0, 255); 
          break;
      }
    }
    showStrip();
    delay(15000);
    // fade to next
    int colorOffset;
    for (int c = 0 ; c <= 51; c ++){
      colorOffset = c * 5;
      for(int k = 0; k < NUM_LEDS; k++ ) {
        switch( (k + offset) % 6) {
          case 0: // blue to red
            setPixel(k, colorOffset, 0, 255 - colorOffset); 
            break;
          case 1: // red to cyan
            setPixel(k, 255 - colorOffset, colorOffset, colorOffset); 
            break;
          case 2: // cyan to green
            setPixel(k, 0, 255, 255 - colorOffset); 
            break;
          case 3: // green to yellow
            setPixel(k, colorOffset, 255,0); 
            break;
          case 4: // yellow to magenta
            setPixel(k, 255, 255 - colorOffset, colorOffset); 
            break;
          case 5: // magenta to blue
            setPixel(k, 255- colorOffset, 0, 255); 
            break;
        }
      }
      showStrip();
    }
    // end fade
  }
}
