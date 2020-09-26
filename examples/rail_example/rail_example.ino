#include "Torch.h"
#include "CommandModule.h"

int rail1LedPins[6] = {2, 3, 4, 5, 6, 7};
int rail2LedPins[6] = {8, 9, 10, 11, 12, 13};
Rail rail1(6, rail1LedPins, 100, 2.8, 3.2);
Rail rail2(6, rail2LedPins, 100, 2.8, 3.2);
DualRailTorch dualRailTorch(rail1, rail2);

void setup() {
  Serial.begin(9600);
  Serial.print(dualRailTorch.trc_getCurrentCurrentDraw());
  Serial.print('\n');
  dualRailTorch.trc_arm();
  Serial.print(dualRailTorch.trc_getCurrentCurrentDraw());
  Serial.print('\n');
}

void loop() {

}
