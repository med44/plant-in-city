void loop() { 
  
  /////////////////////////////////////////////////////////////////////////////
  
  // Settings update?
  YunClient client = server.accept();    //puts the message comming from outside (server.accept) to var 'client'
  if (client) {                          // if true - settings.json has been updated from the UI => read it and update variables
    Console.println(" new input coming!");
    updateSet();                          //update the variables from the file
     //printHtml();
    
      String command = client.readString();
      command.trim();        //kill whitespace
      Serial.println(command);
      
      // is "temperature" command?
      if (command == "currentTimers") {
  
      client.print(counterLight);
      client.print("\t");
      client.print(lightTime);
      client.print("<br>");
      client.print(counterWater);
      client.print("\t");
      client.println(waterTime);
       
    }      
      // Close connection and free resources.
      client.stop();
    
  }  

  // PRECISE TIME CHECK //////////////////////////////////////////////////////////////
  // NOT the TimeCheck example. this one uses the linux side to tell the time

   //Get date from shell
  date.begin("/bin/date");
  date.addParameter("+%u %d/%m/%Y %T"); // for day of the week add %A, for day of week as  add %u where 1 is Monday
  date.run();
  
  String result = "";

  while (date.available() > 0) {
    char c = date.read();
    result = result + c;
  }

  //Parse Linux timestamp and parse it to get our variables
  String timeString = result;
//  Serial.print(timeString);
  
  String dayNumber = timeString.substring(0,1);
  String time = timeString.substring(13, 21);
  String seconds = timeString.substring(20);
  
  //Figure out when stop time is for light and water
  String lightEnd;
  lightEnd = addTime( lightTime, lightDuration);  
  String waterEnd;
  waterEnd = addTime( waterTime, waterDuration);

  
  //Convert time data from strings to integers and update time variables for comparison
  previousDay = thisDay;
  thisDay = dayNumber.toInt();
  
  //Run all the logic & debugging each second
  if (previousSecond != thisSecond){
 
//  Serial.print("previousSecond: ");
//  Serial.print(previousSecond);
//  Serial.print(" thisSecond: ");
//  Serial.print(thisSecond);
    
    //Day of week values used on scheduler logic
//  Serial.print(dayNumber); //this the raw String day of week number without int conversion
//  Serial.print("\t");
  Serial.print("thisDay: ");
  Serial.print(thisDay);
  Serial.print("\t"); 
//  Serial.print("previousDay: "); //to compare last with last known day
//  Serial.print(previousDay);
//  Serial.print("\t");      
  
  //Time & schedule values
  Serial.print("time: ");
  Serial.print("\t   "); 
  Serial.print(time);
  Serial.println(" -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -");
    
  //Lighting scheduler values
  Serial.print("counterLight: ");
  Serial.print(counterLight);
  Serial.print("\t");
  Serial.print("lighTtime: ");
  Serial.print(lightTime);
  Serial.print("\t");
  Serial.print("lightEnd: ");
  Serial.print(lightEnd);
  Serial.print("\t");
  Serial.print("lightOn: ");
  Serial.print(lightOn);
  Serial.print("\t");

  //Check if it's time to turn the lights ON  
  if (counterLight == 1){
      Serial.print(" > Light day");
      if (time == lightTime) {
        //Trigger all events for lighting here
        Serial.print(": alarm on");
        lightOn = 1; //Flags lights as being on
        redLights();
        blueLights();        
      }            
  
  }
  
  //Check if it's time to turn light OFF
      if (lightOn == 1) {
        if (time == lightEnd) {
          //Trigger all events to shut off lighting here
          Serial.print(": alarm off");
          lightOn = 0;
          lightsOff();
        }
     }
  
  Serial.println("");
  
  //IRRIGATION -------------------------------------
  
  //Irrigation scheduler values
  Serial.print("counterWater: ");
  Serial.print(counterWater);
  Serial.print("\t");
  Serial.print("watertime: ");
  Serial.print(waterTime);
  Serial.print("\t");
  Serial.print("waterEnd: ");
  Serial.print(waterEnd);
  Serial.print("\t");
  Serial.print("waterOn: ");
  Serial.print(waterOn);
  Serial.print("\t");
  
     
  //Check if it's time to turn the water ON  
  if (counterWater == 1){
      Serial.print(" > Water day");
      if (time == waterTime) {
        //Trigger all events for watering here
        Serial.print(": alarm on");
        waterOn = 1; //Flags water as being on        
        blueLights();
        digitalWrite(8, HIGH); //turn water on        
      }            
  
  }
  
  //Check if it's time to turn water OFF
      if (waterOn == 1) {
        if (time == waterEnd) {
          //Trigger all events to shut off watering here
          Serial.print(": alarm off");
          waterOn = 0;          
          digitalWrite(8, LOW);
          lightsOff();
        }
     }
       
  //START logic for checking days elapsed with shell time ------->
   
  //If weekday changes, substract a day from counterLight 
  if (thisDay != previousDay){
    
    counterLight--;
    counterWater--;    
    
    if (counterLight == 0){
      counterLight = lightDay;
      }    
  
      if (counterWater == 0){
    counterWater = waterDay;
    }    
  }
  
  //  fastTime(); //use to debug, it makes a day pass faster

 Serial.println();
 Serial.println();


 }
    
  //END logic -------------->

  previousSecond = thisSecond;
  thisSecond = seconds.toInt();
  
  }

void fastTime(){
  
  //START debugging, a day will pass by with each loop ------->
  timer++;
  
  if (timer==10){
    lastday = today;  
    timer = 0;
    today++; //add a day
    counterLight--;
    
    if (today == 8){ //if today is 8 we need to reset to day 1 (weekdays are 1-7)
      today = 1; //1 is monday and 7 is sunday
    }
      
    if (counterLight == 0){
    counterLight = lightDay;
    }  
       
  }
    
  Serial.print("timer: ");
  Serial.print(timer);
  Serial.print("\t");
  Serial.print("today: ");
  Serial.print(today);
  Serial.print("\t");
  Serial.print("lastday: ");
  Serial.print(lastday);
  Serial.print("\t");
  Serial.print("counterLight: ");
  Serial.print(counterLight);
  Serial.print("\t");

  //END debugging -----------------------------------------------------

}

