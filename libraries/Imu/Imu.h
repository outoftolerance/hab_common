#ifndef Imu_h
#define Imu_h

/**
 * @brief      Defines different IMU boards supported
 */
enum IMU_TYPES {
	IMU_TYPE_ADAFRUIT_10DOF = 0,
	IMU_TYPE_ADAFRUIT_9DOF
};

class Imu
{
	public:
		virtual bool begin();
		virtual bool update();

		virtual float getRoll();
		virtual float getPitch();
		virtual float getHeading();
		virtual float getTemperature();
		virtual float getPressure();
		virtual float getBarometricAltitude();
};

#endif