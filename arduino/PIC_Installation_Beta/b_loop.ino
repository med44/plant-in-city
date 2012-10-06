//Main loop.
void loop(){
  
  Serial.print(zone);
  Serial.print(" ");
  readTempHumidity();
  delay(waitTime);
  readLight();
  delay(waitTime);
  readMoisture();
  delay(waitTime);
  readWaterLevel();
  Serial.println();
  
  Serial.print("CSV ");
  Serial.print(temperatureVal);
  Serial.print(", ");
  Serial.print(humidityVal);
  Serial.print(", ");
  Serial.print(lightVal);
  Serial.print(", ");
  Serial.print(moistureVal);
  Serial.print(", ");
  Serial.print(waterTankVal);
  Serial.println();
  
  delay(loopTime); // wait a bit
  
  
//Play sound effect
  playSFX2();
   
    
  digitalWrite(statusLedPin, HIGH);
  delay(statusLedTime);
  digitalWrite(statusLedPin, LOW);
  
  delay(loopTime);
  
}

