#include "Imu_9dof.h"

Imu_9dof::Imu_9dof()
{

}

bool Imu_9dof::begin()
{
	//Start gyroscope
	if!(gyroscope_.begin())
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
	gyroscope_.getEvent(&gyroscope_data_);
	accelerometer_magnetometer_.getEvent(&accelerometer_data_, &magnetometer_data_);

	// Apply mag offset compensation (base values in uTesla)
	float x = magnetometer_data_.magnetic.x - mag_offsets_[0];
	float y = magnetometer_data_.magnetic.y - mag_offsets_[1];
	float z = magnetometer_data_.magnetic.z - mag_offsets_[2];

	// Apply mag soft iron error compensation
	float mx = x * mag_softiron_matrix_[0][0] + y * mag_softiron_matrix_[0][1] + z * mag_softiron_matrix_[0][2];
	float my = x * mag_softiron_matrix_[1][0] + y * mag_softiron_matrix_[1][1] + z * mag_softiron_matrix_[1][2];
	float mz = x * mag_softiron_matrix_[2][0] + y * mag_softiron_matrix_[2][1] + z * mag_softiron_matrix_[2][2];

	// Apply gyro zero-rate error compensation
	float gx = gyroscope_data_.gyro.x + gyro_zero_offsets_[0];
	float gy = gyroscope_data_.gyro.y + gyro_zero_offsets_[1];
	float gz = gyroscope_data_.gyro.z + gyro_zero_offsets_[2];

	// The filter library expects gyro data in degrees/s, but adafruit sensor
	// uses rad/s so we need to convert them first (or adapt the filter lib
	// where they are being converted)
	gx *= 57.2958F;
	gy *= 57.2958F;
	gz *= 57.2958F;

	// Update the filter
	ahrs_filter_.update(gx, gy, gz,
	            		accelerometer_data_.acceleration.x, accelerometer_data_.acceleration.y, accelerometer_data_.acceleration.z,
	            		mx, my, mz);

	return true;
}

float Imu_9dof::getRoll()
{
	return ahrs_filter_.getRoll();
}

float Imu_9dof::getPitch()
{
	return ahrs_filter_.getPitch();
}

float Imu_9dof::getHeading()
{
	return ahrs_filter_.getYaw();
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