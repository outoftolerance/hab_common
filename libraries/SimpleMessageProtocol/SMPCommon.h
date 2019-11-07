/**
 * @brief      Defines different message types that can be sent
 */
enum MESSAGE_TYPES {
	/**
	 * Report Messages
	 */
    MESSAGE_TYPE_HEARTBEAT = 0,
	MESSAGE_TYPE_REPORT_ATTITUDE,
    MESSAGE_TYPE_REPORT_POSITION,
    MESSAGE_TYPE_REPORT_ENVIRONMENT,
    MESSAGE_TYPE_REPORT_TRACKER_POSE,

    /**
     * Command Messages
     */
	MESSAGE_TYPE_COMMAND_ARM,
    MESSAGE_TYPE_COMMAND_DISARM,
    MESSAGE_TYPE_COMMAND_SET_STATE,
    MESSAGE_TYPE_COMMAND_SET_TRACKER_LOCATION,
    MESSAGE_TYPE_COMMAND_SET_TRACKER_TARGET_LOCATION,
    MESSAGE_TYPE_COMMAND_SET_TRACKER_POSE,
    MESSAGE_TYPE_COMMAND_REQUEST_REPORT,
    MESSAGE_TYPE_COMMAND_RESET_BASE_ALTITUDE,

    /**
     * Protocol Level Messages
     */
    MESSAGE_TYPE_PROTO_ACK,
    MESSAGE_TYPE_PROTO_NACK
};

enum NODE_TYPES {
    NODE_TYPE_GROUNDSTATION = 0,
    NODE_TYPE_BALLOON,
    NOTE_TYPE_TRACKER
};

/**
 * @brief Union for float data
 */
typedef union
{
    float value;
    uint8_t bytes[4];
} FloatUnion_t;