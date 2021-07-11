/**********************************************************************************
Ant.cpp : This is the definition file for my Ant class. It contains the constructor
definitions for my Ant class as well as the function declarations for setDirection(),
getDirection(), move(), and getBoard().
*********************************************************************************/

#include "Ant.hpp"

Ant::Ant()
{
   Ant(1, 1, 0, 0);    //passed in paramters create Board object within Ant Class
}

Ant::Ant(int a, int b, int c, int d)
{
   board = new Board(a, b, c, d);     //dynamically allocates new Board object
   setDirection(up);       //initializes direction to up
}

void Ant::setDirection(Direction d)
{
   drct = d;          //sets enumerated type to passed in paramter
}

Ant::Direction Ant::getDirection()       //return direction of ant
{
   return drct;
}

void Ant::move(int tr, int tc)        //follows rules for Langton's Ant
{
   if (board->getCurrentColor() == ' ')
   {
      board->setCurrentColor('#');
      x_temp = board->getXCoord();
      y_temp = board->getYCoord();

      if (getDirection() == up)
      {
         setDirection(right);

         if (y_temp == (tc-1))
         {
            board->setXY(x_temp, 0);
         }
         else
         {
            board->setXY(x_temp, y_temp + 1);
         }
      }
      else if (getDirection() == right)
      {
         setDirection(down);

         if (x_temp == (tr-1))
         {
            board->setXY(0, y_temp);
         }
         else
         {
            board->setXY(x_temp + 1, y_temp);
         }
      }
      else if (getDirection() == down)
      {
         setDirection(left);

         if (y_temp == 0)
         {
            board->setXY(x_temp, (tc-1));
         }
         else
         {
            board->setXY(x_temp, y_temp - 1);
         }
      }
      else if (getDirection() == left)
      {
         setDirection(up);

         if (x_temp == 0)
         {
            board->setXY((tr-1), y_temp);
         }
         else
         {
            board->setXY(x_temp - 1, y_temp);
         }
      }
   }

   else if (board->getCurrentColor() == '#')
   {
      board->setCurrentColor(' ');
      x_temp = board->getXCoord();
      y_temp = board->getYCoord();

      if (getDirection() == up)
      {
         setDirection(left);

         if (y_temp == 0)
         {
            board->setXY(x_temp, (tc-1));
         }
         else
         {
            board->setXY(x_temp, y_temp - 1);
         }
      }
      else if (getDirection() == right)
      {
         setDirection(up);

         if (x_temp == 0)
         {
            board->setXY((tr-1), y_temp);
         }
         else
         {
            board->setXY(x_temp - 1, y_temp);
         }
      }
      else if (getDirection() == down)
      {
         setDirection(right);

         if (y_temp == tc-1)
         {
            board->setXY(x_temp, 0);
         }
         else
         {
            board->setXY(x_temp, y_temp + 1);
         }
      }
      else if (getDirection() == left)
      {
         setDirection(down);

         if (x_temp == (tr-1))
         {
            board->setXY(0, y_temp);
         }
         else
         {
            board->setXY(x_temp + 1, y_temp);
         }
      }
   }
}

Board* Ant::getBoard()     //returns board
{
   return board;
}

