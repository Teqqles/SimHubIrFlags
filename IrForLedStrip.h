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

#ifndef irforled
#define irforled
 
// Change this if you want to use a different output pin
#define IR_SEND_PIN 10

// What kind of remote does your strip use? uncomment the one you use
//#define REMOTE_24_KEY
#define REMOTE_44_KEY

#define DISABLE_POWER_ON /* Some remotes share power on/off functions so we provide
                            a way to disable this if you have trouble.  Comment this
                            if you'd like your led strip to switch itself on before
                            every game.	*/

struct IrFlag {
  unsigned long mainCode;
  bool useFlash;
};

struct IrFlags {
  IrFlag power;   // Code used to switch on the lights and set to a default color
  IrFlag neutral; // What color to set when no flag is out
  IrFlag red;     // Color to use when the race is stopped
  IrFlag pink;    // Color to use when enforced slow down in effect
  IrFlag yellow;  // Caution
  IrFlag orange;  // Black and orange?
  IrFlag white;   // Slow car
  IrFlag green;   // Hazard over
  IrFlag blue;    // Faster car behind
  IrFlag flash;   // Used with yellow/white flags
};

#ifdef REMOTE_24_KEY
const IrFlags remoteCodes {
  {0xF7C03F, false},
  {0xF7E01F, false},
  {0xF720DF, false},
  {0xF76897, false},
  {0xF728D7, true}, // yellow with flash
  {0xF710EF, false},  
  {0xF7E01F, true}, // white with flash
  {0xF7A05F, false},
  {0xF7609F, false},
  {0xF7D02F, false}
};
// color codes can be found @
// https://i0.wp.com/woodsgood.ca/projects/wp-content/uploads/24keyIRRemoteCodes.jpg
#elif defined REMOTE_44_KEY
const IrFlags remoteCodes {
  {0xFF02FD, false},
  {0xFF22DD, false},
  {0xFF1AE5, false},
  {0xFF58A7, false},
  {0xFF18E7, false}, // on my 44 button LED strip flash is always white so disabled
  {0xFF0AF5, false},
  {0xFF22DD, true}, // white with flash
  {0xFFA25D, false},
  {0xFFD02F, false}
};
// color codes can be found @
// https://i1.wp.com/woodsgood.ca/projects/wp-content/uploads/44keyIRRemoteCodes.jpg
#endif

class IrForLedStrip {
  public:
    void setup();
    void showFlag(IrFlag color);
    void demoPattern();  
  private:
    void sendNecColors(IrFlag color);
    void sendNecColors(IrFlag color, IrFlag flash);
};
 
#endif
