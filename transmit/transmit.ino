

#include <RH_ASK.h>
#include <SPI.h> // Not actually used but needed to compile

RH_ASK driver;
int b =1;
int c[5];
//char baf[30];
unsigned long start, habis, beza;
int resistor;
void setup()
{
    Serial.begin(9600);   // Debugging only
    if (!driver.init())
         Serial.println("init failed");
         
}

void loop()
{
	resistor 
    c[0]= b;
    c[1]= b+1;
    c[2]= b+2;
    c[3]= b+3;
    c[4]= b+4;
    start = millis();
    //sprintf(baf,"%d",b);
    driver.send((uint8_t *) &c, 10);
    driver.waitPacketSent();
    //delay(5);
    b++;
    delay(400);
    //Serial.println(baf);
    habis = millis();
    beza = habis - start;
    Serial.println(habis);
    //Serial.println(c);
}


