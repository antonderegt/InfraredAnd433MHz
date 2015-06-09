// This sketch will send out a Nikon D50 trigger signal (probably works with most Nikons)
// See the full tutorial at http://www.ladyada.net/learn/sensors/ir.html
// this code is public domain, please enjoy!
 
int IRledPin = 6;    // LED connected to digital pin 6
 
#include <VirtualWire.h>
 
void setup() {                
  // initialize the IR digital pin as an output:
  pinMode(IRledPin, OUTPUT);  
  pinMode(13, OUTPUT);    
 
 // Serial.begin(9600);
  
//  Serial.println("setup");
  // Initialise the IO and ISR
  //vw_set_ptt_inverted(true);  // Required for DR3100
  vw_setup(2000);	      // Bits per sec
  vw_rx_start();              // Start the receiver PLL running
  
  TurnLedStripOn();
}
 
void loop() { 
  /*
  TurnLedStripOn();
  BrightnessMin();   
  BrightnessPlus();    
  TurnLedStripOff();  
  */
  
  uint8_t buf[VW_MAX_MESSAGE_LEN];
  uint8_t buflen = VW_MAX_MESSAGE_LEN;
  
  if (vw_get_message(buf, &buflen)) { // Non-blocking
    switch (buflen){
      case 2:
        vw_rx_stop();
        TurnLedStripOn();
        vw_rx_start();
        break;
      case 3:
        vw_rx_stop();
        TurnLedStripOff();
        vw_rx_start();
        break;
      case 13:
        vw_rx_stop();
        BrightnessMin();
        BrightnessMin();
        BrightnessMin();
        BrightnessMin();
        BrightnessMin();
        vw_rx_start();
        break;
      case 14:
        vw_rx_stop();
        BrightnessPlus();
        BrightnessPlus();
        BrightnessPlus();
        BrightnessPlus();
        BrightnessPlus();
        vw_rx_start();
        break;
      }
      
      /*
      int i;
      // Message with a good checksum received, dump it.
      Serial.print("Got: ");

      for (i = 0; i < buflen; i++){
	Serial.print((char)buf[i]);
      }
      Serial.println("");
      */
    }
}
 
// This procedure sends a 38KHz pulse to the IRledPin 
// for a certain # of microseconds. We'll use this whenever we need to send codes
void pulseIR(long microsecs) {
  // we'll count down from the number of microseconds we are told to wait
 
  cli();  // this turns off any background interrupts
 
  while (microsecs > 0) {
    // 38 kHz is about 13 microseconds high and 13 microseconds low
   digitalWrite(IRledPin, HIGH);  // this takes about 3 microseconds to happen
   delayMicroseconds(10);         // hang out for 10 microseconds
   digitalWrite(IRledPin, LOW);   // this also takes about 3 microseconds
   delayMicroseconds(10);         // hang out for 10 microseconds
 
   // so 26 microseconds altogether
   microsecs -= 26;
  }
 
  sei();  // this turns them back on
}
 
