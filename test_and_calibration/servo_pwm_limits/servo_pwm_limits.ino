#include <Adafruit_PWMServoDriver.h>

#define SERVO_ADDRESS 1

#define SERVO_PWM_FREQUENCY 60  // Analog servos run at ~60 Hz updates

Adafruit_PWMServoDriver servo_driver = Adafruit_PWMServoDriver();    /**< Adafruit servo driver object */

int pwm_output;

void setup()
{
	Serial.begin(57600);

	servo_driver.begin();
    servo_driver.setPWMFreq(SERVO_PWM_FREQUENCY);

    pwm_output = 200;
}

void loop()
{
	Serial.println(pwm_output);
	servo_driver.setPWM(SERVO_ADDRESS, 0, pwm_output);
	//pwm_output += 10;
	delay(2000);
}