#define MESSAGE_REPORT_TELEMETRY_PAYLOAD_LENGTH 17
#define MESSAGE_REPORT_TELEMETRY_PAYLOAD_BYTE_LENGTH 68

typedef struct smpMessageReportTelemetry
{
    FloatUnion_t latitude;
    FloatUnion_t longitude;
    FloatUnion_t altitude;
    FloatUnion_t altitude_ellipsoid;
    FloatUnion_t altitude_relative;
    FloatUnion_t altitude_barometric;
    FloatUnion_t elevation;
    FloatUnion_t azimuth;
    FloatUnion_t gps_snr;
    FloatUnion_t velocity_horizontal;
    FloatUnion_t velocity_vertical;
    FloatUnion_t roll;
    FloatUnion_t pitch;
    FloatUnion_t heading;
    FloatUnion_t course;
    FloatUnion_t temperature;
    FloatUnion_t pressure;
};

static inline void smpMessageReportTelemetryEncode(uint8_t node_id, uint8_t node_type, smpMessageReportTelemetry& telemetry, hdlcMessage& message)
{
    message.node_id = node_id;
    message.node_type = node_type;
    message.command = MESSAGE_TYPES::MESSAGE_TYPE_REPORT_TELEMETRY;
    message.length = MESSAGE_REPORT_TELEMETRY_PAYLOAD_BYTE_LENGTH;

    int data_position = 0;
    int bytes = 0;

    for (bytes = 0; bytes < sizeof(telemetry.latitude.value); bytes++)
    {
        message.payload[data_position + bytes] = telemetry.latitude.bytes[bytes];
    }

    data_position += sizeof(telemetry.latitude.value);

    for (bytes = 0; bytes < sizeof(telemetry.longitude.value); bytes++)
    {
        message.payload[data_position + bytes] = telemetry.longitude.bytes[bytes];
    }

    data_position += sizeof(telemetry.longitude.value);

    for (bytes = 0; bytes < sizeof(telemetry.altitude.value); bytes++)
    {
        message.payload[data_position + bytes] = telemetry.altitude.bytes[bytes];
    }

    data_position += sizeof(telemetry.altitude.value);

    for (bytes = 0; bytes < sizeof(telemetry.altitude_ellipsoid.value); bytes++)
    {
        message.payload[data_position + bytes] = telemetry.altitude_ellipsoid.bytes[bytes];
    }

    data_position += sizeof(telemetry.altitude_ellipsoid.value);

    for (bytes = 0; bytes < sizeof(telemetry.altitude_relative.value); bytes++)
    {
        message.payload[data_position + bytes] = telemetry.altitude_relative.bytes[bytes];
    }

    data_position += sizeof(telemetry.altitude_relative.value);

    for (bytes = 0; bytes < sizeof(telemetry.altitude_barometric.value); bytes++)
    {
        message.payload[data_position + bytes] = telemetry.altitude_barometric.bytes[bytes];
    }

    data_position += sizeof(telemetry.altitude_barometric.value);

    for (bytes = 0; bytes < sizeof(telemetry.elevation.value); bytes++)
    {
        message.payload[data_position + bytes] = telemetry.elevation.bytes[bytes];
    }

    data_position += sizeof(telemetry.elevation.value);

    for (bytes = 0; bytes < sizeof(telemetry.azimuth.value); bytes++)
    {
        message.payload[data_position + bytes] = telemetry.azimuth.bytes[bytes];
    }

    data_position += sizeof(telemetry.azimuth.value);

    for (bytes = 0; bytes < sizeof(telemetry.gps_snr.value); bytes++)
    {
        message.payload[data_position + bytes] = telemetry.gps_snr.bytes[bytes];
    }

    data_position += sizeof(telemetry.gps_snr.value);

    for (bytes = 0; bytes < sizeof(telemetry.velocity_horizontal.value); bytes++)
    {
        message.payload[data_position + bytes] = telemetry.velocity_horizontal.bytes[bytes];
    }

    data_position += sizeof(telemetry.velocity_horizontal.value);

    for (bytes = 0; bytes < sizeof(telemetry.velocity_vertical.value); bytes++)
    {
        message.payload[data_position + bytes] = telemetry.velocity_vertical.bytes[bytes];
    }

    data_position += sizeof(telemetry.velocity_vertical.value);

    for (bytes = 0; bytes < sizeof(telemetry.roll.value); bytes++)
    {
        message.payload[data_position + bytes] = telemetry.roll.bytes[bytes];
    }

    data_position += sizeof(telemetry.roll.value);

    for (bytes = 0; bytes < sizeof(telemetry.pitch.value); bytes++)
    {
        message.payload[data_position + bytes] = telemetry.pitch.bytes[bytes];
    }

    data_position += sizeof(telemetry.pitch.value);

    for (bytes = 0; bytes < sizeof(telemetry.heading.value); bytes++)
    {
        message.payload[data_position + bytes] = telemetry.heading.bytes[bytes];
    }

    data_position += sizeof(telemetry.heading.value);

    for (bytes = 0; bytes < sizeof(telemetry.course.value); bytes++)
    {
        message.payload[data_position + bytes] = telemetry.course.bytes[bytes];
    }

    data_position += sizeof(telemetry.course.value);

    for (bytes = 0; bytes < sizeof(telemetry.temperature.value); bytes++)
    {
        message.payload[data_position + bytes] = telemetry.temperature.bytes[bytes];
    }

    data_position += sizeof(telemetry.temperature.value);

    for (bytes = 0; bytes < sizeof(telemetry.pressure.value); bytes++)
    {
        message.payload[data_position + bytes] = telemetry.pressure.bytes[bytes];
    }
}

