/***************************************************************
***** Author : Arjun Kahlon
***** Date: May 1, 2017 
***** Description: This program creates a class calld Box which
***** contains constructors to initialize the values, functions to
***** set height, width, and length, as well as 2 function to calculate
***** volume and surface area. This program was tested with the Main
***** provided on Canvas.  
*******************************************************************/

#include "Box.hpp"

    Box::Box()      //initializes values to 1.0
    {
     height = 1.0;
     width = 1.0;
     length = 1.0;
    }

    Box::Box(double h, double w, double l)  //function call to set values
     {
      height = h;
      width = w;
      length = l;
    }

     void Box::setHeight(double h)
     {
       height = h;
     }
     void Box::setWidth(double w)
     {
       width = w;
     }
     void Box::setLength(double l)
     {
       length = l;
     }
     double Box::calcVolume()       //returns Volume
     {
      return (height * width * length);
     }
     double Box::calcSurfaceArea()   //returns Surface Area
     {
      return (2 * (height * width) + 2 * (height * length) + 2 * (width * length)); 
     }    

