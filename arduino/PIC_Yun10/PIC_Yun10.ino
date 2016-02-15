// Needs to be uploaded to Yun via WiFi; Tool - Port - Network Ports - MyYun at 192.168...

//// UI/Web Server ////////////////////////
#include <Bridge.h>
#include <YunServer.h>
#include <YunClient.h>
#include <Console.h>
#include <ArduinoJson.h> // for JSON parsing
#include <FileIO.h> // to work with files on the SD

#define filePath "/mnt/sd/arduino/www/PIC_Yun10/settings.json" //where to find the JSON settings file

YunServer server;



//// TIME CHECK ////////////////////////
#include <Process.h>
Process date;                         // process used to get the date

// DAY COUNTER
byte lastDay = 0;                   // will hold 'day' for comparison, to see when the days change

// LIGHT timing variables //
boolean lightOn = false;
byte lightDay = 1;                  // SET BY USER - light every [lightDay] days
byte sinceLastLightDay = 0;         // counts days since last irrigation

String lightTime = "18:00:00";      // SET BY USER -  what time does the irrigation start
String lightDuration = "00:01:00";  // SET BY USER -  for how long is the light dripping
String lightEnd;                    // COUNTED by the addTime function; lightTime + lightDuration

// WATER timing variables //
boolean waterOn = false;
byte waterDay = 1;                  // SET BY USER - water every [waterDay] days
byte sinceLastWaterDay = 0;         // counts days since last irrigation

String waterTime = "10:00:00";      // SET BY USER -  what time does the irrigation start
String waterDuration = "00:00:05";  // SET BY USER -  for how long is the water dripping
String waterEnd;                    // COUNTED by the addTime function; waterTime + waterDuration

///Other Variables   
int incomingByte; //for Console debugging tools

// Adafruit_NeoPixel shield ////////////////////////
#include <Adafruit_NeoPixel.h>
#include <avr/power.h>

#define PIN            6            // Which pin on the Arduino is connected to the NeoPixels?
#define NUMPIXELS      40           // How many NeoPixels are attached to the Arduino?

int blueRatio = 7;                  //How often do we add a blue pixel in the array? Most grow lights do every 5, 7 or 8 red leds to 1 blue led.
int bluePixel = 0;
int lightFlag = 0;
int blueLEDs [] = {9, 14, 19, 20, 25, 30};

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800); // instance of Adafruit_NeoPixel called "pixels"

/////////////////////////////////////////////////////////////////////////////

void setup() {
  Bridge.begin();           // initialize Bridge   
  Console.begin();          // initialize Console, (instead of Serial). Serial monitor sometimes works, otherwise in Terminal use: ssh root@MyArdunoYunName.local 'telnet localhost 6571'

  Console.println("Plant-in City starting up...");

   // UI / Web Server
//  server.listenOnLocalhost();
  server.begin();
  Console.println("Web server is up.");
  
  delay(500);

  FileSystem.begin();
  if(filePath){   // update the settings IF there is a file, else they will stay default
    updateSet(); 
    Console.println("Settings are updated.");
  } 


  // WATER / RELAY setup
  pinMode(8, OUTPUT); // relay operating 'driver'
  pinMode(10, OUTPUT); // ground for relay
  digitalWrite(10, LOW); // makes the pin act like GND

  // LIGHT setup
  pixels.begin(); // This initializes the NeoPixel library.
  pixels.show(); // Initialize all pixels to 'off'

  sayHi(); // indicates finish of the setup by blinking blue lights
  Console.println("Lights tested.");


}



