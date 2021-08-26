#include "mavlink.h"
#include <SPI.h>
#include <NRFLite.h>

#define APMID 1
#define COMPID 1

const static uint8_t RADIO_ID = 0;
const static uint8_t DESTINATION_RADIO_ID = 1;  // Id of the radio we will transmit to.

// esp 12e
const static uint8_t PIN_RADIO_CE = 2;
const static uint8_t PIN_RADIO_CSN = 15;

// arduino mega
// const static uint8_t PIN_RADIO_CE = 7;
// const static uint8_t PIN_RADIO_CSN = 8;

// esp 12e
struct __attribute__((packed)) RadioPacket  // Note the packed attribute.
{
  byte command;
};

NRFLite _radio;
RadioPacket _radioData;

mavlink_message_t msg;
uint8_t len;
uint8_t buf[MAVLINK_MAX_PACKET_LEN];

int flight_mode = -1;
float relative_alt = -1;
float lat = -1;
float lon = -1;  // meters


void setup() {
  Serial.begin(57600);
  Serial1.begin(57600);
  Serial.println("starting up");

  //  request_gps_data_stream();
  //request_params();
  request_gps_data_stream();
  delay(2000);
  set_guided_mode();
  delay(2000);
}



void loop() {
  while (_radio.hasData()) {
    //  Serial.print("here");
    //  digitalWrite(LED_BUILTIN, LOW);
    _radio.readData(&_radioData);
    byte msg = _radioData.command;

    // debug_print(msg) if ()
    // Serial.write(msg);
  }

  get_update();
  set_light_on_off(0);
  delay(2000);
  set_light_on_off(1);
  delay(2000);
}
