//Functions for playing out sounds from the GinSing shield.

void playSFX1() {
  
  s = GS.getSynth();                                                     // get the synth mode interface
  s->begin ();                                                           // enter synth mode

// Set mixer mode  
  s->selectBank   ( BANK_A );					                                                                               
  s->setPatch     ( OSC_1_TO_MIXER | OSC_3_FRQMOD_OSC_1 );              // patch osc 1 to mixer, and set osc 3 to frequency modulate osc 1                                                                        

// Oscillator 1
  s->setFrequency ( OSC_1 , lightVal );                                  // sets the oscillator based on the amount of light
  s->setAmplitude ( OSC_1 , 1.0f );                                     // set amplitude to full volume
  s->setWaveform  ( OSC_1 , TRIANGLE ); 

// Oscillator 3  
  s->setWaveform  ( OSC_3 , SAWTOOTH );			                // set the FM oscillator (3) as a sine wave
  s->setWavemode  ( OSC_3 , POSITIVE );				        // set the FM oscillator (3) to go from zero to full (no zero crossing)                                                                        
  s->setFrequency ( OSC_3 , 50.0f );					// set the FM oscillator (3) period to 1 second
  s->setAmplitude ( OSC_3 , 1.0f );                                     // set the FM oscillator (3) to full frequency range of modulation
  
  delay(1000);
  
  int halfTone = lightVal * 0.3;
  s->setFrequency ( OSC_1 , halfTone );                                  // set the oscillator to 120 Hz
  s->setWaveform  ( OSC_1 , SINE );  delay(1000);  
    
  s->setAmplitude ( OSC_1 , 0.0f );                                     // set amplitude to zero (off)
  delay (5000);	                                                        // one second of silence	
  
//    GS.end(); 
  
}


void playSFX2() {
  
  s = GS.getSynth();                                                     // get the synth mode interface
  s->begin ();                                                           // enter synth mode

// Set mixer mode  
  s->selectBank   ( BANK_A );					                                                                               
  s->setPatch     ( OSC_1_TO_MIXER );              // patch osc 1 to mixer, and set osc 3 to frequency modulate osc 1                                                                        

// Oscillator 1
  s->setFrequency ( OSC_1 , lightVal );                                  // sets the oscillator based on the amount of light
  s->setAmplitude ( OSC_1 , 1.0f );                                     // set amplitude to full volume
  s->setWaveform  ( OSC_1 , SINE ); 

  delay(1000);
  
  int halfTone = lightVal * 2.3;
  s->setFrequency ( OSC_1 , halfTone );                                  // set the oscillator to 120 Hz
  s->setWaveform  ( OSC_1 , SINE );  delay(1000);  
    
  s->setAmplitude ( OSC_1 , 0.0f );                                     // set amplitude to zero (off)
  delay (5000);	                                                        // one second of silence	
  
//    GS.end(); 
  
}