static inline void smpMessageReportTelemetryDecode(hdlcMessage& message, smpMessageReportTelemetry& telemetry)
{
    int data_position = 0;
    int bytes = 0;

    //Lat
    for (bytes = 0; bytes < sizeof(telemetry.latitude.value); bytes++)
    {
        telemetry.latitude.bytes[bytes] = message.payload[data_position + bytes];
    }

    //Lon
    data_position += sizeof(telemetry.latitude.value);

    for (bytes = 0; bytes < sizeof(telemetry.longitude.value); bytes++)
    {
        telemetry.longitude.bytes[bytes] = message.payload[data_position + bytes];
    }

    //Alt
    data_position += sizeof(telemetry.longitude.value);

    for (bytes = 0; bytes < sizeof(telemetry.altitude.value); bytes++)
    {
        telemetry.altitude.bytes[bytes] = message.payload[data_position + bytes];
    }

    //Alt Ellipsoid
    data_position += sizeof(telemetry.altitude.value);

    for (bytes = 0; bytes < sizeof(telemetry.altitude_ellipsoid.value); bytes++)
    {
        telemetry.altitude_ellipsoid.bytes[bytes] = message.payload[data_position + bytes];
    }

    //Alt Rel
    data_position += sizeof(telemetry.altitude_ellipsoid.value);

    for (bytes = 0; bytes < sizeof(telemetry.altitude_relative.value); bytes++)
    {
        telemetry.altitude_relative.bytes[bytes] = message.payload[data_position + bytes];
    }

    //Alt Baro
    data_position += sizeof(telemetry.altitude_relative.value);

    for (bytes = 0; bytes < sizeof(telemetry.altitude_barometric.value); bytes++)
    {
        telemetry.altitude_barometric.bytes[bytes] = message.payload[data_position + bytes];
    }

    //Elevation
    data_position += sizeof(telemetry.altitude_barometric.value);

    for (bytes = 0; bytes < sizeof(telemetry.elevation.value); bytes++)
    {
        telemetry.elevation.bytes[bytes] = message.payload[data_position + bytes];
    }

    //Azimuth
    data_position += sizeof(telemetry.elevation.value);

    for (bytes = 0; bytes < sizeof(telemetry.azimuth.value); bytes++)
    {
        telemetry.azimuth.bytes[bytes] = message.payload[data_position + bytes];
    }

    //GPS SNR
    data_position += sizeof(telemetry.azimuth.value);

    for (bytes = 0; bytes < sizeof(telemetry.gps_snr.value); bytes++)
    {
        telemetry.gps_snr.bytes[bytes] = message.payload[data_position + bytes];
    }

    //Vel Hor
    data_position += sizeof(telemetry.gps_snr.value);

    for (bytes = 0; bytes < sizeof(telemetry.velocity_horizontal.value); bytes++)
    {
        telemetry.velocity_horizontal.bytes[bytes] = message.payload[data_position + bytes];
    }

    //Vel Vert
    data_position += sizeof(telemetry.velocity_horizontal.value);

    for (bytes = 0; bytes < sizeof(telemetry.velocity_vertical.value); bytes++)
    {
        telemetry.velocity_vertical.bytes[bytes] = message.payload[data_position + bytes];
    }


    //Roll
    data_position += sizeof(telemetry.velocity_vertical.value);

    for (bytes = 0; bytes < sizeof(telemetry.roll.value); bytes++)
    {
        telemetry.roll.bytes[bytes] = message.payload[data_position + bytes];
    }


    //Pitch
    data_position += sizeof(telemetry.roll.value);

    for (bytes = 0; bytes < sizeof(telemetry.pitch.value); bytes++)
    {
        telemetry.pitch.bytes[bytes] = message.payload[data_position + bytes];
    }


    //Heading
    data_position += sizeof(telemetry.pitch.value);

    for (bytes = 0; bytes < sizeof(telemetry.heading.value); bytes++)
    {
        telemetry.heading.bytes[bytes] = message.payload[data_position + bytes];
    }


    //Course
    data_position += sizeof(telemetry.heading.value);

    for (bytes = 0; bytes < sizeof(telemetry.course.value); bytes++)
    {
        telemetry.course.bytes[bytes] = message.payload[data_position + bytes];
    }

    //Temp
    data_position += sizeof(telemetry.course.value);

    for (bytes = 0; bytes < sizeof(telemetry.temperature.value); bytes++)
    {
        telemetry.temperature.bytes[bytes] = message.payload[data_position + bytes];
    }

    //Pres
    data_position += sizeof(telemetry.temperature.value);

    for (bytes = 0; bytes < sizeof(telemetry.pressure.value); bytes++)
    {
        telemetry.pressure.bytes[bytes] = message.payload[data_position + bytes];
    }
}