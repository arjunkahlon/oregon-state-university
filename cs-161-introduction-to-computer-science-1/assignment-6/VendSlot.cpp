#include "Snack.hpp"
#include "VendSlot.hpp"

VendSlot::VendSlot()
{
  snack = Snack();
  snackAmount = 5;
}

VendSlot::VendSlot(Snack s, int a)
{
  snack = s;
  snackAmount = a;
}

Snack VendSlot::getSnack()
{
   return snack;
}

int VendSlot::getAmount()
{
   return snackAmount;
}

void VendSlot::decrementAmount()
{
   snackAmount--;
}

