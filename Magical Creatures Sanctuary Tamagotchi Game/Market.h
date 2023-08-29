#ifndef MARKETH
#define MARKETH
#include "Supplies.h"
#include <iostream>
#include <map>
using namespace std;

class Market {
public:
  Market(); //initializes food inventory and toys inventory
  void printSoldHere();
  void printBoughtHere();
  void printMarket(); //prints out market ascii

  void buy(int productKey, Supplies& supplies);
  void sell(int goodsKey, Supplies& supplies);

private:
  map<string, int> soldHere;
  map<string, int> boughtHere;
};

#endif