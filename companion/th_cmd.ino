enum TH_CMD {
  STATUS,
  RTL_MODE,
  GUIDED_MODE,
  TAKEOFF,
  LAND,
  RELAY_ON,
  RELAY_OFF,
  GO_TO,
  UNKNOWN
} th_cmd;


// int th_cmd_decode(String command){
//   if(command.substring(0,2)="TH"){
//     split_command = command.
//     switch()
//   } else {
//     return -1
//   }
// }