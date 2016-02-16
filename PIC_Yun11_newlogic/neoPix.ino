// NEOPIX Custom Functions
void lightsOff() {
  for (int i = 0; i < NUMPIXELS; i++) {
   // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, pixels.Color(0, 0, 0)); // off
    pixels.show(); // This sends the updated pixel color to the hardware.
  }
}

void redLights() {

  //Serial.println("Red ");

  for (int i = 0; i < NUMPIXELS; i++) {

    //Serial.println(i);

    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, pixels.Color(255, 0, 0)); // Moderately bright green color.
    pixels.show(); // This sends the updated pixel color to the hardware.

  }
}

void blueLights() {

  //Serial.println("Blue ");

  for (int i = 0; i < 6; i++) {
 //   Serial.println(blueLEDs[i]);
    pixels.setPixelColor(blueLEDs[i], pixels.Color(0, 0, 255));
    pixels.show();
  }
}

void sayHi(){     // function for indicating changes, finished setup, etc.
  
  blueLights();
  delay(200);
  lightsOff();
  
  }
