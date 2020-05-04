#include <Servo.h>

Servo indicator_led;

void setup()
{
	pinMode(12, OUTPUT);
	indicator_led.attach(12);
}

void loop()
{
	indicator_led.writeMicroseconds(2000);
	delay(5000);
	indicator_led.writeMicroseconds(1000);
	delay(5000);
}