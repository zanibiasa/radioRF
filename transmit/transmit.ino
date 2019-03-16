

#include <RH_ASK.h>
#include <SPI.h> // Not actually used but needed to compile

RH_ASK driver;
int b =1;
int c[5];
//char baf[30];
unsigned long start, habis, beza;
int resistor;
int resistorLen;
void setup()
{
    Serial.begin(9600);   // Debugging only
    if (!driver.init())
         Serial.println("init failed");
         
}

void loop()
{
	resistor = analogRead(A0);
    resistorLen = sizeof(resistor);
    start = millis();
    //sprintf(baf,"%d",b);
    driver.send((uint8_t *) &resistor, resistorLen);
    driver.waitPacketSent();
    //delay(5);
    
    delay(2);
    
    Serial.println(resistor);
}
