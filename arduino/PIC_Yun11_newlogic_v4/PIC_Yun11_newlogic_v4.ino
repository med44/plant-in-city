// Needs to be uploaded to Yun via WiFi; Tool - Port - Network Ports - MyYun at 192.168...
// v4 has an intermittent valve trigger to prevent water drops from sticking to the same hole

//// UI/Web Server ////////////////////////
#include <Bridge.h>
#include <YunServer.h>
#include <YunClient.h>
#include <ArduinoJson.h> // for JSON parsing
#include <FileIO.h> // to work with files on the SD
#include <Console.h>

#define filePath "/mnt/sda1/arduino/www/PIC_Yun11_newlogic_v4/settings.json" //where to find the JSON settings file

YunServer server;
char json;

//// TIME CHECK ////////////////////////
#include <Process.h>
Process date;                         // process used to get the date

// DAY COUNTER
byte lastDay = 0;                   // will hold 'day' for comparison, to see when the days change
int thisDay;
int previousDay;

// TIME variables for comparisons
int thisSecond;
int previousSecond = -1;
byte sinceLastLightDay = 0;

// LIGHT timing variables //
String lightTime = "19:01:00";
String lightDuration = "00:00:20";
String lightEnd;
byte lightOn = 0;
byte lightDay = 3;                      // SET BY USER - light every [lightDay] days
byte counterLight;                     // counts how many days left of frequency period

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
  Serial.begin(115200);
  Bridge.begin();           // initialize Bridge   
  Console.begin();          // initialize Console, (instead of Serial). Serial monitor sometimes works, otherwise in Terminal use: ssh root@MyArdunoYunName.local 'telnet localhost 6571'
 
  counterLight = lightDay; //make the counter be equal to the daily frequency 
  counterWater = waterDay;

  // UI / Web Server
 // server.listenOnLocalhost();
  server.begin();

  FileSystem.begin();
  if(filePath){ updateSet(); } // update the settings IF there is a file, else they will stay default    

  // WATER / RELAY setup
  pinMode(8, OUTPUT); // relay operating 'driver'
  pinMode(10, OUTPUT); // ground for relay
  digitalWrite(10, LOW); // makes the pin act like GND

  // LIGHT setup
  pixels.begin(); // This initializes the NeoPixel library.
  pixels.show(); // Initialize all pixels to 'off'

  sayHi(); // indicates finish of the setup by blinking blue lights
  
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



