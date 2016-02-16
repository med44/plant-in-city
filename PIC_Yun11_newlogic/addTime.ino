/* 
This function takes two time values and adds them up.
It takes two strings (hh:mm:ss) and returns the result in the same format
If the number of hours exceeds 24 it will start from 0 again, as if continuing the next day. 
*/

String addTime(String time1, String time2) {

  byte hour1 = time1.substring(0, 2).toInt();
  byte minute1 = time1.substring(3, 5).toInt();
  byte second1 = time1.substring(6, 8).toInt();

  byte hour2 = time2.substring(0, 2).toInt();
  byte minute2 = time2.substring(3, 5).toInt();
  byte second2 = time2.substring(6, 8).toInt();

  String hour;
  String minute;
  String second;

  String time;
  byte hold = 0;

  //// second
  second1 = second1 + second2;

  if (second1 < 10) {

    second = "0" + String(second1);
    hold = 0;

  } else if (second1 >= 60) {

    hold = 1;
    second1 = second1 - 60;

    if (second1 < 10) {

      second = "0" + String(second1);

    } else {
      second = String(second1);
    }

  } else {

    second = String(second1);
    hold = 0;
  }

  //// minute
    minute1 = minute1 + minute2 + hold;

  if (minute1 < 10) {

    minute = "0" + String(minute1);
    hold = 0;

  } else if (minute1 >= 60) {

    hold = 1;
    minute1 = minute1 - 60;

    if (minute1 < 10) {

      minute = "0" + String(minute1);

    } else {
      minute = String(minute1);
    }

  } else {

    minute = String(minute1);
    hold = 0;
  }
  
  //// hour
    hour1 = hour1 + hour2 + hold;

    if (hour1 < 10) {

    hour = "0" + String(hour1);
    //hold = 0; //not needed for hours

  } else if (hour1 >= 24) {

    //hold = 1; //not needed for hours
    hour1 = hour1 - 24;

    if (hour1 < 10) {

      hour = "0" + String(hour1);

    } else {
      hour = String(hour1);
    }

  } else {

    hour = String(hour1);
    //hold = 0; //not needed for hours 
  }
  
  //// return
  time = hour + ":" + minute + ":" + second;

  return time;
}

