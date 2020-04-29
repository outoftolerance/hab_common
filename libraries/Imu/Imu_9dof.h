#ifndef Imu_9dof_h
#define Imu_9dof_h

#include <Wire.h>
#include <Imu.h>
#include <Madgwick.h>
#include <Mahony.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_FXOS8700.h>
#include <Adafruit_FXAS21002C.h>
#include <Mahony.h>

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
        Mahony* ahrs_filter_;

        //Calibration parameters
        float mag_offsets_[3]            = { 0.93F, -7.47F, -35.23F };      /*< Offsets applied to raw x/y/z mag values */
        float mag_softiron_matrix_[3][3] = { {  0.986,  -0.035,  0.032 },
                                             {  -0.035,  0.907,  0.037 },
                                             {  0.032,   0.037,  1.122 } }; /*< Soft iron error compensation matrix */
        float mag_field_strength_        = 44.43F;                          /*< Strength of magnetic field recorded */
        float gyro_zero_offsets_[3]      = { 0.0F, 0.0F, 0.0F };            /*< Offsets applied to compensate for gyro zero-drift error for x/y/z */
};

#endif