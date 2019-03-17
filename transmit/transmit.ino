

#include <RH_ASK.h>
#include <SPI.h> // Not actually used but needed to compile

RH_ASK driver;
int b =1;
int c[5];
//char baf[30];
unsigned long start, habis, beza;
int resistor1;
int resistor2;
int resistorArray[];
void setup()
{
    Serial.begin(9600);   // Debugging only
    if (!driver.init())
         Serial.println("init failed");
         
}

void loop()
{
	resistor1 = analogRead(A0);
    resistor2 = analogRead(A1);
    resistorArray[0] = resistor1;
    resistorArray[2] = resistor2;
    
    start = millis();
    //sprintf(baf,"%d",b);
    driver.send((uint8_t *) &resistor, 4);
    driver.waitPacketSent();
    //delay(5);
    
    delay(2);
    
    Serial.println(resistor);
}
