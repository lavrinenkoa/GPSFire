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
// #include <Adafruit_NeoPixel.h>
// #define M5STACK_FIRE_NEO_NUM_LEDS 10
// #define M5STACK_FIRE_NEO_DATA_PIN 15
// extern Adafruit_NeoPixel pixels;

extern SemaphoreHandle_t LCDSemaphore;

static bool blue_st= false;
bool skipp = false;

void red()
{
    if (skipp) return;
    if (blue_st) return;
    if ( xSemaphoreTake( LCDSemaphore, ( TickType_t ) 50 ) == pdTRUE ){
    M5.Lcd.fillRect(0, M5.Lcd.height()-20, M5.Lcd.width(), 20, RED);
    xSemaphoreGive(LCDSemaphore);
    }
};
void green()
{
    if (skipp) return;
    if (blue_st) return;
    if ( xSemaphoreTake( LCDSemaphore, ( TickType_t ) 50 ) == pdTRUE ){
    M5.Lcd.fillRect(0, M5.Lcd.height()-20, M5.Lcd.width(), 20, GREEN);
    xSemaphoreGive(LCDSemaphore);
    }

};
void blue()
{
    if (skipp) return;
    blue_st = true;
    if ( xSemaphoreTake( LCDSemaphore, ( TickType_t ) 50 ) == pdTRUE ){
    M5.Lcd.fillRect(0, M5.Lcd.height()-20, M5.Lcd.width(), 20, BLUE);
    xSemaphoreGive(LCDSemaphore);
    }
};
void white()
{
    if (skipp) return;
    if (blue_st) return;
    if ( xSemaphoreTake( LCDSemaphore, ( TickType_t ) 50 ) == pdTRUE ){
    M5.Lcd.fillRect(0, M5.Lcd.height()-20, M5.Lcd.width(), 20, WHITE);
    xSemaphoreGive(LCDSemaphore);
    }
};
void blue_on()
{
    if (skipp) return;
    blue_st = true;
    if ( xSemaphoreTake( LCDSemaphore, ( TickType_t ) 50 ) == pdTRUE ){
    M5.Lcd.fillRect(0, M5.Lcd.height()-20, M5.Lcd.width(), 20, BLUE);
    xSemaphoreGive(LCDSemaphore);
    }
};
void blue_off(bool st=false)
{
    if (skipp) return;
    blue_st = st;
    if ( xSemaphoreTake( LCDSemaphore, ( TickType_t ) 50 ) == pdTRUE ){
    M5.Lcd.fillRect(0, M5.Lcd.height()-20, M5.Lcd.width(), 20, BLACK);
    xSemaphoreGive(LCDSemaphore);
    }
};
#endif