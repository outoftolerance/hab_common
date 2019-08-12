#include "Imu_10dof.h"

Imu_10dof::Imu_10dof()
{

}

bool Imu_10dof::begin()
{
	//Initialise each sensor
	if(!accelerometer_.begin())
	{
		return false;
	}

	if(!magnetometer_.begin())
	{
		return false;
	}

	if(!barometer_.begin())
	{
		return false;
	}

	//Everything initialized correctly
	return true;
}

bool Imu_10dof::update()
{
	accelerometer_.getEvent(&accelerometer_data_);
	//gyroscope_.getEvent(&gyroscope_data_);
	magnetometer_.getEvent(&magnetometer_data_);
	barometer_.getEvent(&barometer_data_);

	//Calculate attitude from accelerometer
	if (!sensor_board_.accelGetOrientation(&accelerometer_data_, &orientation_))
	{
		return false;
	}

	//Correct magnetometer values based on tilt
	if (!sensor_board_.magTiltCompensation(SENSOR_AXIS_Z, &magnetometer_data_, &accelerometer_data_))
	{
	  return false;
	}

	//Calculate heading from magnetometer
	if (!sensor_board_.magGetOrientation(SENSOR_AXIS_Z, &magnetometer_data_, &orientation_))
	{
		return false;
	}

	//Calculate altitude from barometer
	if (!barometer_data_.pressure)
	{
		return false;
	}

	//Get ambient temperature in C
	barometer_.getTemperature(&temperature_);

	//Convert atmospheric pressure, SLP and temp to altitude
	altitude_barometric_ = barometer_.pressureToAltitude((float)SENSORS_PRESSURE_SEALEVELHPA, barometer_data_.pressure, temperature_);

	return true;
}

float Imu_10dof::getRoll()
{
	return orientation_.roll;
}

float Imu_10dof::getPitch()
{
	return	orientation_.pitch;
}

float Imu_10dof::getHeading()
{
	return orientation_.heading;	
}

float Imu_10dof::getTemperature()
{
	return temperature_;
}

float Imu_10dof::getPressure()
{
	return barometer_data_.pressure;
}

float Imu_10dof::getBarometricAltitude()
{
	return altitude_barometric_;
}