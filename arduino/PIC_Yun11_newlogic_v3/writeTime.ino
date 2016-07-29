/* 
takes three byte numbers h/m/s and returns time as String "hh:mm:ss"
*/

String writeTime(byte hour1, byte minute1, byte second1) {

  String time;

  //// hour ////
  if (hour1 < 10) {           
    time = time + "0" + String(hour1);
  } else {
    time = time + String(hour1);
  }
  
  time = time + ":";

  //// minute ////
  if (minute1 < 10) {
    time = time + "0" + String(minute1);
  } else {
    time = time + String(minute1);
  }

  time = time + ":";

  //// second ////
  if (second1 < 10) {
    time = time + "0" + String(second1);
  } else {
    time = time + String(second1);
  }

  return time;
}
