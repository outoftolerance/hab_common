/**
 * @brief      Defines different message types that can be sent
 */
enum MESSAGE_TYPES {
	/**
	 * Report Messages
	 */
    MESSAGE_TYPE_HEARTBEAT = 0,
    MESSAGE_TYPE_REPORT_TELEMETRY,

    /**
     * Command Messages
     */
	MESSAGE_TYPE_COMMAND_ARM,
    MESSAGE_TYPE_COMMAND_DISARM,
    MESSAGE_TYPE_COMMAND_SET_STATE,
    MESSAGE_TYPE_COMMAND_SET_TRACKER_LOCATION,
    MESSAGE_TYPE_COMMAND_SET_TRACKER_TARGET_LOCATION,
    MESSAGE_TYPE_COMMAND_SET_TRACKER_POSE,
    MESSATE_TYPE_COMMAND_SET_REPORT_RATE,
    MESSAGE_TYPE_COMMAND_REQUEST_REPORT,

    /**
     * Protocol Level Messages
     */
    MESSAGE_TYPE_PROTO_ACK,
    MESSAGE_TYPE_PROTO_NACK
};

enum NODE_TYPES {
    NODE_TYPE_GROUNDSTATION = 0,
    NODE_TYPE_BALLOON,
    NODE_TYPE_TRACKER
};

/**
 * @brief Union for float data
 */
typedef union
{
    float value;
    uint8_t bytes[4];
} FloatUnion_t;

/**
 * @brief Union for float data
 */
typedef union
{
    uint16_t value;
    uint8_t bytes[2];
} Int16Union_t;