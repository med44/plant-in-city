void loop() {
  
     // Settings update?
   YunClient client = server.accept();    //puts the message comming from outside (server.accept) to var 'client'
   if (client) {                          // if true - settings.json has been updated from the UI => read it and update variables
     Console.println("New settings received");
     updateSet();      //reads json file and updates variables accordingly
   } 
  
  checkTime();    //checks timedEvents timers and rules

  debugTools();

  Console.println("");  //new line in console
  delay(1000);           

} //end of loop


void debugTools() {
  // see if there's incoming serial data:
  if (Console.available() > 0) {
    // read the oldest byte in the serial buffer:
    incomingByte = Console.read();
    // if it's a capital H (ASCII 72), turn on the LED:
    if (incomingByte == 'H') {
      redLights();
      blueLights();
    } 
    // if it's an L (ASCII 76) turn off the LED:
    if (incomingByte == 'L') {
      lightsOff();
    }
  }
}
