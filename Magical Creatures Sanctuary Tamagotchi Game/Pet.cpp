#include "Pet.h"

//placeholders for constructors
Pet::Pet(){
  name = "unkown";
}

Pet::Pet(string n) {
   name = n; 
} //for specific pets, also set food and make hunger and mood 

//placeholders for getters and setters
string Pet::GetName(){
  return name;
}
void Pet::SetName(string n){
  name = n;
}

int Pet::GetLevel(){
  return level;
}
void Pet::SetLevel(int l){
  level = l;
}

void Pet::SetType(string t){
  type = t;
}
string Pet::GetType() {
  return type;
}

void Pet::SetFood(string f){
  food = f;
}
string Pet::GetFood(){
  return food;
}

void Pet::SetToy(string t){
  toy = t;
}
string Pet::GetToy(){
  return toy;
}

void Pet::SetGoods(string g){
  goods = g;
}
string Pet::GetGoods(){
  return goods;
}

int Pet::GetMood(){
  return currMood;
}
int Pet::GetEnergy(){
  return currEnergy;
}
void Pet::SetMood(int m){
  currMood = m;
}
void Pet::SetEnergy(int e){
  currEnergy = e;
}

//placeholders for functions (unicorn + gryphon
void Pet::NextLevel(){
  cout << "This should not show (pet.NextLevel())" << endl;
}

void Pet::BeatGame(Supplies& supplies){
  cout << "This should not show (pet.BeatGame())" << endl;
}

void Pet::Play(int numHours, Supplies& supplies) {
  cout << "This should not show (pet.Play())" << endl;
}

void Pet::Feed(int numFood, Supplies& supplies){
  cout << "This should not show (pet.Feed())" << endl;
}

void Pet::HarvestGoods(Supplies& supplies) {
  cout << "This should not show (pet.HarvestGoods())" << endl;
}

void Pet::printPet(){
  cout << "This should not show (pet.printPet())" << endl;
}

void Pet::PrintInfo(){
  //add functionality
  printPet();
  cout << "\nPet Info of " << name << endl;
}

void Pet::savePet(Supplies& supplies){
   cout << "This should not show (pet.savePet())" << endl;
}
void Pet::loadPet(string fileName, Supplies& supplies){
  ifstream fin (fileName);
  string words;
  int nums;

  if (!fin.is_open()) {
    cerr << "Could not open input file!";
    exit(-1);
  } 

  //for supplies
  //food
  fin >> nums;
  supplies.SetNumDaisies(nums);
  fin >> nums;
  supplies.SetNumMice(nums);
  fin >> nums;
  supplies.SetNumCarrots(nums);

  //toys
  fin >> nums;
  supplies.SetNumSaddles(nums);
  fin >> nums;
  supplies.SetNumYarn(nums);
  fin >> nums;
  supplies.SetNumHoards(nums);

  //goods
  fin >> nums;
  supplies.SetNumHairs(nums);
  fin >> nums;
  supplies.SetNumFeathers(nums);
  fin >> nums;
  supplies.SetNumScales(nums);
  
  //for pet
  fin >> level;

  fin.ignore();
  
  getline(fin, name);

  fin >> currMood;
  fin >> currEnergy;

  fin.ignore();

  getline(fin, food); 
  getline(fin, toy);
  getline(fin, goods);

  fin.close();
}
