#define MESSAGE_REPORT_ENVIRONMENT_PAYLOAD_LENGTH 2
#define MESSAGE_REPORT_ENVIRONMENT_PAYLOAD_BYTE_LENGTH 8

typedef struct smpMessageReportEnvironment
{
	FloatUnion_t temperature;
	FloatUnion_t pressure;
};

static inline void smpMessageReportEnvironmentEncode(uint8_t node_id, uint8_t node_type, smpMessageReportEnvironment& environment, hdlcMessage& message)
{
	message.node_id = node_id;
    message.node_type = node_type;
    message.command = MESSAGE_TYPES::MESSAGE_TYPE_REPORT_ENVIRONMENT;
    message.length = MESSAGE_REPORT_ENVIRONMENT_PAYLOAD_BYTE_LENGTH;

    int data_position = 0;
    int bytes = 0;

    for (bytes = 0; bytes < sizeof(float); bytes++)
    {
        message.payload[data_position + bytes] = environment.temperature.bytes[bytes];
    }

    data_position += sizeof(float);

    for (bytes = 0; bytes < sizeof(float); bytes++)
    {
        message.payload[data_position + bytes] = environment.pressure.bytes[bytes];
    }
}