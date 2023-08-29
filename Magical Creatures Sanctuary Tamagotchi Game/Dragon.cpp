#include "Dragon.h"

//constructors
Dragon::Dragon(){
  name = "unkown";
  type = "Dragon";
  food = "Fire Carrots";
  toy = "Coin Hoard";
  goods = "Dragon scales";
  currEnergy = 20;//numerical hunger level (unicorns = )
  currMood = 60;
  level = 3;
}

Dragon::Dragon(string n) {
  name = n; 
  type = "Dragon";
  food = "Fire Carrots";
  toy = "Coin Hoard";
  goods = "Dragon scales";
  currEnergy = 20;//numerical hunger level (unicorns = )
  currMood = 60;
  level = 3;
} 

//setters and getters
string Dragon::GetName(){
  return name;
}
void Dragon::SetName(string n){
  name = n;
}

void Dragon::SetType(string t){
  type = t;
}
string Dragon::GetType() {
  return type;
}

void Dragon::SetFood(string f){
  food = f;
}
string Dragon::GetFood(){
  return food;
}

void Dragon::SetToy(string t){
  toy = t;
}
string Dragon::GetToy(){
  return toy;
}

void Dragon::SetGoods(string g){
  goods = g;
}
string Dragon::GetGoods(){
  return goods;
}

int Dragon::GetLevel() {
  return level;
}
void Dragon::SetLevel(int l) {
  level = l;
}

int Dragon::GetMood(){
  return currMood;
}
int Dragon::GetEnergy(){
  return currEnergy;
}
void Dragon::SetMood(int m){
  currMood = m;
}
void Dragon::SetEnergy(int e){
  currEnergy = e;
}

//pet interactions
void Dragon::BeatGame(Supplies& supplies) {
  level = 4;
  savePet(supplies);
  cout << "\nYou have completed your training and earned your Care of Magical Creatures certificate!" << endl;
  supplies.printCertificate(); //prints out certificate ascii
  cout << "\n        Farewell, Caretaker of Magical Creatures."
       << "\n                    !GAME OVER!" << endl;

  //overwrite "save.txt" in order to reset after beating game
  ofstream fout("save.txt");
  fout << 5 << endl;
  fout << 0 << endl;
  fout << 0 << endl;
  fout << 0 << endl;
  fout << 0 << endl;
  fout << 0 << endl;
  fout << 0 << endl;
  fout << 0 << endl;
  fout << 0 << endl;
  fout << 1 << endl;
  fout << "Unkown" << endl;
  fout << 5 <<  endl;
  fout << 6 << endl;
  fout << "Daisies" << endl;
  fout << "Saddle" << endl;
  fout << "Unicorn hairs" << endl;
  fout.close();
  exit(0);
}

void Dragon::Play(int numHours, Supplies& supplies) {
  //increase mood level  by 1 for each hour played
  //decrease energy by 1 for each hour played
  if (supplies.GetNumHoards() == 0) {
    cout << "\nOops! Looks like you don't have any coin hoards! Buy one at the market so that you can play with " << name << endl;
    return;
  }

  else {
    int prevNumCarrots = supplies.GetNumCarrots();
    //ascii art
    cout << "\n" << "   <>=======() " << "\n"
         << "  (/\\___   /|\\\\        ()==========<>_" <<"\n"
         << "       \\_/ |  \\\\       //|\\   ______/\\)" << "\n"
         << "         \\_|   \\\\     // |\\_/" << "\n"
         << "          \\|\\/|\\_    //  /\\/" << "\n"
         << "             (oo)\\ \\_//  /" << "\n"
         << "            //_/\\_\\/ /  |" << "\n"
         << "           @@/  |=\\  \\  |" << "\n"
         << "     YAY!       \\_=\\_ \\ |" << "\n"
         << "                 \\==\\ \\|\\_ " << "\n"
         << "               __(\\===\\(  )\\" << "\n"
         << "     * 0       __(\\===\\(  )\\" << "\n"
         << "   *  000 *         (((~)\\  /" << "\n"
         << "     00000 *       ______/ /" << "\n"
         << "    0000000       '------'" << "\n" << endl;
    
    for (int i = 0; i < numHours; i++) {
      currMood+= 20;
      currEnergy-= 15;
      supplies.SetNumCarrots(prevNumCarrots - 1);
      if (currMood >= MAXMOOD) { //FIXME
        cout << "\nCongratulations!! " <<  name  << " has reached its maximum mood and is ready to be released back into the wild." << endl; 
        currMood = MAXMOOD;
        BeatGame(supplies);
        return;
      }
  
      else if (currEnergy <= 5) { //stop loop if energy depleted
        cout << "\n" << name << " is too hungry to play anymore :(\nFeed your Dragon to replenish its energy levels." << endl;
        return;
      }
    }
    
    cout << "\nYou just played with " << name << " for " << numHours << " hour(s)." 
         << "\nCurrent Mood Level: " << currMood << "/" << MAXMOOD
         << "\nCurrent Energy Level: " << currEnergy << "/" << MAXENERGY << endl;
  }
}

