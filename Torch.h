/*
  Torch.h - Library for LED Torches.
  Created by Mathijs Hubrechtsen, March 15, 2020.
*/
#ifndef Torch_h
#define Torch_h
#include "Arduino.h"

class Torch {
  public:
    virtual Torch(){};
    virtual int trc_isArmed();
    void virtual trc_arm();
    void virtual trc_disarm();
    
    double virtual trc_getCurrentPowerDraw();
    double virtual trc_getLowArmedPowerDraw();
    double virtual trc_getLowDisarmedPowerDraw();
    double virtual trc_getHighArmedPowerDraw();
    double virtual trc_getHighDisarmedPowerDraw();
    double virtual trc_getAverageArmedPowerDraw();
    double virtual trc_getAverageDisarmedPowerDraw();
};

class Rail {
  public:
    int railSize;
    int* digitalPins;
    int resistor;
    double lowWattage;
    double highWattage;
    Rail(int railSize, int digitalPins[], int resistor, double lowWattage, double highWattage)
    : railSize(railSize), digitalPins(digitalPins), resistor(resistor), lowWattage(lowWattage), highWattage(highWattage) {};
};

class DualRailTorch: public Torch {
  private:
    int armed;
    Rail &rail1;
    Rail &rail2;
    void trc_setArmDisarm(int value);
  public:
    DualRailTorch(Rail &rail1, Rail &rail2);
    int trc_isArmed();
    void trc_arm();
    void trc_disarm();
    double trc_getCurrentPowerDraw();
    double trc_getLowArmedPowerDraw();
    double trc_getLowDisarmedPowerDraw();
    double trc_getHighArmedPowerDraw();
    double trc_getHighDisarmedPowerDraw();
    double trc_getAverageArmedPowerDraw();
    double trc_getAverageDisarmedPowerDraw();
};

#endif
