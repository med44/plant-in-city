// Setup the sketch and initialize variables. 
void setup()                    // run once, when the sketch starts
{
   Serial.begin(9600);
   Serial.println("Plant-in City Installation Beta");
   Serial.println("============================================");
   delay(2000);
   
   pinMode(statusLedPin, OUTPUT);
   pinMode(trigPin, OUTPUT);
   pinMode(echoPin, INPUT);
   
   
//--Start the GinSing shield----------------------   
   GS.begin ( rcvPin , sndPin , ovfPin );             // start the device (required)  
   s = GS.getSynth();                                 // get the synth mode interface
   s->begin ();                                       // enter synth mode 
   GS.end();                                          // end the device
      
}
