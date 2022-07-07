#define ENCODER_USE_INTERRUPTS
//#define ENCODER_DO_NOT_USE_INTERRUPTS
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
//Encoder EncZ(8, 9);
//Encoder EncRX(11, 10);
//Encoder EncRY(12, 13);
//Encoder EncRZ(6, 7);

void setup() {

  delay(1000);
  SerialUSB.begin(9600);

  SerialUSB.print("hello");

  pinMode(0, INPUT_PULLUP);
  pinMode(1, INPUT_PULLUP);
  pinMode(2, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  //        pinMode(8, INPUT_PULLUP);
  //    pinMode(9, INPUT_PULLUP);
  //        pinMode(10, INPUT_PULLUP);
  //    pinMode(11, INPUT_PULLUP);
  //        pinMode(12, INPUT_PULLUP);
  //    pinMode(13, INPUT);
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


void loop() {
  nPosX = EncX.read();
  nPosY = EncY.read();
  //  nPosX = EncZ.read();
  //  nPosRX = EncRX.read();
  //  nPosRY = EncRY.read();

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
