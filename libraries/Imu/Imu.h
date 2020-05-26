#ifndef Imu_h
#define Imu_h

#include <SimpleUtils.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_FXOS8700.h>
#include <Adafruit_FXAS21002C.h>

class Imu
{
	public:
		Imu();
		bool begin();
		bool update();

		bool getAccelerometer(SimpleUtils::AxisData& accel);
        bool getGyroscope(SimpleUtils::AxisData& gyro);
        bool getMagnetometer(SimpleUtils::AxisData& mag);
	private:
		Adafruit_FXAS21002C gyroscope_ = Adafruit_FXAS21002C(0x0021002C);
        Adafruit_FXOS8700 accelerometer_magnetometer_ = Adafruit_FXOS8700(0x8700A, 0x8700B);

        sensors_event_t gyroscope_data_;
        sensors_event_t accelerometer_data_;
        sensors_event_t magnetometer_data_;
};

#endif