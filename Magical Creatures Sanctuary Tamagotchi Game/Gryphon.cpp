#include "Gryphon.h"

//constructors
Gryphon::Gryphon(){
  name = "unkown";
  type = "Gryphon";
  food = "Mice";
  toy = "Ball of Yarn";
  goods = "Gryphon feathers";
  currEnergy = 8;//numerical hunger level (unicorns = )
  currMood = 40;
  level = 2;
}

Gryphon::Gryphon(string n) {
  name = n; 
  type = "Gryphon";
  food = "Mice";
  toy = "Ball of Yarn";
  goods = "Gryphon feathers";
  currEnergy = 8;//numerical hunger level (unicorns = )
  currMood = 40;
  level = 2;
} 

//setters and getters
string Gryphon::GetName(){
  return name;
}
void Gryphon::SetName(string n){
  name = n;
}

void Gryphon::SetType(string t){
  type = t;
}
string Gryphon::GetType() {
  return type;
}

void Gryphon::SetFood(string f){
  food = f;
}
string Gryphon::GetFood(){
  return food;
}

void Gryphon::SetToy(string t){
  toy = t;
}
string Gryphon::GetToy(){
  return toy;
}

void Gryphon::SetGoods(string g){
  goods = g;
}
string Gryphon::GetGoods(){
  return goods;
}

int Gryphon::GetLevel() {
  return level;
}
void Gryphon::SetLevel(int l) {
  level = l;
}
void Gryphon::NextLevel() {
  cout << "\nCongratulations!! " <<  name  << " has reached its maximum mood and is ready to be released back into the wild.\nNow it’s time for a new challenge: taming a dragon!\nSimply save and quit, then load your previous save to move on to the next level :)" << endl; 
  level = 3;
  currMood = MAXMOOD;
  currEnergy = MAXENERGY;
}

int Gryphon::GetMood(){
  return currMood;
}
int Gryphon::GetEnergy(){
  return currEnergy;
}
void Gryphon::SetMood(int m){
  currMood = m;
}
void Gryphon::SetEnergy(int e){
  currEnergy = e;
}

//pet interactions
void Gryphon::Play(int numHours, Supplies& supplies) {
  //increase mood level  by 1 for each hour played
  //decrease energy by 1 for each hour played
  if (supplies.GetNumYarn() == 0) {
    cout << "Oops! Looks like you don't have any balls of yarn! Buy one at the market so that you can play with " << name << endl;
    return;
  }
  
  else {
    //ascii art
    cout << "\n" << "        .-')          _" << "\n" 
         << "  YAY! (`_^ (    .----'/" << "\n"
         << "          ` ) \\_/`   __/    __," <<"\n"
         << "        __{   |`  __/     /_/" << "\n"
         << "      / _{    \\__/ '--. //" << "\n"
         << "      \\_>\\\\  >__/     \\((" << "\n"
         << "            _/ /` _\\_  |))" << "\n"
         << "   __(@)~  /__(  /______/`" << endl;
    
    for (int i = 0; i < numHours; i++) {
      currMood+= 15;
      currEnergy-= 2;
      
      if (currMood >= MAXMOOD) { //stop loop if mood is full
        NextLevel();
        return;
      }
  
      else if (currEnergy <= 5) { //stop loop if energy depleted
        cout << "\n" << name << " is too hungry to play anymore :(\nFeed your gryphon to replenish its energy levels." << endl;
        return;
      }
    }
    
    cout << "\nYou just played with " << name << " for " << numHours << " hour(s)." 
         << "\nCurrent Mood Level: " << currMood << "/" << MAXMOOD
         << "\nCurrent Energy Level: " << currEnergy << "/" << MAXENERGY << endl;
  }
}