void TurnLedStripOn() {
  // This is the code for the CHANNEL + for the downstairs TV COMCAST
  delayMicroseconds(3936); //Time off (Left Column on serial monitor)
  pulseIR(8880);           //Time on  (Right Column on serial monitor)
  delayMicroseconds(4380);
  pulseIR(600);
  delayMicroseconds(500);
  pulseIR(600);
  delayMicroseconds(500);
  pulseIR(600);
  delayMicroseconds(500);
  pulseIR(600);
  delayMicroseconds(500);
  pulseIR(600);
  delayMicroseconds(500);
  pulseIR(600);
  delayMicroseconds(500);
  pulseIR(600);
  delayMicroseconds(500);
  pulseIR(600);
  delayMicroseconds(500);
  pulseIR(600);
  delayMicroseconds(1600);
  pulseIR(600);
  delayMicroseconds(1600);
  pulseIR(600);
  delayMicroseconds(1600);
  pulseIR(600);
  delayMicroseconds(1600);
  pulseIR(600);
  delayMicroseconds(500);
  pulseIR(600);
  delayMicroseconds(1600);
  pulseIR(600);
  delayMicroseconds(1600);
  pulseIR(600);
  delayMicroseconds(1600);
  pulseIR(600);
  delayMicroseconds(1600);
  pulseIR(600);
  delayMicroseconds(1600);
  pulseIR(600);
  delayMicroseconds(500);
  pulseIR(600);
  delayMicroseconds(500);
  pulseIR(600);
  delayMicroseconds(500);
  pulseIR(600);
  delayMicroseconds(500);
  pulseIR(600);
  delayMicroseconds(500);
  pulseIR(600);
  delayMicroseconds(500);
  pulseIR(600);
  delayMicroseconds(500);
  pulseIR(600);
  delayMicroseconds(500);
  pulseIR(600);
  delayMicroseconds(1600);
  pulseIR(600);
  delayMicroseconds(1600);
  pulseIR(600);
  delayMicroseconds(1600);
  pulseIR(600);
  delayMicroseconds(1600);
  pulseIR(600);
  delayMicroseconds(1600);
  pulseIR(600);
  delayMicroseconds(1600);
  pulseIR(600);
  delayMicroseconds(40240);
  pulseIR(8880);
  delayMicroseconds(2180);
  pulseIR(600);
}

void TurnLedStripOff() {
  // This is the code for the CHANNEL + for the downstairs TV COMCAST
  delayMicroseconds(25984); //Time off (Left Column on serial monitor)
  pulseIR(8900);           //Time on  (Right Column on serial monitor)
  delayMicroseconds(4380);
  pulseIR(600);
  delayMicroseconds(500);
  pulseIR(600);
  delayMicroseconds(500);
  pulseIR(600);
  delayMicroseconds(500);
  pulseIR(600);
  delayMicroseconds(500);
  pulseIR(600);
  delayMicroseconds(500);
  pulseIR(600);
  delayMicroseconds(500);
  pulseIR(600);
  delayMicroseconds(500);
  pulseIR(600);
  delayMicroseconds(500);
  pulseIR(600);
  delayMicroseconds(1600);
  pulseIR(600);
  delayMicroseconds(1600);
  pulseIR(600);
  delayMicroseconds(1600);
  pulseIR(600);
  delayMicroseconds(1600);
  pulseIR(600);
  delayMicroseconds(500);
  pulseIR(600);
  delayMicroseconds(1600);
  pulseIR(600);
  delayMicroseconds(1600);
  pulseIR(600);
  delayMicroseconds(1600);
  pulseIR(600);
  delayMicroseconds(500);
  pulseIR(600);
  delayMicroseconds(1600);
  pulseIR(600);
  delayMicroseconds(500);
  pulseIR(600);
  delayMicroseconds(500);
  pulseIR(600);
  delayMicroseconds(500);
  pulseIR(600);
  delayMicroseconds(500);
  pulseIR(600);
  delayMicroseconds(500);
  pulseIR(600);
  delayMicroseconds(500);
  pulseIR(600);
  delayMicroseconds(1600);
  pulseIR(600);
  delayMicroseconds(500);
  pulseIR(600);
  delayMicroseconds(1600);
  pulseIR(600);
  delayMicroseconds(1600);
  pulseIR(600);
  delayMicroseconds(1600);
  pulseIR(600);
  delayMicroseconds(1600);
  pulseIR(600);
  delayMicroseconds(1600);
  pulseIR(600);
  delayMicroseconds(1600);
  pulseIR(600);
  delayMicroseconds(40240);
  pulseIR(8880);
  delayMicroseconds(2180);
  pulseIR(600);
}

