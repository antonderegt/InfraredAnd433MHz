// This sketch will send out a Nikon D50 trigger signal (probably works with most Nikons)
// See the full tutorial at http://www.ladyada.net/learn/sensors/ir.html
// this code is public domain, please enjoy!
 
int IRledPin = 6;    // LED connected to digital pin 6
 
#include <VirtualWire.h>
 
void setup() {                
  // initialize the IR digital pin as an output:
  pinMode(IRledPin, OUTPUT);  
  pinMode(13, OUTPUT);    
 
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
    flashLed();
    switch (buflen){
      case 2:
        vw_rx_stop();
        TurnLedStripOn();
        TurnLedStripOn();
        TurnLedStripOn();
        vw_rx_start();
        break;
      case 3:
        vw_rx_stop();
        TurnLedStripOff();
        TurnLedStripOff();
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
    }
}

void flashLed(){
  digitalWrite(13, HIGH);
  delay(50);
  digitalWrite(13, LOW);
  delay(50);
  digitalWrite(13, HIGH);
  delay(50);
  digitalWrite(13, LOW);
  delay(50);
  digitalWrite(13, HIGH);
  delay(50);
  digitalWrite(13, LOW);
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