void Dragon::Feed(int numFood, Supplies& supplies){
  //increase mood level by 8 for each mouse fed
  //increase energy by 8 for each mouse eaten
  //ascii art
  if (supplies.GetNumCarrots() < numFood) {
    cout << "Oops! Looks like you don't have enough carrots! Buy some more at the market." << endl;
    return;
  }
  
  else {
    cout << "\n" << "   <>=======() " << "\n"
         << "  (/\\___   /|\\\\        ()==========<>_" <<"\n"
         << "       \\_/ |  \\\\       //|\\   ______/\\)" << "\n"
         << "         \\_|   \\\\     // |\\_/" << "\n"
         << "          \\|\\/|\\_    //  /\\/" << "\n"
         << "             (^^)\\ \\_//  /" << "\n"
         << "            //_/\\_\\/ /  |" << "\n"
         << "   YUM!    @@/  |=\\  \\  |" << "\n"
         << "          /\\    \\_=\\_ \\ |" << "\n"
         << "         /')     \\==\\ \\|\\_ " << "\n"
         << "         /M    __(\\===\\(  )\\" << "\n"
         << "               __(\\===\\(  )\\" << "\n"
         << "       W           (((~)\\  /" << "\n"
         << "      (`)         ______/ /" << "\n"
         << "      ('/        '------'" << "\n"
         << "      \\/" << endl;
    
    for (int i = 0; i < numFood; i++) {
      int prevNumCarrots = supplies.GetNumCarrots();
      currEnergy+= 10;
      currMood+= 10;
      supplies.SetNumCarrots(prevNumCarrots - 1);
      
      if (currMood >= MAXMOOD) { //FIXME
        cout << "\nCongratulations!! " <<  name  << " has reached its maximum mood and is ready to be released back into the wild." << endl; 
        currMood = MAXMOOD;
        currEnergy = MAXENERGY;
        BeatGame(supplies);
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
  
    cout << "\nYou just fed " << name << " " << numFood << " "<< food << "(s) ."  
         << "\nCurrent Mood Level: " << currMood << "/" << MAXMOOD
         << "\nCurrent Energy Level: " << currEnergy << "/" << MAXENERGY << endl;
  }
}

void Dragon::HarvestGoods(Supplies& supplies){
  //decrease currEnergy by 5
  //increase number of feathers in supplies by 1
  if (currMood <= 90) {
    cout << "Oops! Your dragon is getting annoyed. You must raise " << name << "'s mood level above 90 in order to harvest more dragon scales." << endl;
    return;
  }
  
  else {
    //ascii art
    cout << "\n" << "   <>=======() " << "\n"
         << "  (/\\___   /|\\\\        ()==========<>_" <<"\n"
         << "       \\_/ |  \\\\       //|\\   ______/\\)" << "\n"
         << "          \\_|   \\\\     // |\\_/" << "\n"
         << "           \\|\\/|\\_    //  /\\/" << "\n"
         << "             (><)\\ \\_//  /      _____" << "\n"
         << "            //_/\\_\\/ /  |    C>{_____    " << "\n"
         << "           @@/  |=\\  \\  |" << "\n"
         << "    OW!         \\_=\\_ \\ |" << "\n"
         << "                 \\==\\ \\|\\_ " << "\n"
         << "               __(\\===\\(  )\\" << "\n"
         << "               __(\\===\\(  )\\" << "\n"
         << "                   (((~)\\  /" << "\n"
         << "                   ______/ /" << "\n"
         << "                   '------'"  << endl;

    currMood-= 5;
    
    int newNumScales = supplies.GetNumScales() + 1;
    supplies.SetNumScales(newNumScales);
    cout << "\nYou just harvested 1 dragon scale from " << name 
         << "\nYou now have " << supplies.GetNumScales() << " dragon scale(s) in your supplies." 
         << "\nCurrent Mood Level: " << currMood << "/" << MAXMOOD
         << "\nCurrent Energy Level: " << currEnergy << "/" << MAXENERGY << endl;
  } 
}

//displays
void Dragon::printPet(){
  cout << "\n" << "   <>=======() " << "\n"
       << "  (/\\___   /|\\\\        ()==========<>_" <<"\n"
       << "       \\_/ |  \\\\       //|\\   ______/\\)" << "\n"
       << "          \\_|   \\\\     // |\\_/" << "\n"
       << "           \\|\\/|\\_    //  /\\/" << "\n"
       << "             (oo)\\ \\_//  /" << "\n"
       << "            //_/\\_\\/ /  |" << "\n"
       << "           @@/  |=\\  \\  |" << "\n"
       << "                \\_=\\_ \\ |" << "\n"
       << "                 \\==\\ \\|\\_ " << "\n"
       << "               __(\\===\\(  )\\" << "\n"
       << "               __(\\===\\(  )\\" << "\n"
       << "                   (((~)\\  /" << "\n"
       << "                   ______/ /" << "\n"
       << "                   '------'"  << endl;
}

void Dragon::PrintInfo(){
  //add functionality
  printPet();
  cout << "\nPet Info of " << name << ", " << type << ":"
       << "\nMood Level: " << currMood << "/" << MAXMOOD
       << "\nEnergy Level: " << currEnergy << "/" << MAXENERGY
       << "\nFood: " << food
       << "\nToy: " << toy
       << "\nSellable goods: " << goods << endl;
}

void Dragon::savePet(Supplies& supplies) {
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
void Dragon::loadPet(string fileName, Supplies& supplies){
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