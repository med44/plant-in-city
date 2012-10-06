//Functions for reading sensor data.


int readTempHumidity() { 
  DHT22_ERROR_t errorCode;
  
  // The sensor can only be read from every 1-2s, and requires a minimum
  // 2s warm-up after power-on.
  delay(100);
  
//  Serial.print("Requesting data...");
  errorCode = myDHT22.readData();
  switch(errorCode)
  {
    case DHT_ERROR_NONE:
//      Serial.print("Got Data ");
      temperatureVal = myDHT22.getTemperatureC();
//      Serial.print("C ");
      humidityVal = myDHT22.getHumidity();
//      Serial.print("% RH");
      // Alternately, with integer formatting which is clumsier but more compact to store and
	  // can be compared reliably for equality:
	  //	  
      char buf[128];
      sprintf(buf, "%hi.%01hi C, %i.%01i %% RH, ",
                   myDHT22.getTemperatureCInt()/10, abs(myDHT22.getTemperatureCInt()%10),
                   myDHT22.getHumidityInt()/10, myDHT22.getHumidityInt()%10);
      Serial.print(buf);
      break;
    case DHT_ERROR_CHECKSUM:
      Serial.print("check sum error ");
      Serial.print(myDHT22.getTemperatureC());
      Serial.print("C ");
      Serial.print(myDHT22.getHumidity());
      Serial.println("%");
      break;
    case DHT_BUS_HUNG:
      Serial.println("BUS Hung ");
      break;
    case DHT_ERROR_NOT_PRESENT:
      Serial.println("Not Present ");
      break;
    case DHT_ERROR_ACK_TOO_LONG:
      Serial.println("ACK time out ");
      break;
    case DHT_ERROR_SYNC_TIMEOUT:
      Serial.println("Sync Timeout ");
      break;
    case DHT_ERROR_DATA_TIMEOUT:
      Serial.println("Data Timeout ");
      break;
    case DHT_ERROR_TOOQUICK:
      Serial.println("Polled to quick ");
      break;
  }
}


int readLight() {
  lightVal = analogRead(lightPin); //read photocell
  lightVal = map(lightVal, 0, 1023, 0, 100); //convert value to %
//  Serial.write(9); //tab
  //Serial.print("Light: ");
  Serial.print(lightVal); //send value over serial
  Serial.write(37);
  Serial.print(" Lx, ");
}


int readMoisture() {
 moistureVal = analogRead(moisturePin); //read moisture sensor
 moistureVal = map(moistureVal, 0, 1023, 0, 100); //convert value to %
// Serial.write(9); //tab
 //Serial.print("Moisture: ");
 Serial.print(moistureVal);
 Serial.write(37);
 Serial.print(" RM, ");
}

int readWaterLevel() {       //read ultrasonic sensor in water tank
  int duration, distance;
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  waterTankVal = distance;
  if (distance >= 200 || distance <= 0){
    Serial.print("Out of range");
  }
  else {
    Serial.print(distance);
    Serial.print(" cm, ");
  }
//  delay(500);  
}