void Gryphon::Feed(int numFood, Supplies& supplies){
  //increase mood level by 8 for each mouse fed
  //increase energy by 8 for each mouse eaten
  if (supplies.GetNumMice() < numFood) {
    cout << "Oops! Looks like you don't have enough mice! Buy some more at the market." << endl;
    return;
  }

  else {
    //ascii art
    cout << "\n" << "        .-')          _" << "\n" 
         << "  YUM! (`_^ (    .----'/" << "\n"
         << "          ` ) \\_/`   __/    __," <<"\n"
         << "        __{   |`  __/     /_/" << "\n"
         << "      / _{    \\__/ '--. //" << "\n"
         << "      \\_>\\\\  >__/     \\((" << "\n"
         << "    __QQ      _/ /` _\\_  |))" << "\n"
         << "___(_)_\">    /__(  /______/`" << endl;
    
    for (int i = 0; i < numFood; i++) {
      int prevNumMice = supplies.GetNumMice();
      currEnergy+= 8;
      currMood+= 8;
      supplies.SetNumMice(prevNumMice - 1);
      if (currMood >= MAXMOOD) { 
        NextLevel();
        return;
      }
  
      else if (currEnergy >= MAXENERGY) { //stop loop if energy full
        currEnergy = MAXENERGY;
        cout << "\nCurrent Mood Level: " << currMood << "/" << MAXMOOD
         << "\nCurrent Energy Level: " << currEnergy << "/" << MAXENERGY << endl;
        cout << "\n" << name << " is full!" << endl;
        return;
      }
    }
  
    cout << "\nYou just fed " << name << " " << numFood << " "<< food << "."  
         << "\nCurrent Mood Level: " << currMood << "/" << MAXMOOD
         << "\nCurrent Energy Level: " << currEnergy << "/" << MAXENERGY << endl;
  }
}

void Gryphon::HarvestGoods(Supplies& supplies){
  //decrease currEnergy by 5
  //increase number of feathers in supplies by 1
  if (currMood <= 40) {
    cout << "Oops! Your gryphon is getting annoyed. You must raise " << name << "'s mood level above 40 in order to harvest more gryphon feathers." << endl;
    return;
  }
  
  else {
    //ascii art
    cout << "\n" << "         .-')          _   ______   ____" << "\n" 
         << "  OW!  (`_< (    .----'/  (_//_;/=={____" << "\n"
         << "          ` ) \\_/`   __/    __," <<"\n"
         << "        __{   |`  __/     /_/" << "\n"
         << "      / _{    \\__/ '--. //" << "\n"
         << "      \\_>\\\\  >__/     \\((" << "\n"
         << "              _/ /` _\\_  |))" << "\n"
         << "             /__(  /______/`" << endl;

      currMood-= 5;
    
      int newNumFeathers = supplies.GetNumFeathers() + 1;
      supplies.SetNumFeathers(newNumFeathers);
      cout << "\nYou just harvested 1 gryphon feather from " << name 
           << "\nYou now have " << newNumFeathers << " gryphon feather(s) in your supplies." 
           << "\nCurrent Mood Level: " << currMood << "/" << MAXMOOD
           << "\nCurrent Energy Level: " << currEnergy << "/" << MAXENERGY << endl;
  } 
}

//displays
void Gryphon::printPet(){
  cout << "\n" << "    .-')          _" << "\n" 
       << "   (`_^ (    .----'/" << "\n"
       << "    ` ) \\_/`   __/    __," <<"\n"
       << "    __{   |`  __/     /_/" << "\n"
       << "  / _{    \\__/ '--. //" << "\n"
       << "  \\_>\\\\  >__/     \\((" << "\n"
       << "        _/ /` _\\_  |))" << "\n"
       << "       /__(  /______/`" << endl;
}

void Gryphon::PrintInfo(){
  //add functionality
  printPet();
  cout << "\nPet Info of " << name << ", " << type << ":"
       << "\nMood Level: " << currMood << "/" << MAXMOOD
       << "\nEnergy Level: " << currEnergy << "/" << MAXENERGY
       << "\nFood: " << food
       << "\nToy: " << toy
       << "\nSellable goods: " << goods << endl;
}

void Gryphon::savePet(Supplies& supplies) {
  ofstream fout("save.txt");
  //check if file opened
  if (!fout.is_open()) {
    cerr << "Could not open save file! Try Again.";
    return;
  }
  
  //for supplies
  //food
  fout << supplies.GetNumDaisies() << endl;
  fout << supplies.GetNumMice() << endl;
  fout << supplies.GetNumCarrots() << endl;

  //toys
  fout << supplies.GetNumSaddles() << endl;
  fout << supplies.GetNumYarn() << endl;
  fout << supplies.GetNumHoards() << endl;

  //goods
  fout << supplies.GetNumHairs() << endl;
  fout << supplies.GetNumFeathers() << endl;
  fout << supplies.GetNumScales() << endl;
  
  //save in order of printInfo
  //for pet
  fout << level << endl;
  fout << name << endl;
  fout << currMood << endl;
  fout << currEnergy << endl;
  fout << food << endl;
  fout << toy << endl;
  fout << goods << endl;

  cout << name << "'s stats have been successfully saved!" << endl;

  fout.close();
}
void Gryphon::loadPet(string fileName, Supplies& supplies){
  ifstream fin (fileName);
  string words;
  int nums;
  //petPtr = new Pet;

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