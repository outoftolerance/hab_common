#include "SimpleServo.h"

SimpleServo::SimpleServo(int min_pwm, int max_pwm, int servo_channel, Adafruit_PWMServoDriver* servo_driver)
{
	min_pwm_ = min_pwm;
	max_pwm_ = max_pwm;
	servo_channel_ = servo_channel;

	driver_ = servo_driver;

	target_angle_ = 0;
	step_size_ = DEFAULT_STEP_SIZE;
	update_delay_ = DEFAULT_UPDATE_DELAY;
}

float SimpleServo::getCurrentAngle()
{
	return current_angle_;
}

float SimpleServo::getTargetAngle()
{
	return target_angle_;
}

bool SimpleServo::setTargetAngle(float angle)
{
	target_angle_ = angle;
	target_pwm_ = map(angle, 0, 90, min_pwm_, max_pwm_);
	return true;
}

bool SimpleServo::setStepSize(int size)
{
	step_size_ = size;
	return true;
}

bool SimpleServo::setUpdateRate(int delay)
{
	update_delay_ = delay;
	bool result = update_timer_.setInterval(update_delay_);
	return result;
}

int SimpleServo::calculateMovement_()
{
    int output;

    if(target_pwm_ != current_pwm_)
    {
        if(target_pwm_ - current_pwm_ > step_size_)
        {
            output += step_size_;
        }
        else if(target_pwm_ - current_pwm_ < step_size_)
        {
            output -= step_size_;
        }
        else
        {
            output = target_pwm_;
        }
    }

    if(output > min_pwm_ && output < max_pwm_)
    {
    	return output;
    }
    else
    {
    	return current_pwm_;
    }
}

bool SimpleServo::update()
{
	if(update_timer_.check())
	{
	    current_pwm_ = calculateMovement_();
	    current_angle_ = map(current_pwm_, min_pwm_, max_pwm_, 0, 90);
	    
	    driver_->setPWM(servo_channel_, 0, current_pwm_);

	    update_timer_.reset();
	}
}