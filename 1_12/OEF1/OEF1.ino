#include <Wire.h>
#include <TTSTime.h>
#include <Streaming.h>

TTSTime time;

int hour = 0;
int minu = 0;
int sec = 0;
bool flag = false;

void setup()
{
    Serial.begin(115200);
    Wire.begin();
    Serial.write("hello world\n");   
    time.setTime(11,59,55);
}
void loop()
{
    Serial.print(hour, DEC);
    Serial.print(" : ");
    Serial.print(minu, DEC);
    Serial.print(" : ");
    Serial.println(sec, DEC);
    delay(1000);
}
