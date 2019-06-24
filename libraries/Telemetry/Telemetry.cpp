#include "Telemetry.h"

/*------------------------------Constructor Methods------------------------------*/
Telemetry::Telemetry(IMU_TYPES imu_type)
{
	gps_serial_ = NULL;
	gps_fix_status_ = false;

	switch(imu_type)
	{
		case IMU_TYPES::IMU_TYPE_ADAFRUIT_10DOF:
			imu_ = new Imu_10dof();
			break;
		case IMU_TYPES::IMU_TYPE_ADAFRUIT_9DOF:
			imu_ = new Imu_9dof();
			break;
	}
}

Telemetry::Telemetry(IMU_TYPES imu_type, Stream* gps_serial, int gps_fix_pin) :
	gps_serial_(gps_serial),
	gps_fix_pin_(gps_fix_pin)
{
	gps_serial_buffer_ = new Buffer(GPS_SERIAL_BUFFER_SIZE);
	gps_fix_status_ = false;
}

/*------------------------------Private Methods------------------------------*/

void Telemetry::update_()
{
	if(gps_serial_ != NULL)
	{
		char c;

		while(gps_serial_->available())
		{
			c = gps_serial_->read();
			gps_.encode(c);
			gps_serial_buffer_->push(c);
		}

		gps_fix_status_ = digitalRead(gps_fix_pin_);
	}

	imu_.update();
}

/*------------------------------Public Methods------------------------------*/

bool Telemetry::init()
{
	//Initialise the GPS
	if(gps_serial_ != NULL)
	{
		static_cast<HardwareSerial&>(*gps_serial_).begin(GPS_SERIAL_BAUD);
	}

	//Initialise each sensor
	if(!imu.begin())
	{
		return false;
	}

	//Everything initialized correctly
	return true;
}

bool Telemetry::get(TelemetryStruct& telemetry)
{
	//Update all sensor data
	update_();

	//Assign to output struct
	if(gps_serial_ != NULL)
	{
		telemetry.latitude = (float)gps_.location.lat();
		telemetry.longitude = (float)gps_.location.lng();
		telemetry.altitude = (float)gps_.altitude.meters();		
		telemetry.course = (float)gps_.course.deg();
	}
	else
	{
		telemetry.latitude = 0;
		telemetry.longitude = 0;
		telemetry.altitude = 0;
		telemetry.course = 0;
	}
	
	telemetry.altitude_barometric = imu_.getBarometricAltitude();
	telemetry.roll = imu_.getRoll();
	telemetry.pitch = imu_.getPitch();
	telemetry.heading = imu_.getHeading();
	telemetry.temperature = imu_.getTemperature();
	telemetry.pressure = imu_.getPressure();

	return true;
}

bool Telemetry::getAccelerometerRaw(AxisData& accelerometer)
{
	return false;
}

bool Telemetry::getGyroscopeRaw(AxisData& gyroscope)
{
	return false;
}

bool Telemetry::getMagnetometerRaw(AxisData& magnetometer)
{
	return false;
}

bool Telemetry::getBarometerRaw(float& data)
{
	return false;
}

int Telemetry::getGpsString(char string[])
{
	int i = 0;

	if(gps_serial_ != NULL)
	{
		while(gps_serial_buffer_->available())
		{
			string[i] = gps_serial_buffer_->pop();
			i++;
		}
	}

	return i;
}

bool Telemetry::getGpsFixStatus()
{
	return gps_fix_status_;
}

float Telemetry::getGpsHdop()
{
	if(gps_serial_ != NULL)
	{
		return (float)gps_.hdop.hdop();
	}
	else
	{
		return 0;
	}
}

long Telemetry::getGpsDateTime()
{
	return 0;
}