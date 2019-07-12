/*************************************************
CSCI-241 -Assignment 3- Fall 2017

Programmer: Andrew Slade
Z-ID: z1818810
Section: 4
TA: Dinesh Sandadi
Date Due: 2/28/2017

Purpose:Contains declaration for monkey class which 
manipulates data related to feeding a set of monkeys.
*************************************************/

#ifndef MONKEY_H
#define MONKEY_H

#include <string>
using std::string;

static const int NUMMONKEYS = 3;
static const int NUMDAYS = 7;

class Monkey
  {
    public:
    //public methods and data members

    Monkey();
    string getName(int);
    void printArray();
    float totalFoodEaten();
    float avgDailyConsumption();
    float avgDailyPerMonkey(int);
    void mostEaten();

    private:
    //private methods and data members

    string monkeyNames[3] = {"Curious George", "Mojo", "Marcel"};    
    float lbsFood[NUMMONKEYS][NUMDAYS];
    
  };

#endif
