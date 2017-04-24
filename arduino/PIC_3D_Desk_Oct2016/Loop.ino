void loop() { 
  
  /////////////////////////////////////////////////////////////////////////////
  
  // Settings update?
  BridgeClient client = server.accept();    //puts the message comming from outside (server.accept) to var 'client'
  if (client) {                          // if true - settings.json has been updated from the UI => read it and update variables
    
      String command = client.readString();
      command.trim();        //kill whitespace
      Console.println(command);
      
      if (command == "updatedTimer") {
        Console.println("New schedule recorded:");
        updateSet();                          //update the variables from the file
        }

      if (command == "currentTimers") {  
//        currentTimers();
          client.println("Lighting:");
          client.print(counterLight);
          client.print("\t");
          client.print(lightTime);
          client.print("\t");
          client.println(lightEnd);
          client.println();
          client.println();
          client.println("Irrigation:");
          client.print(counterWater);
          client.print("\t");
          client.print(waterTime);
          client.print("\t");
          client.println(waterEnd);
          }
  
      if (command == "checkSoil") {
      
        soilVal = analogRead(soilPin); //connect sensor to Analog 0
        client.print(soilVal); //print the value to serial port
        client.print("\t");
    
        if(soilVal >= drySoil)
        {
          client.print("Parched");
        }
        
        else if(soilVal > wetSoil && soilVal < drySoil)
        {
          client.print("Dry");
        } 
        
        else if(soilVal > soakedSoil && soilVal < wetSoil)
        {
          client.print("Wet");
        }
        
        else if(soilVal > water && soilVal < soakedSoil)
        {
          client.print("Soaked");
        }
        
        else if(soilVal <= water)
        {
          client.print("Water");
        }
  
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
  String dayNumber = timeString.substring(0,1);
  String time = timeString.substring(13, 21);
  String seconds = timeString.substring(20);
  
  //Figure out when stop time is for light and water
  String lightEnd;
  lightEnd = addTime( lightTime, lightDuration);  
  String waterEnd;
  waterEnd = addTime( waterTime, waterDuration);
  
  //Convert time data from strings to integers and update time variables for comparison
  thisDay = dayNumber.toInt();
  
  //START logic for checking days elapsed with shell time ------->

  //If weekday changes, substract a day from counterLight 
  if (thisDay != previousDay){
    
    counterLight--;
    counterWater--;    
    
    if (counterLight <= 0){
      counterLight = lightDay;
      }    
  
      if (counterWater <= 0){
    counterWater = waterDay;
    }    
  }

  
  previousDay = thisDay; //Store the last known day to compare if there was a change on the next loop


  
  //Run all the logic & debugging each second
  if (previousSecond != thisSecond){
    
    //Day of week values used on scheduler logic
//  Console.print("thisDay: ");
//  Console.print(thisDay);
//  Console.print("\t");     
  
  //Time & schedule values
  Console.println(time);
//  Console.println(" -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -");
//  currentTimers();
  
  
  //LIGHTING -------------------------------------
  
  //Lighting scheduler values
//  Console.print("counterLight: ");
//  Console.print(counterLight);
//  Console.print("\t");
//  Console.print("lighTtime: ");
//  Console.print(lightTime);
//  Console.print("\t");
//  Console.print("lightEnd: ");
//  Console.print(lightEnd);
//  Console.print("\t");
//  Console.print("lightOn: ");
//  Console.print(lightOn);
//  Console.print("\t");

  //Check if it's time to turn the lights ON  
  if (counterLight == 1){
      Console.print(" > Light day");
      if (time == lightTime) {
        //Trigger all events for lighting here
        Console.print(": ON");
        lightOn = 1; //Flags lights as being on
        redLights();
        blueLights();
        Console.println("All lights on ");
        
      }            
  
  }
  
  //Check if it's time to turn light OFF
      if (lightOn == 1) {
        if (time >= lightEnd) {
          //Trigger all events to shut off lighting here
          Console.print(": OFF");
          lightOn = 0;
          lightsOff();
        }
     }
  
  Console.println("");
  
  //IRRIGATION -------------------------------------
  
  //Irrigation scheduler values
//  Console.print("counterWater: ");
//  Console.print(counterWater);
//  Console.print("\t");
//  Console.print("watertime: ");
//  Console.print(waterTime);
//  Console.print("\t");
//  Console.print("waterEnd: ");
//  Console.print(waterEnd);
//  Console.print("\t");
//  Console.print("waterOn: ");
//  Console.print(waterOn);
//  Console.print("\t");
  
     
  //Check if it's time to turn the water ON  
  if (counterWater == 1){
      Console.print(" > Water day");
      if (time == waterTime) {
        //Trigger all events for watering here
        Console.print(": water on");
        waterOn = 1; //Flags water as being on        
      }            
  
  }  
  
  //Check if it's time to turn water OFF
      if (waterOn == 1) {
        
       digitalWrite(8, HIGH); //turn water on
       Console.println(": ON");   
        
        if (time >= waterEnd) {
          //Trigger all events to shut off watering here
          digitalWrite(8, LOW);
          Console.print(": OFF");
          waterOn = 0;          
          logUpdate();          
        }
     }
     
 
       
  //START logic for checking days elapsed with shell time ------->
  
  //  fastTime(); //use to debug, it makes a day pass faster

// checkSoil();

 Console.println();
 Console.println();


 }
    
  //END logic -------------->

  previousSecond = thisSecond;
  thisSecond = seconds.toInt();

//  Serial.print("freeMemory()= "); 
//  Serial.println(freeMemory()); //shows how much memory is free on program  
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
    
  Console.print("timer: ");
  Console.print(timer);
  Console.print("\t");
  Console.print("today: ");
  Console.print(today);
  Console.print("\t");
  Console.print("lastday: ");
  Console.print(lastday);
  Console.print("\t");
  Console.print("counterLight: ");
  Console.print(counterLight);
  Console.print("\t");

  //END debugging -----------------------------------------------------

}

//void currentTimers(){
//String timerNames [] = {"lightTime: ", "lightEnd: ", "waterTime: ", "waterEnd: "};
//String timers [] = {lightTime, lightEnd, waterTime, waterEnd};
//String stateNames [] = {"counterLight: ", "lightOn: ", "counterWater: ", "waterOn: "};
//byte states [] = {counterLight, lightOn, counterWater, waterOn};
//
////if (mode = "client"){
//
//for(int x = 0; x < 5; x++) {
//  client.print(timerNames[x]);
//  client.print("\t");
//  client.print(timers[x]);
//}
//  client.println();
// for(int x = 0; x < 5; x++) {
//  client.print(stateNames[x]);
//  client.print("\t");
//  client.print(states[x]);
//  }
//}

//if (mode = "Console"){
//
// for(int x = 0; x < 5; x++) {
//  Console.print(timerNames[x]);
//  Console.print("\t");
//  Console.print(timers[x]);
//}
//  Console.println();
// for(int x = 0; x < 5; x++) {
//  Console.print(stateNames[x]);
//  Console.print("\t");
//  Console.print(states[x]);
//  }
//} 
//}