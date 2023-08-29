#ifndef GRYPHONH
#define GRYPHONH
#include "Pet.h"
#include "Supplies.h"
#include <iostream>
using namespace std;

class Gryphon : public Pet{
public:
  Gryphon(); 
	Gryphon(string n); //for specific pets, also set food and make hunger and mood 0
 
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

  int GetLevel() override;
  void SetLevel(int l) override;
  void NextLevel() override;

  int GetMood() override;
  int GetEnergy() override;
  void SetMood(int m) override;
  void SetEnergy(int e) override;

	void Play(int numHours, Supplies& supplies) override; //>mood + <energy
  void Feed(int numFood, Supplies& supplies) override; //>mood + >energy
  void HarvestGoods(Supplies& supplies) override; //<mood 

  void printPet() override;  //prints pet ascii
  void PrintInfo() override; //prints out name, type, food, toy, goods, mood, & hunger

  void savePet(Supplies& supplies) override;
  void loadPet(string fileName, Supplies& supplies) override;

private:
  string name, type, food, toy, goods;
  int level; //1 = unicorn, 2 = gryphon, 3 = dragon, 4 = finish game
  int currEnergy, currMood; 
  const int MAXENERGY = 40;
  const int MAXMOOD = 100;
};

#endif