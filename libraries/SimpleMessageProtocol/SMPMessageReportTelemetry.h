#define MESSAGE_REPORT_TELEMETRY_PAYLOAD_LENGTH 13
#define MESSAGE_REPORT_TELEMETRY_PAYLOAD_BYTE_LENGTH 52

typedef struct smpMessageReportTelemetry
{
    FloatUnion_t latitude;
    FloatUnion_t longitude;
    FloatUnion_t altitude;
    FloatUnion_t altitude_relative;
    FloatUnion_t altitude_barometric;
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

    for (bytes = 0; bytes < sizeof(float); bytes++)
    {
        message.payload[data_position + bytes] = telemetry.latitude.bytes[bytes];
    }

    data_position += sizeof(float);

    for (bytes = 0; bytes < sizeof(float); bytes++)
    {
        message.payload[data_position + bytes] = telemetry.longitude.bytes[bytes];
    }

    data_position += sizeof(float);

    for (bytes = 0; bytes < sizeof(float); bytes++)
    {
        message.payload[data_position + bytes] = telemetry.altitude.bytes[bytes];
    }

    data_position += sizeof(float);

    for (bytes = 0; bytes < sizeof(float); bytes++)
    {
        message.payload[data_position + bytes] = telemetry.altitude_relative.bytes[bytes];
    }

    data_position += sizeof(float);

    for (bytes = 0; bytes < sizeof(float); bytes++)
    {
        message.payload[data_position + bytes] = telemetry.altitude_barometric.bytes[bytes];
    }

    data_position += sizeof(float);

    for (bytes = 0; bytes < sizeof(float); bytes++)
    {
        message.payload[data_position + bytes] = telemetry.velocity_horizontal.bytes[bytes];
    }

    data_position += sizeof(float);

    for (bytes = 0; bytes < sizeof(float); bytes++)
    {
        message.payload[data_position + bytes] = telemetry.velocity_vertical.bytes[bytes];
    }

    data_position += sizeof(float);

    for (bytes = 0; bytes < sizeof(float); bytes++)
    {
        message.payload[data_position + bytes] = telemetry.roll.bytes[bytes];
    }

    data_position += sizeof(float);

    for (bytes = 0; bytes < sizeof(float); bytes++)
    {
        message.payload[data_position + bytes] = telemetry.pitch.bytes[bytes];
    }

    data_position += sizeof(float);

    for (bytes = 0; bytes < sizeof(float); bytes++)
    {
        message.payload[data_position + bytes] = telemetry.heading.bytes[bytes];
    }

    data_position += sizeof(float);

    for (bytes = 0; bytes < sizeof(float); bytes++)
    {
        message.payload[data_position + bytes] = telemetry.course.bytes[bytes];
    }

    data_position += sizeof(float);

    for (bytes = 0; bytes < sizeof(float); bytes++)
    {
        message.payload[data_position + bytes] = telemetry.temperature.bytes[bytes];
    }

    data_position += sizeof(float);

    for (bytes = 0; bytes < sizeof(float); bytes++)
    {
        message.payload[data_position + bytes] = telemetry.pressure.bytes[bytes];
    }
}