#ifndef SIMPLESERVO_H
#define SIMPLESERVO_H

#include <Timer.h>
#include <Adafruit_PWMServoDriver.h>

#define DEFAULT_STEP_SIZE 1
#define DEFAULT_UPDATE_DELAY 25

#define SERVO_PWM_FREQUENCY 60

class SimpleServo {
	public:
		SimpleServo(int min_pwm, int max_pwm, int servo_channel_, Adafruit_PWMServoDriver* servo_driver);
		bool update();
		float getCurrentAngle();
		float getTargetAngle();
		bool setTargetAngle(float angle);
		bool setStepSize(int size);
		bool setUpdateRate(int delay);
	private:
		int calculateMovement_();

		int min_pwm_;
		int max_pwm_;
		int servo_channel_;

		Timer update_timer_;
		Adafruit_PWMServoDriver* driver_;

		float target_angle_;
		float current_angle_;

		int target_pwm_;
		int current_pwm_;
		int step_size_;
		int update_delay_;
};

#endif