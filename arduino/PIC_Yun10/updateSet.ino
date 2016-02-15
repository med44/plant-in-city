/* 
This function reads the JSON file (defined as filePath), parses out the values and updates variables with them.
The JSON file must be correctly formated. NO COMA after the last item!!!
*/

void updateSet() {

  File dataFile = FileSystem.open(filePath, FILE_READ);   //open file
  String json = dataFile.readString();                    // read data to 'json' variable
  dataFile.close();                                       // close file


// ArdunoJson.h //
  StaticJsonBuffer<400> jsonBuffer;       // buffer must be big enough to hold the whole JSON string
  JsonObject& root = jsonBuffer.parseObject(json);    // breaks the JSON string into individual items, saves into JsonObject 'root'
  
  Console.println(json);

  if (!root.success()) {
    Console.println("parseObject() failed");
    return;   //if parsing failed, this will exit the function and not change the values to 00
    
  } else { // update variables
   
    lightDay = root["LI"];
    lightTime = writeTime( root["LH"] , root["LM"] , 0 );
    lightDuration = writeTime( root["LDH"] , root["LDM"] , root["LDS"] );
    lightEnd = addTime( lightTime, lightDuration);

    waterDay = root["WI"];
    waterTime = writeTime( root["WH"] , root["WM"] , 0 );
    waterDuration = writeTime( root["WDH"] , root["WDM"] , root["WDS"] );
    waterEnd = addTime( waterTime, waterDuration);

    sinceLastLightDay=0; //reset interval timers
    sinceLastWaterDay=0;

    Console.println("values updated");
    Console.print("light time:");
    Console.println(lightTime);
    Console.print("light day:");
    Console.println(lightDay);

    Console.print(":: water time:");
    Console.println(waterTime);
    Console.print("water day:");
    Console.println(waterDay);
    
  } // end of if(!root.success())
}

