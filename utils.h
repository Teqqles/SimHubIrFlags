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

#ifndef debugutils
#define debugutils

// If you want to see what is going on under the hood
#define VERBOSE_SERIAL_OUTPUT false

void serialPrintPrefix(const char *prefix);
void debugPrintToSerial(const char *prefix, const char *text);
void debugPrintToSerial(const char *prefix, int body, int base);
#endif
