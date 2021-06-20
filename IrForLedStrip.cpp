/*
 *
 *  Copyright (C) 2021  David Long
 *  Email: teqqles@gmail.com
 *
 *  This file is part of SimHubIrFlags
 *
 *  SimHubIrFlags is free software: you can redistribute it and/or modify
 *  it under the terms of the MIT license.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, 
 *  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 *  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 *  IN NO EVENT SHALL DAVID LONG BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER 
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 *  FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER 
 *  DEALINGS IN THE SOFTWARE.
 *
 *  You should have received a copy of the MIT license along with this 
 *  program. If not, see:
 *  <https://github.com/Teqqles/SimHubIrFlags/LICENSE>.
 *
 */

#include "IrForLedStrip.h"
#include "Utils.h"
#include <Arduino.h>
#include <IRremote.h>

void IrForLedStrip::setup(){
  delay(4000); // To be able to connect Serial monitor after reset or power up and before first print out. Do not wait for an attached Serial Monitor!
  
  Serial.println(F("START " __FILE__ " from " __DATE__ "\r\nUsing library version " VERSION_IRREMOTE)); // Just to know which program is running

  IrSender.begin(IR_SEND_PIN, ENABLE_LED_FEEDBACK); // Specify send pin and enable feedback LED at default feedback LED pin

  Serial.print(F("Ready to send IR signals at pin "));
#if defined(ARDUINO_ARCH_STM32) || defined(ESP8266)
  Serial.println(IR_SEND_PIN_STRING);
#else
  Serial.println(IR_SEND_PIN);
#endif
#if not defined(DISABLE_POWER_ON)
  sendNecColors(remoteCodes.power);
#endif
  sendNecColors(remoteCodes.neutral); // Power on and put us in a neutral color
}

void IrForLedStrip::sendNecColors(IrFlag color) {
#if defined(VERBOSE_SERIAL_OUTPUT)
  debugPrintToSerial("IR Code: ", color.mainCode, HEX);
#endif 
  IrSender.sendNECMSB(color.mainCode, 32);
}

void IrForLedStrip::sendNecColors(IrFlag color, IrFlag flash) {
  sendNecColors(color);
  if (color.useFlash) {
    sendNecColors(flash);
  }
}

void IrForLedStrip::showFlag(IrFlag color) {
  sendNecColors(color, remoteCodes.flash);
}

void IrForLedStrip::demoPattern(){
#if not defined(DISABLE_POWER_ON)
  debugPrintToSerial("Power On");
  sendNecColors(remoteCodes.power);
  delay(2000);  
#else
  debugPrintToSerial("Power On disabled");	
#endif	
  debugPrintToSerial("Red Flag");
  sendNecColors(remoteCodes.red, remoteCodes.flash);
  delay(2000);
  debugPrintToSerial("Pink Flag");
  sendNecColors(remoteCodes.pink, remoteCodes.flash);
  delay(2000);  
  debugPrintToSerial("Yellow Flag");
  sendNecColors(remoteCodes.yellow, remoteCodes.flash);
  delay(2000); 
  debugPrintToSerial("Orange Flag");
  sendNecColors(remoteCodes.orange, remoteCodes.flash);
  delay(2000);    
  debugPrintToSerial("White Flag - Slow Car/Final Lap");
  sendNecColors(remoteCodes.white, remoteCodes.flash);  
  delay(2000);  
  debugPrintToSerial("Green Flag");
  sendNecColors(remoteCodes.green, remoteCodes.flash);
  delay(2000);    
  debugPrintToSerial("Blue Flag");
  sendNecColors(remoteCodes.blue, remoteCodes.flash);  
  delay(2000);    
  debugPrintToSerial("Neutral State");
  sendNecColors(remoteCodes.neutral, remoteCodes.flash);  
  delay(2000);     
  debugPrintToSerial("End of cycle");
}
