#include "Arduino.h"
#include "Torch.h"

DualRailTorch::DualRailTorch(Rail &rail1, Rail &rail2): rail1(rail1), rail2(rail2) {
  for (int i = 0; i < rail1.railSize; i++) {
    pinMode(rail1.digitalPins[i], OUTPUT); // Declare the LED as an output
  }
  for (int i = 0; i < rail2.railSize; i++) {
    pinMode(rail2.digitalPins[i], OUTPUT); // Declare the LED as an output
  }
};

void DualRailTorch:: trc_setArmDisarm(int value) {
  for (int i = 0; i < rail1.railSize; i++) {
    digitalWrite(this->rail1.digitalPins[i], value); // Turn the LED on
  }
  for (int i = 0; i < rail2.railSize; i++) {
    digitalWrite(this->rail2.digitalPins[i], value); // Turn the LED on
  }
}

int DualRailTorch::trc_isArmed() {
  return this->armed;
};


void DualRailTorch::trc_arm() {
  this->armed = 1;
  this->trc_setArmDisarm(HIGH);
};

void DualRailTorch::trc_disarm() {
  this->armed = 0;
  this->trc_setArmDisarm(LOW);
};

double DualRailTorch::trc_getCurrentPowerDraw() {
  return this->trc_isArmed() ? this->trc_getAverageArmedPowerDraw(): this->trc_getAverageDisarmedPowerDraw();
};


double DualRailTorch::trc_getLowArmedPowerDraw() {
  double rail1Current = this->rail1.railSize * ((5 - this->rail1.lowWattage) / this->rail1.resistor);
  double rail2Current = this->rail2.railSize * ((5 - this->rail2.lowWattage) / this->rail2.resistor);
  return rail1Current + rail2Current;
};

double DualRailTorch::trc_getLowDisarmedPowerDraw() {
  return 0;
};

double DualRailTorch::trc_getHighArmedPowerDraw() {
  double rail1Current = this->rail1.railSize * ((5 - this->rail1.highWattage) / this->rail1.resistor);
  double rail2Current = this->rail2.railSize * ((5 - this->rail2.highWattage) / this->rail2.resistor);
  return rail1Current + rail2Current;
};

double DualRailTorch::trc_getHighDisarmedPowerDraw() {
  return 0;
};

double DualRailTorch::trc_getAverageArmedPowerDraw() {
  return (this->trc_getLowArmedPowerDraw() + this->trc_getHighArmedPowerDraw()) / 2;
};

double DualRailTorch::trc_getAverageDisarmedPowerDraw() {
  return (this->trc_getLowDisarmedPowerDraw() + this->trc_getHighDisarmedPowerDraw()) / 2;
};
