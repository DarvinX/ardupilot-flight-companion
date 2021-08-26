void request_params() {
  mavlink_msg_param_request_read_pack(APMID, COMPID, &msg, 1, 1, "SYSID_SW_TYPE", -1);
  send_msg();
  Serial.println("param req send");
}

void request_gps_data_stream() {
  mavlink_msg_request_data_stream_pack(APMID, COMPID, &msg, 1, 1, 6, 1, 1);
  send_msg();
  Serial.println("gps request send");
}

//==================Actions==================
void take_off(float relative_alt) {
}

void land() {
}

void go_to(int lat, int lon, float relative_alt) {
}

void set_light_on_off(int state) {
  send_command_long(MAV_CMD::MAV_CMD_DO_SET_RELAY, 0,
                    1, state, 0, 0, 0, 0, 0);
}

//===============Flight Modes================
// loiter 5, guided 4, stabilise 0, auto 3, rtl 6
void set_guided_mode() {
  mavlink_msg_set_mode_pack(APMID, COMPID, &msg, 1, 5, 4);
  send_msg();
  Serial.println("guided mode req");
}

void RTL() {
  mavlink_msg_set_mode_pack(APMID, COMPID, &msg, 1, 5, 6);
  send_msg();
  Serial.println("returning to home");
}

void send_msg() {
  len = mavlink_msg_to_send_buffer(buf, &msg);
  Serial1.write(buf, len);
}

// =================Utils=====================
void send_command_long(uint16_t command, uint8_t confirmation, float param1, float param2, float param3, float param4, float param5, float param6, float param7) {
  mavlink_msg_command_long_pack(APMID, COMPID, &msg, 1, 1, command, confirmation, param1,
                                param2, param3, param4, param5, param6, param7);
  send_msg();
}