void checkSoil() {
  soilVal = analogRead(soilPin); //connect sensor to Analog 0
  Console.print(soilVal); //print the value to serial port
  Console.print("\t");
  
if(soilVal >= drySoil)
{
  Console.println("Parched");
}

else if(soilVal > wetSoil && soilVal < drySoil)
{
  Console.println("Dry");
} 

else if(soilVal > soakedSoil && soilVal < wetSoil)
{
  Console.println("Wet");
}

else if(soilVal > water && soilVal < soakedSoil)
{
  Console.println("Soaked");
}

else if(soilVal <= water)
{
  Console.println("Water");
}
  
}


