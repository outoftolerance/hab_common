/**
 * @brief      Defines different message types that can be sent
 */
enum MESSAGE_TYPES {
	/**
	 * Report Messages
	 */
	MESSAGE_TYPE_REPORT_TELEMETRY,
    MESSAGE_TYPE_REPORT_POSITION,
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

    /**
     * Protocol Level Messages
     */
    MESSAGE_TYPE_PROTO_ACK,
    MESSAGE_TYPE_PROTO_NACK
};