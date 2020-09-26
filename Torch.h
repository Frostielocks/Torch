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

    double virtual trc_getCurrentCurrentDraw();
    double virtual trc_getLowArmedCurrentDraw();
    double virtual trc_getLowDisarmedCurrentDraw();
    double virtual trc_getHighArmedCurrentDraw();
    double virtual trc_getHighDisarmedCurrentDraw();
    double virtual trc_getAverageArmedCurrentDraw();
    double virtual trc_getAverageDisarmedCurrentDraw();
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
    double trc_getCurrentCurrentDraw();
    double trc_getLowArmedCurrentDraw();
    double trc_getLowDisarmedCurrentDraw();
    double trc_getHighArmedCurrentDraw();
    double trc_getHighDisarmedCurrentDraw();
    double trc_getAverageArmedCurrentDraw();
    double trc_getAverageDisarmedCurrentDraw();
};

#endif
