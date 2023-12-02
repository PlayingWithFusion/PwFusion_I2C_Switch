/***************************************************************************
* File Name: PwFusion_I2C_Switch.ino
* Processor/Platform: ATtiny841-MMHR (tested)
* Development Environment: Arduino 2.1.1
*
* Designed for use with with Playing With Fusion IFB-40004 I2C Switch
* Copyright � 2023 Playing With Fusion, Inc.
* SOFTWARE LICENSE AGREEMENT: This code is released under the MIT License.
*
* Permission is hereby granted, free of charge, to any person obtaining a
* copy of this software and associated documentation files (the "Software"),
* to deal in the Software without restriction, including without limitation
* the rights to use, copy, modify, merge, publish, distribute, sublicense,
* and/or sell copies of the Software, and to permit persons to whom the
* Software is furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
* FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
* DEALINGS IN THE SOFTWARE.
* **************************************************************************
* REVISION HISTORY:
* Author		    Date		    Comments
* N. Johnson    2023Oct1   Original version
*
* Playing With Fusion, Inc. invests time and resources developing open-source
* code. Please support Playing With Fusion and continued open-source
* development by buying products from Playing With Fusion!
*
* **************************************************************************
* ADDITIONAL NOTES:
* This file contains functions to flash an AtTiny841-MMHR included in
* the Playing with Fusion i2c toggle switch interface board (IFB-40004).
* Funcionality is as described below:
*   - Read values from the toggle switch componet
*   - Pack values into a register struct
*   - Send values over the i2c bus when requested
***************************************************************************/

#include <WireS.h>
#include <ezButton.h>


uint8_t address0 = 0x13;    // Uncut Address
uint8_t address1 = 0x14;  // Cut Address

// Define pins
#define SW 0
#define ADR_SEL 9

ezButton button(SW);

struct memoryMap {
  uint8_t sw;
};

volatile memoryMap registerMap = {
  .sw = 0x00,
};

// Create a pointer so the register number refers to data in the registerMap.
uint8_t *registerPointer = (uint8_t *)&registerMap;



volatile byte registerPosition;


int btnState;

void setup() {

  pinMode(ADR_SEL, INPUT);

  startI2C();

  button.setDebounceTime(5); // set debounce time to 50 milliseconds

};

void startI2C() {
  if (digitalRead(ADR_SEL) == LOW) {
    Wire.begin(address0);
  } else {
    Wire.begin(address1);
  }

  Wire.onReceive(receiveEvent);
  Wire.onRequest(requestEvent);
}


void loop() {

  // Collect data from the joystick button
  button.loop(); // MUST call the loop() function first
  if(button.isPressed())
    btnState = 1;

  if(button.isReleased())
    btnState = 0;
  
  // Store the mapped values from the switch in the registerMap struct
  registerMap.sw = btnState;
}
 
// Gets called when the ATtiny receives an i2c request
void requestEvent() {
  Wire.write(*(registerPointer + registerPosition));
}

// Gets called when the ATtiny revieves an i2c transmission
void receiveEvent(byte howMany) {
  if (howMany < 1) return;

  // Set the register offset position to what the master requests.
  registerPosition = Wire.read();
  howMany--;
  if (!howMany) return;
}