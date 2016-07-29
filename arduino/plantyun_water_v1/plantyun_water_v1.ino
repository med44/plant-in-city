// Needs to be uploaded to Yun via WiFi; Tool - Port - Network Ports - MyYun at 192.168...
// v4 has an intermittent valve trigger to prevent water drops from sticking to the same hole

//// UI/Web Server ////////////////////////
#include <Bridge.h>
#include <YunServer.h>
#include <YunClient.h>
#include <ArduinoJson.h> // for JSON parsing
#include <FileIO.h> // to work with files on the SD
#include <Console.h>

#define filePath "/mnt/sda1/arduino/www/plantyun_water_v1/settings.json" //where to find the JSON settings file

YunServer server;
char json;

//// TIME CHECK ////////////////////////
#include <Process.h>
Process date;                         // process used to get the date

// PIN Configuration
int waterPin = 8;
int groundPin = 10;

// DAY COUNTER
byte lastDay = 0;                   // will hold 'day' for comparison, to see when the days change
int thisDay;
int previousDay;

// TIME variables for comparisons
int thisSecond;
int previousSecond = -1;


// WATER timing variables //
String waterTime = "17:58:40";      // SET BY USER -  what time does the irrigation start
String waterDuration = "00:00:10";  // SET BY USER -  for how long is the water dripping
String waterEnd;                    // COUNTED by the addTime function; waterTime + waterDuration
boolean waterOn = 0;
byte waterDay = 1;                  // SET BY USER - water every [waterDay] days
byte sinceLastWaterDay = 0;         // counts days since last irrigation
byte counterWater;                     // counts how many days left of frequency period




//DEBUGGING
byte today = 1; //counts days of week 1-7
byte lastday; //to comapre if days changed
byte timer; //to pretend days pass quicker

/////////////////////////////////////////////////////////////////////////////

void setup() {
  Serial.begin(115200);
  Bridge.begin();           // initialize Bridge   
  Console.begin();          // initialize Console, (instead of Serial). Serial monitor sometimes works, otherwise in Terminal use: ssh root@MyArdunoYunName.local 'telnet localhost 6571'
 
  counterWater = waterDay; //make the counter be equal to the daily frequency 

  // UI / Web Server
 // server.listenOnLocalhost();
  server.begin();

  FileSystem.begin();
  if(filePath){ updateSet(); } // update the settings IF there is a file, else they will stay default    

  // WATER / RELAY setup
  pinMode(waterPin, OUTPUT); // relay operating 'driver'
  pinMode(groundPin, OUTPUT); // ground for relay
  digitalWrite(groundPin, LOW); // makes the pin act like GND

  
//  while (!Serial);              // wait for Serial Monitor to open
//  Serial.println("Time Check");  // Title of sketch 
//  
//    if (!date.running()) {
//    date.begin("date");
//    date.addParameter("+%u %d/%m/%Y %T");
//    date.run();
//  }
//  
//  Serial.print("previousSecond: ");
//  Serial.print(previousSecond);
//  Serial.print(" thisSecond: ");
//  Serial.println(thisSecond);

}



