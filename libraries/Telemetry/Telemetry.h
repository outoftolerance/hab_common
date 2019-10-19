#ifndef Telemetry_h
#define Telemetry_h

#include <Buffer.h>
#include <Wire.h>
#include <TinyGPS++.h>
#include <Imu.h>
#include <Imu_9dof.h>
#include <Imu_10dof.h>

#define GPS_SERIAL_BAUD 9600
#define GPS_SERIAL_BUFFER_SIZE 64

/**
 * @brief Structure for axis related data (e.g. acceleration, velocity, gyro, mag, etc...)
 */
typedef struct AxisData
{
    float x;
    float y;
    float z;
} AxisData;

/**
 * @brief Structure for complete telemetry output.
 */
typedef struct TelemetryStruct
{
    float latitude;             /**< Latitude in decimal degrees */
    float longitude;            /**< Longitude in decimal degrees */
    float altitude;             /**< Altitude in meters from GPS */
    float altitude_barometric;  /**< Altitude in meters from barometer */
    float velocity_horizontal;  /**< Velocity horizontally along course vector */
    float velocity_vertical;    /**< Velocity vertically */
    float roll;                 /**< Roll in radians */
    float pitch;                /**< Pitch in radians */
    float heading;              /**< Magnetic heading in degrees */
    float course;               /**< Direction of travel in degrees */
    float temperature;          /**< Temperature in degrees C */
    float pressure;             /**< Pressure in pascals */
} TelemetryStruct;

/**
 * @brief      Telemetry class definition. Class interacts with all sensors and gives access to sensor data in a useful way
 */
class Telemetry
{
    public:
        /*
         * @brief      Telemetry class constructor without GPS
         */
        Telemetry(IMU_TYPES imu_type);

        /**
         * @brief      Telemetry class constructor with GPS
         * @param      imu_type The type of IMU connected
         * @param      gps_stream  Pointer to the Stream object for the GPS serial port
         * @param      gps_fix_pin Pin number for the GPS fix status indicator
         */
        Telemetry(IMU_TYPES imu_type, Stream* gps_stream, int gps_fix_pin);

        /**
         * @brief      Initialises all variables and objects to their default value/state
         */
        bool init();

        /**
         * @brief      Returns current telemetry of system
         * @param      Pointer to variable to output data to
         * @return     Boolean success/fail indicator
         */
        bool get(TelemetryStruct& telemetry);

        /**
         * @brief      Gets raw accelerometer data
         * @param      Pointer to variable to output data to
         * @return     Boolean success/fail indicator
         */
        bool getAccelerometerRaw(AxisData& accelerometer);

        /**
         * @brief      Gets the raw gyroscope data
         * @param      Pointer to variable to output data to
         * @return     Boolean success/fail indicator
         */
        bool getGyroscopeRaw(AxisData& gyroscope);

        /**
         * @brief      Gets the raw magnetometer data
         * @param      Pointer to variable to output data to
         * @return     Boolean success/fail indicator
         */
        bool getMagnetometerRaw(AxisData& magnetometer);

        /**
         * @brief      Gets the raw barometer data
         * @param      Pointer to variable to output data to
         * @return     Boolean success/fail indicator
         */
        bool getBarometerRaw(float& data);

        /**
         * @brief      Gets the latest gps serial chars
         * @param      string  Pointer to the output string
         * @return     Number of chars returned
         */
        int getGpsString(char string[]);

        /**
         * @brief      Gets the gps fix status
         *
         * @return     The gps fix status, true if fix, false if not
         */
        bool getGpsFixStatus();

        /**
         * @brief      Returns the horizontal precision of the GPS
         *
         * @return     The gps hdop in meters floating point
         */
        float getGpsHdop();

        /**
         * @brief      Gets the date and time from GPS unit
         *
         * @return     The gps date time as seconds since unix epoch
         */
        long getGpsDateTime();

    private:
        /**
         * @brief      Updates all sensors
         */
        void update_();

        TinyGPSPlus gps_;                                   /**< Defines Tiny GPS object */
        Stream* gps_serial_;                                /**< Defines Stream object for GPS device serial port */
        Buffer* gps_serial_buffer_;                         /**< Buffer to store received GPS serial data in for sending out to other devices */
        int gps_fix_pin_;                                   /**< Pin that senses GPS fix status */
        bool gps_fix_status_;                               /**< Current fix status of the GPS unit */
        Imu* imu_;
};

#endif
