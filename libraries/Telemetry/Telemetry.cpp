#include "Telemetry.h"

/*------------------------------Constructor Methods------------------------------*/
Telemetry::Telemetry(IMU_TYPES imu_type)
{
    gps_serial_ = NULL;
    gps_fix_status_ = false;
    altitude_base_is_set_ = false;
    altitude_base_ = 0;

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
    switch(imu_type)
    {
        case IMU_TYPES::IMU_TYPE_ADAFRUIT_10DOF:
            imu_ = new Imu_10dof();
            break;
        case IMU_TYPES::IMU_TYPE_ADAFRUIT_9DOF:
            imu_ = new Imu_9dof();
            break;
    }
    
    gps_serial_buffer_ = new Buffer(GPS_SERIAL_BUFFER_SIZE);
    gps_fix_status_ = false;
    altitude_base_is_set_ = false;
    altitude_base_ = 0;
}

/*------------------------------Private Methods------------------------------*/

void Telemetry::update_()
{
    imu_->update();

    if(gps_serial_ != NULL)
    {
        char c;

        while(gps_serial_->available())
        {
            c = gps_serial_->read();
            gps_.encode(c);
            gps_serial_buffer_->push(c);
        }

        //Detect for first transition of GPS fix
        if(!gps_fix_status_ && digitalRead(gps_fix_pin_) && !altitude_base_is_set_)
        {
            altitude_base_ = (float)gps_.altitude.meters();
            altitude_base_is_set_ = true;
        }
    }
    else if(!altitude_base_is_set_)
    {
        altitude_base_ = imu_->getBarometricAltitude();
        altitude_base_is_set_ = true;
    }
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
    if(!imu_->begin())
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

    //Grab data not dependent on GPS
    telemetry.altitude_barometric.value = imu_->getBarometricAltitude();
    telemetry.roll.value = imu_->getRoll();
    telemetry.pitch.value = imu_->getPitch();
    telemetry.heading.value = imu_->getHeading();
    telemetry.temperature.value = imu_->getTemperature();
    telemetry.pressure.value = imu_->getPressure();

    //Assign to output struct
    if(gps_serial_ != NULL)
    {
        telemetry.latitude.value = (float)gps_.location.lat();
        telemetry.longitude.value = (float)gps_.location.lng();
        telemetry.altitude.value = (float)gps_.altitude.meters();
        telemetry.course.value = (float)gps_.course.deg();
        telemetry.velocity_vertical.value = (float)gps_.speed.mps();
        telemetry.velocity_horizontal.value = 0.0;

        if(altitude_base_is_set_)
        {
            telemetry.altitude_relative.value = telemetry.altitude.value - altitude_base_;
        }
        else
        {
            telemetry.altitude_relative.value = 0.0;
        }
    }
    else
    {
        telemetry.latitude.value = 0.0;
        telemetry.longitude.value = 0.0;
        telemetry.altitude.value = 0.0;
        telemetry.course.value = 0.0;
        telemetry.velocity_vertical.value = 0.0;
        telemetry.velocity_horizontal.value = 0.0;

        if(altitude_base_is_set_)
        {
            telemetry.altitude_relative.value = telemetry.altitude_barometric.value - altitude_base_;
        }
        else
        {
            telemetry.altitude_relative.value = 0;
        }
    }

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

bool Telemetry::resetBaseAltitude()
{
    if(gps_serial_ != NULL)
    {
        altitude_base_ = gps_.altitude.meters();
    }
    else
    {
        altitude_base_ = imu_->getBarometricAltitude();   
    }

    return true;
}