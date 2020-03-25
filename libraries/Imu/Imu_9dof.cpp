#include "Imu_9dof.h"

Imu_9dof::Imu_9dof()
{
	ahrs_ = new Adafruit_Simple_AHRS(&accelerometer_magnetometer_, &accelerometer_magnetometer_);
}

bool Imu_9dof::begin()
{
	//Start gyroscope
	if(!gyroscope_.begin())
	{
		return false;
	}

	//Start accel and mag
	if(!accelerometer_magnetometer_.begin(ACCEL_RANGE_4G))
	{
		return false;
	}

	return true;
}

bool Imu_9dof::update()
{
	return true;
}

float Imu_9dof::getRoll()
{
	sensors_vec_t orientation;
	ahrs_->getOrientation(&orientation);
	return orientation.roll;
}

float Imu_9dof::getPitch()
{
	sensors_vec_t orientation;
	ahrs_->getOrientation(&orientation);
	return orientation.pitch;
}

float Imu_9dof::getHeading()
{
	sensors_vec_t orientation;
	ahrs_->getOrientation(&orientation);
	return orientation.heading;
}

float Imu_9dof::getTemperature()
{
	return 0;
}

float Imu_9dof::getPressure()
{
	return 0;
}

float Imu_9dof::getBarometricAltitude()
{
	return 0;
}