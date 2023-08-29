#include <iostream>
#include "Unicorn.h"
#include "Gryphon.h"
#include "Dragon.h"
#include "Supplies.h"
#include "Market.h"
#include <fstream>
using namespace std;

//menu functions
//prints out menu ascii art
void printMenu() {
  cout << "\n" << "    ~~~~~~~~~~~~~~~~~~~~~~~~~\n"
       << "    |-------Main Menu-------|\n"
       << "    |~~~~~~~~~~~~~~~~~~~~~~~|\n"
       << "    | 1 - Check pet stats   |\n"
       << "    | 2 - Check supplies    |\n"
       << "    | 3 - Buy from Market   |\n"
       << "    | 4 - Sell at Market    |\n"
       << "    | 5 - Feed pet          |\n"
       << "    | 6 - Play with pet     |\n"
       << "    | 7 - Harvest pet goods |\n"
       << "    | 8 - Pass Time         |\n"   
       << "    | 9 - Load latest save  |\n"
       << "    | 10 - Save & quit      |\n"
       << "    | Please enter a number |\n"
       << "    ~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
}

//actual menu functionality using switch statements to respond to user input
void menuFunction(Pet &pet, Supplies& supplies, Market& market) {
  //print menu system
  printMenu();

  //adding functionality to switch statement
  bool quit = false;
  int option;
  cin >> option;
  
  while (!quit) {
    switch(option){
      case 1: { 
        pet.PrintInfo();
        break;
      } //see pet stats
      
      case 2: {
        supplies.printSupplies();
        break;
      } //see supplies
      
      case 3: {
        int buyChoice;
        market.printSoldHere();
        cout << "Enter the number for your choice:" << endl;
        cin >> buyChoice;
        market.buy(buyChoice, supplies);
        break;
      } //buy from market
      
      case 4: {
        int sellChoice;
        market.printBoughtHere();
        cout << "Enter the number for your choice:" << endl;
        cin >> sellChoice;
        market.sell(sellChoice, supplies);
        break;
      } //sell at market
      
      case 5: {
        int numFood;
        cout << "Enter the amount of " << pet.GetFood() << " you want to feed " << pet.GetName() << endl;
        cin >> numFood;
        pet.Feed(numFood, supplies);
        break;
      } //feed pet
      
      case 6: {
        int numHours;
        cout << "Enter how many hours you'd like to play with " << pet.GetName() << endl;
        cin >> numHours;
        pet.Play(numHours, supplies);
        
        break;
      } //play with pet
      
      case 7: {
        pet.HarvestGoods(supplies);
        break;
      } //harvest pet goods
      
      case 8: {
        int prevMood = pet.GetMood();
        int prevEnergy = pet.GetEnergy();
        pet.SetMood(prevMood - 2);
        pet.SetEnergy(prevEnergy - 2);
        cout << "\n\n⋆｡ ﾟ☁︎｡ ⋆｡ ﾟ☾ ﾟ｡ ⋆⋆｡°✩ ⋆⁺₊⋆ ☀︎ ⋆⁺₊⋆ ☾☼ ｡ ﾟ☁︎｡ ⋆｡ ﾟ☾ ﾟ｡ ⋆ ☁︎\n" << endl;
        cout << "\n1 day later..." << endl;
        pet.PrintInfo();
        break;
      } //pass time
      
      case 9: {
        //string fileName;
        pet.loadPet("save.txt", supplies);
        break;
      } //load latest save
      
      case 10: {
        pet.savePet(supplies);
        quit = true;
        exit(0);
        break;
      } //save and quit
      
      default: {
        cout << "Invalid option! Please enter an integer from 1 - 10." 
        << endl;
        break;
      }
    }
    printMenu();
    cin >> option;
  }
}

int main() {
  //output game title
  cout << "\n            ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" 
       << "\n            | MAGICAL CREATURES SANCTUARY |"
       << "\n            |       By: Alima Alam        |" 
       << "\n            ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" <<endl;

  //initialize supplies and markey for use throughout game
  Supplies supplies;
  Market market;
  
  string petName;
  cout << "\nName your pet!" << endl;
  cin >> petName;

  //make a pet to read "save.txt", if first time playing, file will be set to default unicorn
  Pet pet(petName);
  pet.loadPet("save.txt", supplies); 

  //menuFunction(pet, supplies, market);
  //unicorn
  if (pet.GetLevel() == 1) {
    Unicorn unicorn(petName);
    unicorn.loadPet("save.txt", supplies);
    unicorn.SetName(petName);
    cout << "Your current pet is a unicorn named " << unicorn.GetName() << ". Here are your pet's current stats." << endl;
    unicorn.PrintInfo();
    menuFunction(unicorn, supplies, market);
  } 
    
  //gryphon
  else if (pet.GetLevel() == 2) {
    Gryphon gryphon(petName);
    //if the previous save has data for a gryphon, read that data
    if (pet.GetType() == "Gryphon") {
      gryphon.loadPet("save.txt", supplies);
    } 
    
    cout << "Your current pet is a gryphon named " << gryphon.GetName() << ". Here are your pet's current stats." << endl;
    gryphon.PrintInfo();
    menuFunction(gryphon, supplies, market);
  } 

  //dragon
  else if (pet.GetLevel() == 3) {
    Dragon dragon(petName);
    //if the previous save has data for a dragon, read that data
    if (pet.GetType() == "Dragon") {
      dragon.loadPet("save.txt", supplies);
    } 
    
    cout << "Your current pet is a dragon named " << dragon.GetName() << ". Here are your pet's current stats." << endl;
    dragon.PrintInfo();
    menuFunction(dragon, supplies, market);
  } 

  //game over
  //this should not be necessary for expected gameplay, but I included it just in case
  else {
    pet.BeatGame(supplies);
    cout << "If you would like to begin a new game, simply restart the game without reloading your previous save. Happy gaming!" << endl;
  } 

  return 0;
}
