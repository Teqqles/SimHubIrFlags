#include "utils.h"
#include <Arduino.h>

void serialPrintPrefix(const char *prefix) {
  if(!isblank(prefix)) {
    Serial.print(prefix);  
  }
}

void debugPrintToSerial(const char *prefix, const char *text) {
  if (VERBOSE_SERIAL_OUTPUT) {
    serialPrintPrefix(prefix);
    Serial.println(text);
  }
}

void debugPrintToSerial(const char *prefix, int body, int base) {
  if (VERBOSE_SERIAL_OUTPUT) {
    serialPrintPrefix(prefix);
    Serial.println(body, base);
  }
}
