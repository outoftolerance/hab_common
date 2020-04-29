#define MESSAGE_COMMAND_SET_REPORT_RATE_PAYLOAD_LENGTH 13
#define MESSAGE_COMMAND_SET_REPORT_RATE_PAYLOAD_BYTE_LENGTH 52

typedef struct smpMessageCommandSetReportRate
{
    Int16Union_t message;   /*< MESSAGE_TYPE id rate being set */
    FloatUnion_t rate;      /*< Desired message rate in Hz */
};

static inline void smpMessageCommandSetReportRateEncode(uint8_t node_id, uint8_t node_type, smpMessageCommandSetReportRate& command, hdlcMessage& message)
{
    message.node_id = node_id;
    message.node_type = node_type;
    message.command = MESSAGE_TYPES::MESSAGE_TYPE_COMMAND_SET_REPORT_RATE;
    message.length = MESSAGE_COMMAND_SET_REPORT_RATE_PAYLOAD_BYTE_LENGTH;

    int data_position = 0;
    int bytes = 0;

    for (bytes = 0; bytes < sizeof(float); bytes++)
    {
        message.payload[data_position + bytes] = command.message.bytes[bytes];
    }

    data_position += sizeof(float);

    for (bytes = 0; bytes < sizeof(float); bytes++)
    {
        message.payload[data_position + bytes] = command.rate.bytes[bytes];
    }
}