void BrightnessPlus() {
  // This is the code for the CHANNEL + for the downstairs TV COMCAST
  delayMicroseconds(25984); //Time off (Left Column on serial monitor)
  pulseIR(8900);           //Time on  (Right Column on serial monitor)
  delayMicroseconds(4380);
  pulseIR(600);
  delayMicroseconds(500);
  pulseIR(600);
  delayMicroseconds(500);
  pulseIR(600);
  delayMicroseconds(500);
  pulseIR(600);
  delayMicroseconds(500);
  pulseIR(600);
  delayMicroseconds(500);
  pulseIR(600);
  delayMicroseconds(500);
  pulseIR(600);
  delayMicroseconds(500);
  pulseIR(600);
  delayMicroseconds(500);
  pulseIR(600);
  delayMicroseconds(1600);
  pulseIR(600);
  delayMicroseconds(1600);
  pulseIR(600);
  delayMicroseconds(1600);
  pulseIR(600);
  delayMicroseconds(1600);
  pulseIR(600);
  delayMicroseconds(500);
  pulseIR(600);
  delayMicroseconds(1600);
  pulseIR(600);
  delayMicroseconds(1600);
  pulseIR(600);
  delayMicroseconds(1600);
  pulseIR(600);
  delayMicroseconds(500);
  pulseIR(600);
  delayMicroseconds(500);
  pulseIR(600);
  delayMicroseconds(500);
  pulseIR(600);
  delayMicroseconds(500);
  pulseIR(600);
  delayMicroseconds(500);
  pulseIR(600);
  delayMicroseconds(500);
  pulseIR(600);
  delayMicroseconds(500);
  pulseIR(600);
  delayMicroseconds(500);
  pulseIR(600);
  delayMicroseconds(1600);
  pulseIR(600);
  delayMicroseconds(1600);
  pulseIR(600);
  delayMicroseconds(1600);
  pulseIR(600);
  delayMicroseconds(1600);
  pulseIR(600);
  delayMicroseconds(1600);
  pulseIR(600);
  delayMicroseconds(1600);
  pulseIR(600);
  delayMicroseconds(1600);
  pulseIR(600);
  delayMicroseconds(1600);
  pulseIR(600);
  delayMicroseconds(40240);
  pulseIR(8880);
  delayMicroseconds(2180);
  pulseIR(600);
}

void BrightnessMin() {
  // This is the code for the CHANNEL + for the downstairs TV COMCAST
  delayMicroseconds(25984); //Time off (Left Column on serial monitor)
  pulseIR(8900);           //Time on  (Right Column on serial monitor)
  delayMicroseconds(4380);
  pulseIR(600);
  delayMicroseconds(500);
  pulseIR(600);
  delayMicroseconds(500);
  pulseIR(600);
  delayMicroseconds(500);
  pulseIR(600);
  delayMicroseconds(500);
  pulseIR(600);
  delayMicroseconds(500);
  pulseIR(600);
  delayMicroseconds(500);
  pulseIR(600);
  delayMicroseconds(500);
  pulseIR(600);
  delayMicroseconds(500);
  pulseIR(600);
  delayMicroseconds(1600);
  pulseIR(600);
  delayMicroseconds(1600);
  pulseIR(600);
  delayMicroseconds(1600);
  pulseIR(600);
  delayMicroseconds(1600);
  pulseIR(600);
  delayMicroseconds(500);
  pulseIR(600);
  delayMicroseconds(1600);
  pulseIR(600);
  delayMicroseconds(1600);
  pulseIR(600);
  delayMicroseconds(1600);
  pulseIR(600);
  delayMicroseconds(1600);
  pulseIR(600);
  delayMicroseconds(500);
  pulseIR(600);
  delayMicroseconds(500);
  pulseIR(600);
  delayMicroseconds(500);
  pulseIR(600);
  delayMicroseconds(500);
  pulseIR(600);
  delayMicroseconds(500);
  pulseIR(600);
  delayMicroseconds(500);
  pulseIR(600);
  delayMicroseconds(500);
  pulseIR(600);
  delayMicroseconds(500);
  pulseIR(600);
  delayMicroseconds(1600);
  pulseIR(600);
  delayMicroseconds(1600);
  pulseIR(600);
  delayMicroseconds(1600);
  pulseIR(600);
  delayMicroseconds(1600);
  pulseIR(600);
  delayMicroseconds(1600);
  pulseIR(600);
  delayMicroseconds(1600);
  pulseIR(600);
  delayMicroseconds(1600);
  pulseIR(600);
  delayMicroseconds(40240);
  pulseIR(8880);
  delayMicroseconds(2180);
  pulseIR(600);
}
