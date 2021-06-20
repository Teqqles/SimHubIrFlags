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
#include <IRremoteInt.h>
#include <ArduinoJson.h>

IrForLedStrip strip;
StaticJsonDocument<100> flagDoc;

void setup() {
  Serial.begin(115200);
  while (!Serial) continue; // wait for serial...
  strip.setup();
}

void loop() {
  if (Serial.available() > 0) // we have bytes for reading
  {
    String stringifiedJson = Serial.readStringUntil('\n');

    DeserializationError error = deserializeJson(flagDoc, stringifiedJson);
    if (error) {
      Serial.print("deserializeJson() failed: ");
      Serial.println(error.c_str());
      return;
    };
    const char *flagValue = flagDoc["flag"];
    if (strcmp(flagValue, "R") == 0) {
      strip.showFlag(remoteCodes.red);	
    } else if (strcmp(flagValue, "B") == 0) {
      strip.showFlag(remoteCodes.blue);
    } else if (strcmp(flagValue, "Y") == 0) {
      strip.showFlag(remoteCodes.yellow);
    } else if (strcmp(flagValue, "O") == 0) {
      strip.showFlag(remoteCodes.orange);	  
    } else if (strcmp(flagValue, "P") == 0) {
      strip.showFlag(remoteCodes.pink);   
    } else if (strcmp(flagValue, "G") == 0) {
      strip.showFlag(remoteCodes.green);
    } else if (strcmp(flagValue, "W") == 0) {
      strip.showFlag(remoteCodes.white);
    } else if (strcmp(flagValue, "D") == 0) { // not a flag but who doesn't like a demo?
      strip.demoPattern();       
    } else { // not a valid flag code so we switch back to neutral
      strip.showFlag(remoteCodes.neutral);
    }
    Serial.print("flag updated to :");
    Serial.println(flagValue);   
  }
}
