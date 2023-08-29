#include "Market.h"

Market::Market() {
  soldHere.insert({"1 - Saddle", 15}); //saddle
  soldHere.insert({"2 - Yarn", 20}); //yarn
  soldHere.insert({"3 - Coin hoard", 25}); //hoard
  soldHere.insert({"4 - Daisies", 10}); //daisies - 10 pack
  soldHere.insert({"5 - Mice", 12}); //mice - 10 pack
  soldHere.insert({"6 - Fire carrots", 15}); //carrots - 10 pack

  boughtHere.insert({"1 - Unicorn Hair", 15}); //unicorn hair
  boughtHere.insert({"2 - Gryphon feather", 30}); //gryphon feather
  boughtHere.insert({"3 - Dragon Scale", 50}); //dragon scale
}

void Market::printMarket() {
  cout << "\n" << "         _|=|__________" << "\n"
       << "        / _ --     -__ \\" << "\n"
       << "       / -_ [MARKET] - -\\" << "\n"
       << "      /__________________\\" << "\n"
       << "       ||  || /__\\ ||  ||" << "\n"
       << "       ||[]|| | .| ||[]||" << "\n"
       << "     ()||__||_|__|_||__||()" << "\n"
       << "    ( )|-|-|-|====|-|-|-|( )" <<  "\n"
       << "    ^^^^^^^^^^====^^^^^^^^^^^" << endl;
}

void Market::printSoldHere() {
  printMarket();
  
  cout << "\nPlease note that all food is sold in packs of 5!" 
       << "\nWe sell:" << endl;
  for (auto itr = soldHere.begin(); itr != soldHere.end(); ++itr) {
    cout << itr->first << ": " << itr->second << " taka" << endl;
  }
}

void Market::printBoughtHere() {
  printMarket();
  cout << "\nWe buy:" << endl;
  for (auto itr = boughtHere.begin(); itr != boughtHere.end(); ++itr) {
    cout << itr->first << ": " << itr->second << " taka" << endl;
  }
}

void Market::buy(int productKey, Supplies& supplies){ //takes in an integer from 1 - 6 
  int taka = supplies.GetNumTaka();

  if (taka <= 0) {
    cout << "Oops! Looks like you're broke. Come back once you've earned more taka." << endl;
  }

  else {
    if (productKey == 1) {
      supplies.SetNumTaka(taka - 15);
      supplies.SetNumSaddles(supplies.GetNumSaddles() + 1);
    }
  
    else if (productKey == 2) {
      supplies.SetNumTaka(taka - 20);
      supplies.SetNumYarn(supplies.GetNumYarn() + 1);
    }
  
    else if (productKey == 3) {
      supplies.SetNumTaka(taka - 25);
      supplies.SetNumHoards(supplies.GetNumHoards() + 1);
    }  
  
    else if (productKey == 4) {
      supplies.SetNumTaka(taka - 10);
      supplies.SetNumDaisies(supplies.GetNumDaisies() + 5);
    }
  
    else if (productKey == 5) {
      supplies.SetNumTaka(taka - 12);
      supplies.SetNumMice(supplies.GetNumMice() + 5);
    }
  
    else if (productKey == 6) {
      supplies.SetNumTaka(taka - 15);
      supplies.SetNumCarrots(supplies.GetNumCarrots() + 5);
    }
  }

  supplies.printSupplies();
}

void Market::sell(int goodsKey, Supplies& supplies){
  int taka = supplies.GetNumTaka();
  if (goodsKey == 1) {
    if (supplies.GetNumHairs() == 0) {
      cout << "Oops! Looks like you don't have enough hairs. Come back after you've harvested more!." << endl;
      return;
    }
    
    supplies.SetNumTaka(taka + 15);
    supplies.SetNumHairs(supplies.GetNumHairs() - 1);
  }

  else if (goodsKey == 2) {
    if (supplies.GetNumFeathers() == 0) {
      cout << "Oops! Looks like you don't have enough feathers. Come back after you've harvested more!." << endl;
      return;
    }
    supplies.SetNumTaka(taka + 30);
    supplies.SetNumFeathers(supplies.GetNumFeathers() - 1);
  }

  else if (goodsKey == 3) {
    if (supplies.GetNumScales() == 0) {
      cout << "Oops! Looks like you don't have enough scales. Come back after you've harvested more!." << endl;
      return;
    }
    supplies.SetNumTaka(taka + 50);
    supplies.SetNumScales(supplies.GetNumScales() - 1);
  }

  supplies.printSupplies();
}