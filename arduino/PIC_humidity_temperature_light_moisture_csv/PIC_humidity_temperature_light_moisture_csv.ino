//This code exports raw data (no calclutaions performed) via Serial.
//We use this stream in Processing to provide real-time graphing of the data as part of a demo.

//For the sensor circuits we used the MAKE Garduino tutorial by Luke Iseman: 
//http://makeprojects.com/Project/Garduino-Geek-Gardening/62/1#.T9qApmhg9-c


//Sensor pins
int humidityPin = 7;  //  Humirel HS1101 sensor + 220 Ohm resistor
int temperaturePin = 5; // LM35DZ Temperature sensor
int lightPin = 1; // Photocell + 10k Ohm resistor
int moisturePin = 3; //Two galvanized nails + 10k Ohm resistor
int ledPin = 13;

//Sensor variables
int temperatureVal = 0;
int humidityVal = 0;
int lightVal = 0;
int moistureVal = 0;

//Constants, etc.
float voltage = 4.80;
const float Vsupply= 1024.0;
int waitTime = 0;
int loopTime = 200;

void setup()                    // run once, when the sketch starts
{
   Serial.begin(9600);
   Serial.println("4 Sensor Code v.10 Mar. 5, 2012");
   delay(2000);
}

void loop()                     // run over and over again
{
    readTemp();
    delay(waitTime);
    readHumidity();
    delay(waitTime);
    readLight();
    delay(waitTime);
    readMoisture();
    Serial.println();
      
  digitalWrite(ledPin, HIGH);
  delay(300);
  digitalWrite(ledPin, LOW);
  
  delay(loopTime);
  
}

float readHumidity() {
  float Vout = ( RCtime(humidityPin) );
  float relativeHumidity = (Vout/Vsupply)*100.0;
  int humidity = (int) relativeHumidity;
  //Serial.print("Humidity: ");
  Serial.print(humidity);
  //  Serial.write(37);
  Serial.print(",");

}

long RCtime(int sensPin) {
   long result = 0;
   pinMode(sensPin, OUTPUT);       // make pin OUTPUT
   digitalWrite(sensPin, HIGH);    // make pin HIGH to discharge capacitor - study the schematic
   delay(1);                       // wait a  ms to make sure cap is discharged

   pinMode(sensPin, INPUT);        // turn pin into an input and time till pin goes low
   digitalWrite(sensPin, LOW);     // turn pullups off - or it won't work
   while(digitalRead(sensPin)){    // wait for pin to go low
      result++;
   }
   return result;                   // report results   
}   

int readTemp() {
  temperatureVal = analogRead(temperaturePin); //read temeprature sensor
//  Serial.print(temperatureVal);
//  Serial.write(9); //tab
  temperatureVal = (voltage * temperatureVal * 100.0) / 1024.0; //calculate temperature in Celsius
//  Serial.write(9); //tab
//Serial.print("Temp: ");
  Serial.print(temperatureVal);
//  Serial.write(186);
  Serial.print(",");  
}

int readLight() {
  lightVal = analogRead(lightPin); //read photocell
//  lightVal = map(lightVal, 0, 1023, 0, 100); //convert value to %
//  Serial.write(9); //tab
  //Serial.print("Light: ");
  Serial.print(lightVal); //send value over serial
//  Serial.write(37);
  Serial.print(",");  
}

int readMoisture() {
 moistureVal = analogRead(moisturePin); //read moisture sensor
// moistureVal = map(moistureVal, 0, 1023, 0, 100); //convert value to %
// Serial.write(9); //tab
 //Serial.print("Moisture: ");
 Serial.print(moistureVal);
// Serial.write(37);
// Serial.print(",");
}
  
