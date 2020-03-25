#ifndef Imu_9dof_h
#define Imu_9dof_h

#include <Wire.h>
#include <Imu.h>
#include <Madgwick.h>
#include <Mahony.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_FXOS8700.h>
#include <Adafruit_FXAS21002C.h>
#include <Adafruit_Simple_AHRS.h>

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

		//AHRS;
		Adafruit_Simple_AHRS* ahrs_;
};

#endif