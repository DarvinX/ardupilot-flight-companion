
void get_update() {
  mavlink_message_t msg;
  mavlink_status_t status;

  while (Serial1.available()) {
    uint8_t c = Serial1.read();
    if (mavlink_parse_char(MAVLINK_COMM_0, c, &msg, &status)) {
      Serial.print("debug msg: ");
      Serial.println(msg.msgid);

      switch (msg.msgid) {
        case MAVLINK_MSG_ID_GLOBAL_POSITION_INT:
          relative_alt = float(mavlink_msg_global_position_int_get_relative_alt(&msg)) / 1000;
          lat = ((float)mavlink_msg_global_position_int_get_lat(&msg)) / 10000000;
          lon = ((float)mavlink_msg_global_position_int_get_lon(&msg)) / 10000000;
          Serial.println(lat, 7);
          Serial.println(lon, 7);
          break;
        case MAVLINK_MSG_ID_HEARTBEAT:
          // loiter 5, guided 4, stabilise 0, auto 3, rtl 6
          flight_mode = mavlink_msg_heartbeat_get_custom_mode(&msg);
          Serial.println(flight_mode);

          break;
      }
    }
  }
}


void debug_print(byte debug_msg) {
  Serial.println(debug_msg);
}