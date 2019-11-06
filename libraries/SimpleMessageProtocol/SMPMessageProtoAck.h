#include <SMPCommon.h>

#define MESSAGE_REPORT_ATTITUDE_PAYLOAD_LENGTH 3
#define MESSAGE_REPORT_ATTITUDE_PAYLOAD_BYTE_LENGTH 12

typedef struct smpMessageReportAttitude
{
	FloatUnion_t roll;
	FloatUnion_t pitch;
	FloatUnion_t heading;
};

static inline void smpMessageReportAttitudeEncode(uint8_t node_id, NODE_TYPES node_type, smpMessageReportAttitude& attitude, hdlcMessage& message)
{
	message.node_id = node_id;
    message.node_type = node_type;
    message.command = MESSAGE_TYPES::MESSAGE_TYPE_REPORT_ATTITUDE;
    message.length = MESSAGE_REPORT_ATTITUDE_PAYLOAD_BYTE_LENGTH;

    int data_position = 0;
    int bytes = 0;

    for (bytes = 0; bytes < sizeof(float); bytes++)
    {
        message.payload[data_position + bytes] = attitude.roll.bytes[bytes];
    }

    data_position += sizeof(float);

    for (bytes = 0; bytes < sizeof(float); bytes++)
    {
        message.payload[data_position + bytes] = attitude.pitch.bytes[bytes];
    }

    data_position += sizeof(float);

    for (bytes = 0; bytes < sizeof(float); bytes++)
    {
        message.payload[data_position + bytes] = attitude.heading.bytes[bytes];
    }
}