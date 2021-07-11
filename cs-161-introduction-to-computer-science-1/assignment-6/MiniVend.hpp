#ifndef MiniVend_HPP
#define MiniVend_HPP

#include "Snack.hpp"
#include "VendSlot.hpp"

class MiniVend
{
  private:
     VendSlot v1, v2, v3, v4;
     double money;

  public:

      MiniVend(VendSlot, VendSlot, VendSlot, VendSlot, double);

      double getMoney();

      int numEmptySlots();

      double valueOfSnacks();

      void buySnack(int);
};

#endif
