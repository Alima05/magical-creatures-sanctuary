#include "Unicorn.h"

//constructors
Unicorn::Unicorn(){
  name = "unkown";
  type = "Unicorn";
  food = "Daisies";
  toy = "Saddle";
  goods = "Unicorn hairs";
  currEnergy = 6;//numerical hunger level (unicorns = )
  currMood = 5;
  level = 1;
}

Unicorn::Unicorn(string n) {
  name = n; 
  type = "Unicorn";
  food = "Daisies";
  toy = "Saddle";
  goods = "Unicorn hairs";
  currEnergy = 6;//numerical hunger level (unicorns = )
  currMood = 5;
  level = 1;
} 

//setters and getters
string Unicorn::GetName(){
  return name;
}
void Unicorn::SetName(string n){
  name = n;
}

void Unicorn::SetType(string t){
  type = t;
}
string Unicorn::GetType() {
  return type;
}

void Unicorn::SetFood(string f){
  food = f;
}
string Unicorn::GetFood(){
  return food;
}

void Unicorn::SetToy(string t){
  toy = t;
}
string Unicorn::GetToy(){
  return toy;
}

void Unicorn::SetGoods(string g){
  goods = g;
}
string Unicorn::GetGoods(){
  return goods;
}

//new level?
int Unicorn::GetLevel() {
  return level;
}
void Unicorn::SetLevel(int l) {
  level = l;
}

int Unicorn::GetMood(){
  return currMood;
}
int Unicorn::GetEnergy(){
  return currEnergy;
}
void Unicorn::SetMood(int m){
  currMood = m;
}
void Unicorn::SetEnergy(int e){
  currEnergy = e;
}

//pet interactions
void Unicorn::NextLevel() {
  cout << "\nCongratulations!! " <<  name  << " has reached its maximum mood and is ready to be released back into the wild.\nNow it’s time for a new challenge: taming a gryphon!\n\nSimply save and quit, then load your previous save to move on to the next level :)" << endl; 
  level = 2;
  currMood = MAXMOOD;
  currEnergy = MAXENERGY;
}

void Unicorn::Play(int numHours, Supplies& supplies) {
  //increase mood level  by 1 for each hour played
  //decrease energy by 1 for each hour played
  //ascii art
  if (supplies.GetNumSaddles() == 0) {
    cout << "Oops! Looks like you don't have any saddles! Buy one at the market so that you can play with " << name << endl;
    return;
  }

  else {
    cout << "\n                 {)          " << "\n"
         << "      \\       c==//\\         " << "\n"
         << "       \\\\_-~~/-._|_|         " << "\n"
         << "        /'_,/,   //'~~~~>;;,  " << "\n"
         << "  YAY!  `~  _( _||_..\\ | ';; " << "\n"
         << "          /'~|/ ~' `\\<\\>  ;  " << "\n"
         << "          \"  |      /  |     " << "\n"
         << "             \"      \"  \"    " << endl;
    
    for (int i = 0; i < numHours; i++) {
      currMood+= 10;
      currEnergy-= 5;
      
      if (currMood >= MAXMOOD) { //stop loop if mood is full
        NextLevel();
        return;
      }
  
      else if (currEnergy <= 5) { //stop loop if energy depleted
        cout << "\n" << name << " is too hungry to play anymore :(\nFeed your unicorn to replenish its energy levels." << endl;
        return;
      }
    }
    
    cout << "\nYou just played with " << name << " for " << numHours << " hour(s)." 
         << "\nCurrent Mood Level: " << currMood << "/" << MAXMOOD
         << "\nCurrent Energy Level: " << currEnergy << "/" << MAXENERGY << endl;
  }
}

void Unicorn::Feed(int numFood, Supplies& supplies){
  //increase mood level by 1 for each daisy fed
  //increase energy by 1 for each daisy eaten

  if (supplies.GetNumDaisies() < numFood) {
    cout << "Oops! Looks like you don't have enough daisies in your supplies. Buy some more from the the market." << endl;
    return;
  }

  else {
    //ascii art
    cout << "\n" << "              \\ " << "\n"
         << "               \\" << "\n"
         << "                \\\\ "<< "\n"
         << "                 \\\\ "<< "\n"
         << "                  >\\/7" << "\n"
         << "              _.-(6' \\ "<< "\n"
         << "  YUM!   🏵~`~(=___._/`\\ "<< "\n"
         << "                  )  \\|" << "\n"
         << "                 /   / |" << "\n"
         << "                /    > /" << "\n"
         << "               j    < _\\ "<< endl;
    
    for (int i = 0; i < numFood; i++) {
      int prevNumDaisies = supplies.GetNumDaisies();
      currEnergy+= 6;
      currMood+= 5;
      supplies.SetNumDaisies(prevNumDaisies - 1);
      
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

void Unicorn::HarvestGoods(Supplies& supplies){
  //decrease currEnergy by 2
  //increase number of unicorn hairs in supplies by 1
  if (currMood <= 20) {
    cout << "Oops! Your unicorn is getting annoyed. You must raise " << name << "'s mood level above 20 in order to harvest more unicorn hairs." << endl;
    return;
  }
  
  else {
    //ascii art
  cout << "\n" << "              \\ " << "\n"
       << "               \\" << "\n"
       << "                \\\\ "<< "\n"
       << "                 \\\\ "<< "\n"
       << "                  >\\/7"<< "\n"
       << "              _.-(6' \\         " << "\n"
       << "      OW!!   (o___._/`\\      ___"<< "\n"
       << "                  )  \\| ~-~-{___" << "\n"
       << "                 /   / |" << "\n"
       << "                /    > /" << "\n"
       << "               j    < _\\ "<< endl;

    currMood-= 2;
    
    int newNumHairs = supplies.GetNumHairs() + 1;
    supplies.SetNumHairs(newNumHairs);
    cout << "\nYou just harvested 1 unicorn hair from " << name 
         << "\nYou now have " << newNumHairs << " unicorn hair(s) in your supplies." 
         << "\nCurrent Mood Level: " << currMood << "/" << MAXMOOD
         << "\nCurrent Energy Level: " << currEnergy << "/" << MAXENERGY << endl;
  } 
}

//displays
void Unicorn::printPet(){
  cout << "\n" << "              \\ " << "\n"
       << "               \\" << "\n"
       << "                \\\\ "<< "\n"
       << "                 \\\\ "<< "\n"
       << "                  >\\/7" << "\n"
       << "              _.-(6' \\ "<< "\n"
       << "             (=___._/`\\ "<< "\n"
       << "                  )  \\|" << "\n"
       << "                 /   / |" << "\n"
       << "                /    > /" << "\n"
       << "               j    < _\\ "<< endl;
}

void Unicorn::PrintInfo(){
  //add functionality
  printPet();
  cout << "\nPet Info of " << name << ", " << type << ":"
       << "\nMood Level: " << currMood << "/" << MAXMOOD
       << "\nEnergy Level: " << currEnergy << "/" << MAXENERGY
       << "\nFood: " << food
       << "\nToy: " << toy
       << "\nSellable goods: " << goods << endl;
}

void Unicorn::savePet(Supplies& supplies) {
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

  cout << "Your progress has been successfully saved!" << endl;

  fout.close();
}
void Unicorn::loadPet(string fileName, Supplies& supplies){
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