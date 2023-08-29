#ifndef PETH
#define PETH
#include <iostream>
#include <fstream>
#include "Supplies.h"
using namespace std;

class Pet {
public:
  Pet(); 
	Pet(string n); //for specific pets, also set food and make hunger and mood randomized

  virtual void SetName(string n);
  virtual string GetName();

  virtual void SetType(string t);
  virtual string GetType();

  virtual void SetFood(string f);
  virtual string GetFood();

  virtual void SetToy(string t);
  virtual string GetToy();

  virtual void SetGoods(string g);
  virtual string GetGoods();

  virtual int GetLevel();
  virtual void SetLevel(int l);

  virtual int GetMood();
  virtual int GetEnergy();
  virtual void SetMood(int m);
  virtual void SetEnergy(int e);

  //pet interactions
  virtual void BeatGame(Supplies& supplies);
  virtual void NextLevel();
  virtual void Play(int numHours, Supplies& supplies);
  virtual void Feed(int numFood, Supplies& supplies); 
  virtual void HarvestGoods(Supplies& supplies);
  
  virtual void printPet();  
  virtual void PrintInfo();

  virtual void savePet(Supplies& supplies);
  virtual void loadPet(string fileName, Supplies& supplies);

protected:
  int level; //1 = unicorn, 2 = gryphon, 3 = dragon, 4 = finish game
  string name, type, food, toy, goods;
  int currEnergy, currMood; 
};

#endif