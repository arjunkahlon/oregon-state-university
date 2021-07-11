#ifndef VendSlot_HPP
#define VendSlot_HPP

#include "Snack.hpp"


class VendSlot
{
  private:
   Snack snack;
   int snackAmount;

  public:

    VendSlot();

    VendSlot(Snack, int);

    Snack  getSnack();

    int getAmount();

    void decrementAmount();
};

#endif
