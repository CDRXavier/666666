/*
  Buttons example
  June 11, 2015
  Copyright (C) 2015 David Martinez
  All rights reserved.
  This code is the most basic barebones code for showing how to use buttons in
  Arduboy.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.
*/

//#include <Arduboy2.h>

// Make an instance of arduboy used for many functions
//Arduboy2 arduboy;

// Variables for your game go here.
//char title[] = "Press Buttons!";
//byte x;
//byte y;

// Width of each charcter including inter-character space
//#define CHAR_WIDTH 6

// Height of each charater
//#define CHAR_HEIGHT 8

// To get the number of characters, we subtract 1 from the length of
// the array because there will be a NULL terminator at the end.
//#define NUM_CHARS (sizeof(title) - 1)

// This is the highest value that x can be without the end of the text
// going farther than the right side of the screen. We add one because
// there will be a 1 pixel space at the end of the last character.
// WIDTH and HEIGHT are defined in the Arduboy library.
//#define X_MAX (WIDTH - (NUM_CHARS * CHAR_WIDTH) + 1)

// This is the highest value that y can be without the text going below
// the bottom of the screen.
//#define Y_MAX (HEIGHT - CHAR_HEIGHT)

#define ENCODER_USE_INTERRUPTS
//#define ENCODER_DO_NOT_USE_INTERRUPTS
//we have interuupt on all pins on PortB and PD0123
#include "Encoder.h"

//D8 - PA06 - DGI2 - EXTINT6
//D9 - PA07 - DGI3 - EXTINT7
//D4 - PA08 - NMI
//D3 - PA09 - EXTINT9
//D1 - PA10 - EXTINT10
//D0 - PA11 - EXTINT11
//PA13 - DGI0 - EXTINT13
//D4 - PA14 - EXTINT14
//D5 - PA15 - EXTINT15
//D11 - PA16 - ALT_MOSI - EXTINT0
//D13 - PA17 - ALT_SCK-- LED_YELLOW - EXTINT1
//D10 - PA18 - ALT_SS - EXTINT2
//D12 - PA19 - ALT_MISO - EXTINT3
//D6 - PA20 - EXTINT4
//D7 - PA21 - DGI1 - EXTINT5
//AREF - PA03 - EXTINT3
//A0 - PA02 - EXTINT2 - VOUT
//A3 - PA04 - EXTINT4
//A4 - PA05 - EXTINT5
//A5 - PB02 - EXTINT2
//A1 - PB08 - EXTINT8
//A2 - PB09 - EXTINT9

Encoder EncX(1, 0);
Encoder EncY(2, 5);
Encoder EncZ(8, 9);
Encoder EncRX(11, 10);
Encoder EncRY(12, 13);
//Encoder EncRZ(6, 7);
//ThumbPointer for Rx and Ry

// This function runs once in your game.
// use it for anything that needs to be set only once in your game.
void setup() {
  //initiate arduboy instance
  //  arduboy.begin();
  delay(1000);
  SerialUSB.begin(9600);

  // here we set the framerate to 30, we do not need to run at default 60 and
  // it saves us battery life.
  //  arduboy.setFrameRate(30);
SerialUSB.print("hello");
  // set x and y to the middle of the screen
  //  x = (WIDTH / 2) - (NUM_CHARS * CHAR_WIDTH / 2);
  //  y = (HEIGHT / 2) - (CHAR_HEIGHT / 2);
      pinMode(0, INPUT_PULLUP);
    pinMode(1, INPUT_PULLUP);
        pinMode(2, INPUT_PULLUP);
    pinMode(5, INPUT_PULLUP);
        pinMode(8, INPUT_PULLUP);
    pinMode(9, INPUT_PULLUP);
        pinMode(10, INPUT_PULLUP);
    pinMode(11, INPUT_PULLUP);
        pinMode(12, INPUT_PULLUP);
    pinMode(13, INPUT);
}
short posX = 0;
short posY = 0;
short posZ = 0;
short posRX = 0;
short posRY = 0;
//short posRZ = 0;
short nPosY = 0;
short nPosX = 0;
short nPosZ = 0;
short nPosRX = 0;
short nPosRY = 0;
//short nPosRZ = 0;

// our main game loop, this runs once every cycle/frame.
// this is where our game logic goes.
void loop() {
  nPosX = EncX.read();
  nPosY = EncY.read();
  nPosX = EncZ.read();
  nPosRX = EncRX.read();
  nPosRY = EncRY.read();
  
  if ((posX != nPosX) || (posY != nPosY) || (posZ != nPosZ) || (posRX != nPosRX) || (posRY != nPosRY)) {
    if (posX != nPosX) {
      posX = nPosX;
      SerialUSB.print(' ');
      SerialUSB.print(nPosX);
    }
    else
      SerialUSB.print("  ");
    if (nPosY != posY) {
      posY = nPosY;
      SerialUSB.print(' ');
      SerialUSB.print(nPosY);
    }
    else
      SerialUSB.print("  ");
    if (posZ != nPosZ) {
      posZ = nPosZ;
      SerialUSB.print(' ');
      SerialUSB.print(nPosX);
    }
    else
      SerialUSB.print("  ");
    if (posRX != nPosRX) {
      posRX = nPosRX;
      SerialUSB.print(' ');
      SerialUSB.print(nPosX);
    }
    else
      SerialUSB.print("  ");
    if (nPosRY != posRY) {
      posRY = nPosRY;
      SerialUSB.print(' ');
      SerialUSB.print(nPosY);
    }
    else
      SerialUSB.print("  ");
      SerialUSB.println();
  }
}
