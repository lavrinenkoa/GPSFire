#include "mygps.h"

#ifdef GPSATOM

CRGB led(0, 0, 0);

// static bool red_st=  false;
// static bool green_st=false;
static bool blue_st= false;
// static bool white_st=false;

void red()
{
    if (blue_st) return;
    led = CRGB(0,255,0);
    M5.dis.drawpix(0, led);
}

void green()
{
    if (blue_st) return;
    led = CRGB(255,0,0);
    M5.dis.drawpix(0, led);
}

void blue()
{
    led = CRGB(0,0,255);
    M5.dis.drawpix(0, led);
}

void blue_on()
{
    blue_st = true;
    led = CRGB(0,0,255);
    M5.dis.drawpix(0, led);
}

void blue_off()
{
    blue_st = false;
    led = CRGB(0,0,0);
    M5.dis.drawpix(0, led);
}

void white()
{
    if (blue_st) return;
    led = CRGB(255,255,255);
    M5.dis.drawpix(0, led);
}
#else
#include <Adafruit_NeoPixel.h>

#define M5STACK_FIRE_NEO_NUM_LEDS 10
#define M5STACK_FIRE_NEO_DATA_PIN 15

extern Adafruit_NeoPixel pixels;

static bool blue_st= false;

void red(){};
void green(){};
void blue(){};
void white()
{
    // if (blue_st) return;
    // pixels.setPixelColor(1, pixels.Color(255, 255, 255));     
    // pixels.show();    
};
void blue_on()
{
    // blue_st = true;
    // pixels.setPixelColor(1, pixels.Color(0, 0, 255));     
    // pixels.show();
};
void blue_off()
{
    // blue_st = false;
    // pixels.setPixelColor(1, pixels.Color(0, 0, 0));     
    // pixels.show();    
};
#endif