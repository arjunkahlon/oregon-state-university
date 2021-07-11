#include "Snack.hpp"
#include "VendSlot.hpp"
#include "MiniVend.hpp"

MiniVend::MiniVend(VendSlot x1, VendSlot x2, VendSlot x3, VendSlot x4, double m)
{
 v1 = x1;
 v2 = x2;
 v3 = x3;
 v4 = x4;
 money = m;
}

double MiniVend::getMoney()
{
   return money;
}

int MiniVend::numEmptySlots()
{
  int tally = 0;

  if(v1.getAmount() == 0)
   {
      tally++;
   }
   if(v2.getAmount() == 0)
   {
      tally++;
   }
   if(v3.getAmount() == 0)
   {
      tally++;
   }
   if(v4.getAmount() == 0)
   {
      tally++;
   }

   return tally;
}

double MiniVend::valueOfSnacks()
{
return (v1.getAmount()*v1.getSnack().getPrice()) + (v2.getAmount()*v2.getSnack().getPrice()) + (v3.getAmount()*v3.getSnack().getPrice()) + (v4.getAmount()*v4.getSnack().getPrice());
}

void MiniVend::buySnack(int q)
{
  if(q==0 && v1.getAmount() > 0)
     {
      v1.decrementAmount();
      money += v1.getSnack().getPrice();
     }
  if(q==1 && v2.getAmount() > 0)
     {
      v2.decrementAmount();
      money += v2.getSnack().getPrice();
     }
  if(q==2 && v3.getAmount() > 0)
     {
      v3.decrementAmount();
      money += v3.getSnack().getPrice();
     }
  if(q==3 && v4.getAmount() > 0)
     {
      v4.decrementAmount();
      money += v4.getSnack().getPrice();
     }
}

