/*************************************************
CSCI-241 -Assignment 3- Fall 2017

Programmer: Andrew Slade
Z-ID: z1818810
Section: 4
TA: Dinesh Sandadi
Date Due: 2/28/2017

Purpose:Contains code for monkey class. Manipulates data
from and reads in data to monkey class.
*************************************************/

//Preprocessors
#include "Monkey.h"
#include <string>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <cstring>
#include <cassert>

using std::cout;
using std::endl;
using std::setw;
using std::fstream;
using std::ios;
using std::string;
using std::fixed;
using std::setprecision;
using std::right;
using std::left;
//--------------

/************************************************
Monkeys(default constructor)

Use: Constructs class Monkeys with values from 
     a read in file.

Parameters: none(default constructor)

Returns: nothing(default constructor)
************************************************/
Monkey::Monkey()
  {
   string fileName ="monkeyfood.txt";
    
   fstream myFiler(fileName.c_str(), ios::in);
    if(myFiler.is_open())
     {
       for(int c = 0; c < NUMMONKEYS; c++)
         {
           /*
            double for loop to fill array
            static const int NUMMONKEYS = 3;
            static const int NUMDAYS = 7;

            as a note to self: first entry is
            at 0,0 not 1,1
           */
           for(int q = 0; q < NUMDAYS ; q++)
             {
               myFiler >> lbsFood[c][q];
             }
         }
     }
    else
     {
       //breaks here if file does not open
       cout << fileName << " does not exist" << endl;
       assert(myFiler);
     }
  }

/************************************************
getName

Use: Accessor for the monkeyNames array.

Parameters: an integer.

Returns: a c++ string. 
**************************************************/
string Monkey::getName(int indexed)
  {
    string theChosenOne = ""; //a temp holder

    //gets name
    theChosenOne = monkeyNames[indexed];
    
   return theChosenOne;
  }

/************************************************
printArray

Use: Prints lbsFood array and the names of the monkeys
     that the values belong to.

Parameters: none

Returns: nothing(void)
************************************************/
void Monkey::printArray()
  {
   
    cout << fixed << setprecision(2);
    cout << endl;
    for(int b = 0; b < NUMMONKEYS; b++)
      {
       //for loop prints values for each monkey 
  
        cout << setw(15) << left << monkeyNames[b];

        for(int t = 0; t < NUMDAYS ; t++)
          {
            //this prints out the actual food amounts
            cout << setw(5) << right << lbsFood[b][t] << " ";
            if(t == NUMDAYS - 1)
             {
               //inserts end of line at final index for monkey
               cout << endl;
             } 
          }
      }
   return;
  }

/************************************************
totalFoodEaten

Use: Calculates the total food consumed for the week
     for each monkey.

Parameters: none

Returns: a float
************************************************/
float Monkey::totalFoodEaten()
  {
    float eat = 0.00; //temp holder
    
    for(int x = 0; x < NUMMONKEYS; x++)
      {
        for(int z = 0; z < NUMDAYS ; z++)
          {
            //calculates the total food consumed
            eat += lbsFood[x][z];
          }
      }
      
   return eat;
  }

/************************************************
avgDailyConsumption

Use: returns average consumption for each
     day this week. 

Parameters: none

Returns: a float
************************************************/
float Monkey::avgDailyConsumption()
  {
    float avgWeekFood = 0.00;//temp variable
    
    //calculates the average amount of food consumed per monkey
    avgWeekFood = totalFoodEaten() / (NUMMONKEYS * NUMDAYS);
      
   return avgWeekFood;
  }

/************************************************
avgDailyPerMonkey

Use: Calculates the average food consumption per 
     monkey for the week. 

Parameters: an integer

Returns: a float
************************************************/
float Monkey::avgDailyPerMonkey(int monkeyHolder)
  { 
    float avgPerMonkey = 0.0; //temp holder
    
    for(int r = 0; r < NUMDAYS; r++)
      {
        avgPerMonkey += lbsFood[monkeyHolder][r];
      }
    avgPerMonkey /= NUMDAYS;
   return avgPerMonkey;
  }

/************************************************
mostEaten

Use: Searches the array for the most food eaten
     and the monkey that ate that amount.

Parameters: none

Returns: none(void)
************************************************/
void Monkey::mostEaten()
  {
    /*
      we used a code like this in my 240 at kish
      not as efficient, but effective
      seems to run best in O = n time,
      however, I could be incorrect.
    */

    bool flag = false; //holds bool for verification of search
    float highestNum = 0.0; //holds highest current value
    int monkeyNamer = 0; //holds index of monkey found in search
    
       //loop to search
    do{   
       /*
         as a note, this seems incredibly counter intuitive.
         however, the for loops take precedence during the 
         do while. So, the for loop iterates entirely, and then,
         at the end, it returns the final value gotten which is 
         evaluated by the do while.
       */
       for(int jj = 0; jj < NUMMONKEYS; jj++ )
         {
           //basic search double for loop to iterate through 2d array
           for(int zz = 0; zz < NUMDAYS; zz++)
             {
               if(lbsFood[jj][zz] > highestNum)
                 {
                   /*
                     if current value is > highest number 
                     assign current value to highest number
                     continue
                   */
    
                   highestNum = lbsFood[jj][zz];
                   flag = false; //continues loop
                   monkeyNamer = jj;
                  }
               else if(lbsFood[jj][zz] < highestNum )
                 {
                   //if current value < highest number, do nothing
                   flag = true; //sends up flag
                 }
               else
                 { 
                   //catch all
                   flag = false;
                 }    
             }
           }
     }while(!flag);

    cout << endl << monkeyNames[monkeyNamer] << " ate the most - " 
         << highestNum << " pounds" << endl;
    
   return;
  }
