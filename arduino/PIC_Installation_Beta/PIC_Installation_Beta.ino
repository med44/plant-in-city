// PLANT-IN CITY 
// This code is our basis for the Plant-in City project.
// It shows how we are structuring the different aspects of the interactions.
// Version: Beta1
// Date: 08/31/12
// www.plantincity.com
// info@plantincity.com
//
// ===================
// In this tab we declare global variables, defines, libraries and includes.

//Includes
//#include <Time.h>                                    // timer libraries
//#include <TimeAlarms.h>                              // timer libraries
#include <GinSing.h>                                 // interface header file
#include <DHT22.h>                                   // RHT03 Temperature & Humidity Sensor library
#include <stdio.h>                                   // Only used for sprintf (RTH03)

///////////////////////////////////////////////////////
//SENSORS

// RHT03 Temperature & Humidity =======================
// Plug data wire into  Pin 7
// Connect a 4.7K resistor between VCC and the data pin (strong pullup)
#define DHT22_PIN 7                                  // declares Pin 7 as the RHT03 sensor pin
DHT22 myDHT22(DHT22_PIN);                            // Setup a DHT22 instance

// Photocell ==========================================
// Plug data wire into  Pin A4 
// Connect a 10K resistor between VCC and GND
#define lightPin 4                                    // declares Pin A4  as the photocell sensor pin 

// SEN0114 Moisture Sensor ============================
// Plug data wire into  Pin A5 
#define moisturePin 5                                 // declares Pin A5  as the moisture sensor pin 

// HC-SR04 Ultrasonic Range Sensor (Water Tank Level)==
// Plug Trigger wire to pin A2
// Plug Echo wire to pin A3
#define trigPin 16
#define echoPin 17  


// Status LED =========================================
// Plug LED to Pin 8
#define statusLedPin 8                               // declares Pin 12  as the LED pin 

///////////////////////////////////////////////////////
// VARIABLES
// Sensor values
int temperatureVal = 0;                               
int humidityVal = 0;
int lightVal = 0;
int moistureVal = 0;
int waterTankVal = 0;


// Constants
char zone = 'A';                                    // Plant-in City installation has 4 zones (A-D)
int waitTime = 0;
int loopTime = 2500;
int statusLedTime = 500;



// ====================
// GinSing Shield settings. For more info visit http://www.ginsingsound.com/
GinSing  GS;                                         // create the class library from which all methods and data are accessed
GinSingSynth *s;                                     // our global pointer to the synth mode interface ( set up after initialization )

#define rcvPin  4                                    // this is the pin used for receiving    ( can be either 4 or 12 )
#define sndPin  3                                    // this is the pin used for transmitting ( can be either 3 or 11 ) 
#define ovfPin  2                                    // this is the pin used for overflow control ( can be either 2 or 10 )
