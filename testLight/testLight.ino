#include <Adafruit_NeoPixel.h>

#define PIN 6

// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(36, PIN, NEO_GRB + NEO_KHZ800);

// IMPORTANT: To reduce NeoPixel burnout risk, add 1000 uF capacitor across
// pixel power leads, add 300 - 500 Ohm resistor on first pixel's data input
// and minimize distance between Arduino and first pixel.  Avoid connecting
// on a live circuit...if you must, connect GND first.

int address[8] = {0,1,0,1,0,1,0,1};

void setup() {
  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
#if defined (__AVR_ATtiny85__)
  if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
#endif
  // End of trinket special code


  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}

int bitSize = 4;
int offSet = 2;

void loop() {

    for(int i = 0; i < 2 ; i ++){
      strip.setPixelColor(i, strip.Color(0, 0, 255));
    }
    for(int i = 34; i < 36 ; i ++){
      strip.setPixelColor(i, strip.Color(0, 0, 255));
    }
    for(int i = 0; i < 8; i++){
      if(address[i] == 1){
        for(int j = 0; j < bitSize; j++){
          if(j == 0 || j == bitSize - 1){
            strip.setPixelColor(bitSize*i + j + offSet, strip.Color(0, 0, 0));
          }
          else{
            strip.setPixelColor(bitSize*i + j + offSet, strip.Color(255, 0, 0));
          }
        }
      }
      else{
        for(int j = 0; j < bitSize; j++){
          if(j == 0 || j == bitSize - 1){
            strip.setPixelColor(bitSize*i + j + offSet, strip.Color(0, 0, 0));
          }
          else{
            strip.setPixelColor(bitSize*i + j + offSet, strip.Color(0, 255, 0));
          }
        }
      }  
    }
 
   strip.show();


}
