#ifndef Imu_9dof_h
#define Imu_9dof_h

#include <Wire.h>
#include <Imu.h>
#include <Madgwick.h>
#include <Mahony.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_FXOS8700.h>
#include <Adafruit_FXAS21002C.h>

class Imu_9dof : public Imu
{
	public:
		Imu_9dof();
		~Imu_9dof();

		bool begin() override;
		bool update() override;

		float getRoll() override;
		float getPitch() override;
		float getHeading() override;
		float getTemperature() override;
		float getPressure() override;
		float getBarometricAltitude() override;
	private:
		Adafruit_FXAS21002C gyroscope_ = Adafruit_FXAS21002C(0x0021002C);
		Adafruit_FXOS8700 accelerometer_magnetometer_ = Adafruit_FXOS8700(0x8700A, 0x8700B);

		sensors_event_t gyroscope_data_;
		sensors_event_t accelerometer_data_;
		sensors_event_t magnetometer_data_;

		//Mahony ahrs_filter_;
		Madgwick ahrs_filter_;

		// Offsets applied to raw x/y/z mag values
		float mag_offsets_[3] = { 0.93F, -7.47F, -35.23F };

		// Soft iron error compensation matrix
		float mag_softiron_matrix_[3][3] = { {  0.943,  0.011,  0.020 },
		                                     {  0.022,  0.918, -0.008 },
		                                     {  0.020, -0.008,  1.156 } };

		// Offsets applied to compensate for gyro zero-drift error for x/y/z
		float gyro_zero_offsets_[3] = { 0.0F, 0.0F, 0.0F };
};

#endif