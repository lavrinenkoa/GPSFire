#include <M5Stack.h>

#define DBG_FILE_TXT       "/debug.txt"
#define LCD_MAX_LOG_LINE   ( 20 )

int lcdLine=0;

void dbg(const char* format, ...)
{
    File logFile;
    char tmp[1024*2];
    va_list argptr;
    va_start(argptr, format);
    vsprintf(tmp, format, argptr);
    va_end(argptr);

    if ( lcdLine%LCD_MAX_LOG_LINE == 0 )
    {
        M5.Lcd.clear();
        M5.Lcd.setCursor(0, 0);
    }
    lcdLine++;

    Serial.printf(tmp);
    M5.Lcd.printf(tmp);
    logFile = SD.open(DBG_FILE_TXT, "a+");
    logFile.printf(tmp);
    logFile.flush();
    logFile.close();
}

void dbg_serial(const char* format, ...)
{
    char tmp[1024*2];
    va_list argptr;
    va_start(argptr, format);
    vsprintf(tmp, format, argptr);
    va_end(argptr);

    if ( lcdLine%LCD_MAX_LOG_LINE == 0 )
    {
        M5.Lcd.clear();
        M5.Lcd.setCursor(0, 0);
    }
    lcdLine++;

    Serial.printf(tmp);
}


