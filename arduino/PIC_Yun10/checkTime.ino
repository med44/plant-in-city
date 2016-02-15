void checkTime() {
  
    // PRECISE TIME CHECK //////////////////////////////////////////////////////////////
  // NOT the TimeCheck example. this one uses the linux side to tell the time

  date.begin("/bin/date");
  date.addParameter("+%d/%m/%Y %T"); // for day of the week add %A // %m %Y - month and year are not used in this sketch
  date.run();

  String timeString = "";
  while (date.available() > 0) {
    char c = date.read();
    timeString = timeString + c;
  }  

  Console.print(timeString);     // print the results we got dd/mm/yyyy hh:mm:ss

  String day = timeString.substring(0, 2);    //current day
  String time = timeString.substring(11, 19); //current hh:mm:ss only, no date

  /* FOR DEBUGING: makes the day 'go by' every minute and time is always 10:00:ss
  String day = timeString.substring(14, 16);
  String second = timeString.substring(17, 19);
  String time = String(writeTime(10, 00, second.toInt())); //timeString.substring(11, 19); // hh:mm:ss only, no date
  */

    Console.print("SLLD: ");
    Console.print(sinceLastLightDay);
    Console.print(" LD: ");
    Console.print(lightDay);
    Console.print(":: SLWD: ");
    Console.print(sinceLastWaterDay);
    Console.print(" WD: ");
    Console.print(waterDay);
    Console.print(" T: ");
    Console.println(time);

  // Day Counter ////////////////////////////////////////////////////////////// 
    if (lastDay != day.toInt()) {          // if the date changed
    sinceLastLightDay ++ ;                     //add 1 to days since the last lighting
    sinceLastWaterDay ++ ;                     //add 1 to days since the last watering
    lastDay = day.toInt();                  //update lastDay value for the next comparison
  }

  
    // LIGHT TIMER //////////////////////////////////////////////////////////////
  
  if (lightDay != 0 && lightOn == false && sinceLastLightDay >= lightDay && time == lightTime) { // if lighting is active(not set to 0 days), light's off, interval reached, right time

    redLights();                  //turn light on
    blueLights();                 //turn light on
    lightOn = true;                  //light on
    Console.print(" #lights on ");

    sinceLastLightDay = 0;        //reset the day counter
    //lightEnd = addTime(lightTime, lightDuration); // calculates 'lightEnd' the time to stop the light // not needed here as it's calculated on updateSet()

  } else if (lightOn == true && time == lightEnd ) {   // if the light's on and the end time is reached

    lightsOff();           //turns all the lights off
    lightOn = false;      //light stopped
    Console.print(" #lights off ");
  }

     
  // WATER TIMER //////////////////////////////////////////////////////////////

  if (waterDay != 0 && waterOn == false && sinceLastWaterDay >= waterDay && time == waterTime) { //if watering is active(not set to 0 days), water is off, interval reached, right time

    digitalWrite(8, HIGH);                //turn water on
    waterOn = true;                       //water running
    Console.print(" #water running ");

    sinceLastWaterDay = 0;                //reset the day counter
    //waterEnd = addTime(waterTime, waterDuration); // calculates 'waterEnd' the time to stop the water

  } else if (waterOn == true && time == waterEnd ) {   // if the water is running and the end time is reached/ / not needed here as it's calculated on updateSet()

    digitalWrite(8, LOW);
    waterOn = false;      //water stopped
    Console.print(" #water stopped ");
  }
    
}
