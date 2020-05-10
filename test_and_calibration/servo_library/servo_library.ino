#include <SimpleServo.h>
#include <Adafruit_PWMServoDriver.h>

#define PAN_SERVO_CHANNEL 5
#define TILT_SERVO_CHANNEL 4

#define PAN_SERVO_PWM_MIN  150  // this is the 'minimum' pulse length count (out of 4096) Left
#define PAN_SERVO_PWM_MAX  600  // this is the 'maximum' pulse length count (out of 4096) Right
#define TILT_SERVO_PWM_MIN  260 // Vertical
#define TILT_SERVO_PWM_MAX  470 // Horizontal

Adafruit_PWMServoDriver driver = Adafruit_PWMServoDriver();

SimpleServo pan_servo(PAN_SERVO_PWM_MIN, PAN_SERVO_PWM_MAX, PAN_SERVO_CHANNEL, &driver);
SimpleServo tilt_servo(TILT_SERVO_PWM_MAX, TILT_SERVO_PWM_MIN, TILT_SERVO_CHANNEL, &driver);

void setup()
{
	Serial.begin(115200);

	driver.begin();
	driver.setPWMFreq(60);

	while(!Serial){}

	tilt_servo.init();
	
}

void loop()
{
	tilt_servo.start();

	while(1)
	{
		tilt_servo.setTargetAngle(30);
    	tilt_servo.move();
	}
}