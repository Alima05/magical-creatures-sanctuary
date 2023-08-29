#ifndef DRAGONH
#define DRAGONH
#include "Pet.h"
#include "Supplies.h"
#include <iostream>
#include <fstream>
using namespace std;

class Dragon : public Pet{
public:
  Dragon(); 
	Dragon(string n); //for specific pets, also set food and make hunger and mood 0

  void SetName(string n) override;  
  string GetName() override;
	
  void SetType(string t) override;
  string GetType() override;

  void SetFood(string f) override;
  string GetFood() override;

  void SetToy(string t) override;
  string GetToy() override;

  void SetGoods(string g) override;
  string GetGoods() override;

  int GetMood() override;
  int GetEnergy() override;
  void SetMood(int m) override;
  void SetEnergy(int e) override;

  int GetLevel() override;
  void SetLevel(int l) override;

  void BeatGame(Supplies& supplies) override;	
  void Play(int numHours, Supplies& supplies) override; //>mood + <energy
  void Feed(int numFood, Supplies& supplies) override; //>mood + >energy
  void HarvestGoods(Supplies& supplies) override; //<mood

  void printPet() override;
  void PrintInfo() override; //prints out name, type, food, toy, goods, mood, & hunger

  void savePet(Supplies& supplies) override;
  void loadPet(string fileName, Supplies& supplies) override;

private:
  string name, type, food, toy, goods;
  int level; //1 = unicorn, 2 = gryphon, 3 = dragon, 4 = finish game
  int currEnergy, currMood; 
  const int MAXENERGY = 60;
  const int MAXMOOD = 200;
};

#endif