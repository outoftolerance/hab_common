#ifndef Imu_10dof_h
#define Imu_10dof_h

#include <Wire.h>
#include <Imu.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_LSM303_U.h>
#include <Adafruit_BMP085_U.h>
#include <Adafruit_L3GD20_U.h>
#include <Adafruit_10DOF.h>

class Imu_10dof : public Imu
{
	public:
		Imu_10dof();
		~Imu_10dof();

		bool begin() override;
		bool update() override;

		float getRoll() override;
		float getPitch() override;
		float getHeading() override;
		float getTemperature() override;
		float getPressure() override;
		float getBarometricAltitude() override;
	private:
		Adafruit_10DOF sensor_board_ = Adafruit_10DOF(); 										/**< 10 degree of freedom sensor board */
		Adafruit_LSM303_Accel_Unified accelerometer_ = Adafruit_LSM303_Accel_Unified(30301); 	/**< accelerometer/gyroscope private object */
		Adafruit_LSM303_Mag_Unified magnetometer_ = Adafruit_LSM303_Mag_Unified(30302); 		/**< magnetometer private object */
		Adafruit_BMP085_Unified barometer_ = Adafruit_BMP085_Unified(18001); 					/**< barometer private object */

		sensors_event_t accelerometer_data_; 	/**< Struct for latest accelerometer data */
		//sensors_event_t gyroscope_data_;		/**< Struct for latest gyroscope data */
		sensors_event_t magnetometer_data_; 	/**< Struct for latest magenetometer data */
		sensors_event_t barometer_data_; 		/**< Struct for latest barometer data */
		sensors_vec_t orientation_; 			/**< Orientation struct needed by Adafruit sensor library for some functions */

		float altitude_barometric_;
		float temperature_;
};

#endif