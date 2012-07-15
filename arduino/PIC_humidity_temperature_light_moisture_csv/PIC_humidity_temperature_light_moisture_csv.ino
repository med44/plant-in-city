//Uses the Humirel HS1101 sensor connected to Pin 7

//Sensor pins
int humidityPin = 7;  // 220 Ohm resistor connected to this pin
int temperaturePin = 5;
int lightPin = 1;
int moisturePin = 3;
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
  
