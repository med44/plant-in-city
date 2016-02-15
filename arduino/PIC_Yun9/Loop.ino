void loop() { /////////////////////////////////////////////////////////////////////////////

  // Settings update?
  YunClient client = server.accept();    //puts the message comming from outside (server.accept) to var 'client'
  if (client) {                          // if true - settings.json has been updated from the UI => read it and update variables
    Console.println(" new input coming!");
    updateSet();                          //update the variables from the file
  }

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

  Console.println("-------------------------");
  Console.print(timeString);     // print the results we got dd/mm/yyyy hh:mm:ss

  String day = timeString.substring(0, 2);    //current day
  String time = timeString.substring(11, 19); //current hh:mm:ss only, no date

  /* FOR DEBUGING: makes the day 'go by' every minute and time is always 10:00:ss
  String day = timeString.substring(14, 16);
  String second = timeString.substring(17, 19);
  String time = String(writeTime(10, 00, second.toInt())); //timeString.substring(11, 19); // hh:mm:ss only, no date
  */

  //Light variables

  Console.print("lightDay:");
  Console.print("\t");
  Console.println(lightDay);
  Console.print("lightTime:");
  Console.print("\t");
  Console.println(lightTime);  
  Console.print("lightDuration:");
  Console.print("\t");
  Console.println(lightDuration);
  Console.print("lightEnd:");
  Console.print("\t");
  Console.println(lightEnd);
  Console.print("lightOn: ");
  Console.print("\t");
  Console.println(lightOn);
  Console.println();
  
  //Water variables

  Console.print("waterDay:");
  Console.print("\t");
  Console.println(waterDay);
  Console.print("waterTime:");
  Console.print("\t");
  Console.println(waterTime);
  Console.print("waterDuration:");
  Console.print("\t");
  Console.println(waterDuration);
  Console.print("waterEnd:");
  Console.print("\t");
  Console.println(waterEnd);
  Console.print("waterOn: ");
  Console.print("\t");
  Console.println(waterOn);
  Console.println();
  

  //Timers

  Console.print("time: ");
  Console.print("\t");
  Console.println(time);
  Console.print("sinceLastLightDay: ");
  Console.print("\t");
  Console.println(sinceLastLightDay);
  Console.print("sinceLastWaterDay: ");
  Console.print("\t");
  Console.print(sinceLastWaterDay);
  Console.println();
  

  // Day Counter //////////////////////////////////////////////////////////////
  if (lastDay != day.toInt()) {          // if the date changed
    sinceLastLightDay ++ ;                     //add 1 to days since the last lighting
    sinceLastWaterDay ++ ;                     //add 1 to days since the last watering
    lastDay = day.toInt();                  //update lastDay value for the next comparison
  }  
   
   Console.println("Counted days elapsed");


  // LIGHT TIMER //////////////////////////////////////////////////////////////

  if (lightDay != 0 && lightOn == 0 && sinceLastLightDay >= lightDay && time >= lightTime) { // if lighting is active(not set to 0 days), light's off, interval reached, right time

    redLights();                  //turn light on
    blueLights();                 //turn light on
    lightOn = true;                  //light on
    Console.println(" #lights on ");

    sinceLastLightDay = 0;        //reset the day counter
    //lightEnd = addTime(lightTime, lightDuration); // calculates 'lightEnd' the time to stop the light // not needed here as it's calculated on updateSet()

  } else if (lightOn == 1 && time >= lightEnd ) {   // if the light's on and the end time is reached

    lightsOff();           //turns all the lights off
    lightOn = false;      //light stopped
    Console.println(" #lights off ");
  }
  
    Console.println("Checked light timer");


  // WATER TIMER //////////////////////////////////////////////////////////////

  if (waterDay != 0 && waterOn == 0 && sinceLastWaterDay >= waterDay && time >= waterTime) { //if watering is active(not set to 0 days), water is off, interval reached, right time

    digitalWrite(8, HIGH);                //turn water on
    waterOn = true;                       //water running
    Console.println(" #water running ");

    sinceLastWaterDay = 0;                //reset the day counter
    //waterEnd = addTime(waterTime, waterDuration); // calculates 'waterEnd' the time to stop the water

  } else if (waterOn == 1 && time >= waterEnd ) {   // if the water is running and the end time is reached/ / not needed here as it's calculated on updateSet()

    digitalWrite(8, LOW);
    waterOn = false;      //water stopped
    Console.println(" #water stopped ");
  }
  
  Console.println("Checked water timer");

  //-----------------------

  Console.println("");  //new line in console
  delay(5000);

} //end of loop

