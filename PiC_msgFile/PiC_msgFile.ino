// Needs to be uploaded to Yun via WiFi; Tool - Port - Network Ports - MyYun at 192.168...

#include <Bridge.h>
#include <YunServer.h>
#include <YunClient.h>

#include <FileIO.h>
#define filePath "/mnt/sd/arduino/www/PiC_msgFile/settings.txt"

YunServer server;

void setup () {

  Serial.begin(9600);
  Bridge.begin();
  server.listenOnLocalhost();
  server.begin();
  Console.begin();  

}
 
void loop () {

// update settings.txt when prompted from the UI
  YunClient client = server.accept();    //puts the message comming from outside (server.accept) to var 'client'
  
  if(client) {     // if there is something in 'client' it means there is an incomming message
    
    String input = client.readString();  //load msg to a variable input  
    Console.println(input);
    
    FileSystem.remove(filePath);  //remove the current settings file
    Console.println("deleted");
    
    File dataFile = FileSystem.open(filePath, FILE_WRITE); //create the new file and open it for adding
    dataFile.println(input);
    
    Console.println("Settings updated!");

    dataFile.close();
    client.stop();    
  } 
    
  delay(150);
}
