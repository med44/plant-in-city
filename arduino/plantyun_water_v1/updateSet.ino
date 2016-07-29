/*
This function reads the JSON file (defined as filePath), parses out the values and updates variables with them.
The JSON file must be correctly formated. NO COMA after the last item!!!
*/

void updateSet() {

  byte bufferSize = 150; //define number of bytes expected on the JSON thread
  char json[bufferSize]; //create a char array buffer that is 150 bytes in size in this case

  //Opens a 'settings.json' text file on SD that has has a JSON string stored in filePath = /mnt/sd/arduino/www/[your_sketch_name]
  File dataFile = FileSystem.open(filePath, FILE_READ);
  dataFile.readBytes(json, bufferSize);
  dataFile.close();

  Console.println(json); //prints whatever JSON string values were read

  StaticJsonBuffer<JSON_OBJECT_SIZE(10)> jsonBuffer; //We know our JSON string just has 10 objects only and no arrays, so our buffer is set to handle that many
  JsonObject& root = jsonBuffer.parseObject(json);    // breaks the JSON string into individual items, saves into JsonObject 'root'

  if (!root.success()) {
    Console.println("parseObject() failed");
    return;   //if parsing failed, this will exit the function and not change the values to 00

  } else { // update variables

    waterDay = root["WI"];
    waterTime = writeTime( root["WH"] , root["WM"] , 0 );
    waterDuration = writeTime( root["WDH"] , root["WDM"] , root["WDS"] );
    waterEnd = addTime( waterTime, waterDuration);

    Console.print("waterTime: ");
    Console.println(waterTime);
    Console.print("waterDay: ");
    Console.println(waterDay);
    Console.println();

    counterWater = waterDay; //update day counters for irrigation


  }
}

