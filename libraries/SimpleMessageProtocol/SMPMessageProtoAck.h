#define MESSAGE_PROTO_ACK_PAYLOAD_LENGTH 1
#define MESSAGE_PROTO_ACK_PAYLOAD_BYTE_LENGTH 1

typedef struct smpMessageProtoAck
{
	uint8_t type;
};

static inline void smpMessageProtoAckEncode(uint8_t node_id, uint8_t node_type, smpMessageProtoAck& ack, hdlcMessage& message)
{
	message.node_id = node_id;
    message.node_type = node_type;
    message.command = MESSAGE_TYPES::MESSAGE_TYPE_PROTO_ACK;
    message.length = MESSAGE_PROTO_ACK_PAYLOAD_BYTE_LENGTH;

    int data_position = 0;
    int bytes = 0;

    for (bytes = 0; bytes < sizeof(uint8_t); bytes++)
    {
        message.payload[data_position + bytes] = ack.type;
    }
}