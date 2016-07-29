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
      Console.println(command);
      
      // is "temperature" command?
      if (command == "currentTimers") {
  
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
//  Console.print(timeString);
  
  String dayNumber = timeString.substring(0,1);
  String time = timeString.substring(13, 21);
  String seconds = timeString.substring(20);
  
  //Figure out when stop time is for watering
  String waterEnd;
  waterEnd = addTime( waterTime, waterDuration);

  
  //Convert time data from strings to integers and update time variables for comparison
  previousDay = thisDay;
  thisDay = dayNumber.toInt();
  
  //Run all the logic & debugging each second
  if (previousSecond != thisSecond){
 
//  Console.print("previousSecond: ");
//  Console.print(previousSecond);
//  Console.print(" thisSecond: ");
//  Console.print(thisSecond);
    
    //Day of week values used on scheduler logic
//  Console.print(dayNumber); //this the raw String day of week number without int conversion
//  Console.print("\t");
  Console.print("thisDay: ");
  Console.print(thisDay);
  Console.print("\t"); 
//  Console.print("previousDay: "); //to compare last with last known day
//  Console.print(previousDay);
//  Console.print("\t");      
  
  //Time & schedule values
  Console.print("time: ");
  Console.print("\t   "); 
  Console.print(time);
  Console.println(" -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -");    
        
  //IRRIGATION -------------------------------------
  
  //Irrigation scheduler values
  Console.print("counterWater: ");
  Console.print(counterWater);
  Console.print("\t");
  Console.print("watertime: ");
  Console.print(waterTime);
  Console.print("\t");
  Console.print("waterEnd: ");
  Console.print(waterEnd);
  Console.print("\t");
  Console.print("waterOn: ");
  Console.print(waterOn);
  Console.print("\t");
  
     
  //Check if it's time to turn the water ON  
  if (counterWater == 1){
      Console.print(" > Water day");
      if (time == waterTime) {
        //Trigger all events for watering here
        Console.print(": watering...");
        waterOn = 1; //Flags water as being on        
      }            
  
  }  
  
  //Check if it's time to turn water OFF
      if (waterOn == 1) {
        
       digitalWrite(waterPin, HIGH); //turn water on
       Console.print(": water on");   
       
        if (time >= waterEnd) {
          //Trigger all events to shut off watering here
          digitalWrite(waterPin, LOW);
          Console.print(": water off");
          waterOn = 0;          

        }
     }
     
 
       
  //START logic for checking days elapsed with shell time ------->
   
  //If weekday changes, substract a day from counterWater 
  if (thisDay != previousDay){
    
    counterWater--;    
          
      if (counterWater == 0){
    counterWater = waterDay;
    }    
  }
  
// fastTime(); //use to debug, it simulates a day passing every 10 secs

 Console.println();
 Console.println();


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
    counterWater--;
    
    if (today == 8){ //if today is 8 we need to reset to day 1 (weekdays are 1-7)
      today = 1; //1 is monday and 7 is sunday
    }
      
    if (counterWater == 0){
    counterWater = waterDay;
    }  
       
  }

  Console.println();  
  Console.print("timer: ");
  Console.print(timer);
  Console.print("\t");
  Console.print("today: ");
  Console.print(today);
  Console.print("\t");
  Console.print("lastday: ");
  Console.print(lastday);
  Console.print("\t");
  Console.print("counterWater: ");
  Console.print(counterWater);
  Console.print("\t");

  //END debugging -----------------------------------------------------

}

