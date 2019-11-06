#define MESSAGE_HEARTBEAT_PAYLOAD_LENGTH 1
#define MESSAGE_HEARTBEAT_PAYLOAD_BYTE_LENGTH 1

typedef struct smpMessageHeartbeat
{
	uint8_t mission_state;
};

static inline void smpMessageHeartbeatEncode(uint8_t node_id, uint8_t node_type, smpMessageHeartbeat& heartbeat, hdlcMessage& message)
{
	message.node_id = node_id;
    message.node_type = node_type;
    message.command = MESSAGE_TYPES::MESSAGE_TYPE_HEARTBEAT;
    message.length = MESSAGE_HEARTBEAT_PAYLOAD_BYTE_LENGTH;

    int data_position = 0;
    int bytes = 0;

    for (bytes = 0; bytes < sizeof(uint8_t); bytes++)
    {
        message.payload[data_position + bytes] = heartbeat.mission_state;
    }
}