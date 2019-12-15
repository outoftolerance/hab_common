#define MESSAGE_REPORT_POSITION_PAYLOAD_LENGTH 8
#define MESSAGE_REPORT_POSITION_PAYLOAD_BYTE_LENGTH 32

typedef struct smpMessageReportPosition
{
	FloatUnion_t latitude;
	FloatUnion_t longitude;
    FloatUnion_t altitude;
    FloatUnion_t altitude_relative;
    FloatUnion_t altitude_barometric;
    FloatUnion_t course;
    FloatUnion_t velocity_horizontal;
    FloatUnion_t velocity_vertical;
};

static inline void smpMessageReportPositionEncode(uint8_t node_id, uint8_t node_type, smpMessageReportPosition& position, hdlcMessage& message)
{
	message.node_id = node_id;
    message.node_type = node_type;
    message.command = MESSAGE_TYPES::MESSAGE_TYPE_REPORT_POSITION;
    message.length = MESSAGE_REPORT_POSITION_PAYLOAD_BYTE_LENGTH;

    int data_position = 0;
    int bytes = 0;

    for (bytes = 0; bytes < sizeof(float); bytes++)
    {
        message.payload[data_position + bytes] = position.latitude.bytes[bytes];
    }

    data_position += sizeof(float);

    for (bytes = 0; bytes < sizeof(float); bytes++)
    {
        message.payload[data_position + bytes] = position.longitude.bytes[bytes];
    }

    data_position += sizeof(float);

    for (bytes = 0; bytes < sizeof(float); bytes++)
    {
        message.payload[data_position + bytes] = position.altitude.bytes[bytes];
    }

    data_position += sizeof(float);

    for (bytes = 0; bytes < sizeof(float); bytes++)
    {
        message.payload[data_position + bytes] = position.altitude_relative.bytes[bytes];
    }

    data_position += sizeof(float);

    for (bytes = 0; bytes < sizeof(float); bytes++)
    {
        message.payload[data_position + bytes] = position.altitude_barometric.bytes[bytes];
    }

    data_position += sizeof(float);

    for (bytes = 0; bytes < sizeof(float); bytes++)
    {
        message.payload[data_position + bytes] = position.course.bytes[bytes];
    }

    data_position += sizeof(float);

    for (bytes = 0; bytes < sizeof(float); bytes++)
    {
        message.payload[data_position + bytes] = position.velocity_horizontal.bytes[bytes];
    }

    data_position += sizeof(float);

    for (bytes = 0; bytes < sizeof(float); bytes++)
    {
        message.payload[data_position + bytes] = position.velocity_vertical.bytes[bytes];
    }
}