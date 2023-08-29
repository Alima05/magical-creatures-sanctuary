#include "Supplies.h"

Supplies::Supplies() {
  numTaka = 50;
  numDaisies = 5;
  numMice = 0;
  numCarrots = 0;
  numSaddles = 0;
  numYarn = 0;
  numHoards = 0;
  numHairs = 0;
  numFeathers = 0;
  numScales = 0;
}

//money
int Supplies::GetNumTaka() {
  return numTaka;
}
void Supplies::SetNumTaka(int t) {
  numTaka = t;
}

//food
int Supplies::GetNumDaisies() {
  return numDaisies;
}
int Supplies::GetNumMice(){
  return numMice;
}
int Supplies::GetNumCarrots(){
  return numCarrots;
}

void Supplies::SetNumDaisies(int d){
  numDaisies = d;
}
void Supplies::SetNumMice(int m){
  numMice = m;
}
void Supplies::SetNumCarrots(int c){
  numCarrots = c;
}

//toys
int Supplies::GetNumSaddles() {
  return numSaddles;
}
int Supplies::GetNumYarn(){
  return numYarn;
}
int Supplies::GetNumHoards(){
  return numHoards;
}

void Supplies::SetNumSaddles(int s){
  numSaddles = s;
}
void Supplies::SetNumYarn(int y){
  numYarn = y;
}
void Supplies::SetNumHoards(int ch){
  numHoards = ch;
}

//sellable goods
int Supplies::GetNumHairs(){
  return numHairs;
}
int Supplies::GetNumFeathers(){
  return numFeathers;
}
int Supplies::GetNumScales(){
  return numScales;
}

void Supplies::SetNumHairs(int h){
  numHairs = h;
}
void Supplies::SetNumFeathers(int f){
  numFeathers = f;
}
void Supplies::SetNumScales(int s){
  numScales = s;
}

void Supplies::printCertificate(){
  cout << "              _______________________" << "\n"
       << "            =(__   _ ___    _  __   _)=" << "\n"
       << "              |                     |" << "\n"
       << "              | ******************* |" << "\n"
       << "              |   CERTIFICATE FOR   |" << "\n"
       << "              |     THE CARE OF     |" << "\n"
       << "              |  MAGICAL CREATURES  |" << "\n"
       << "              | ******************* |" << "\n"
       << "              |__  _  ___   __  ____|" << "\n"
       << "            =(_______________________)=" <<  endl;
}

void Supplies::printSupplies(){
  cout << "\nYou own... " 
       << "\nWallet: " << numTaka << " taka"
       << "\nDaises: " << numDaisies
       << "\nSaddles: " << numSaddles
       << "\nUnicorn Hairs: " << numHairs << "\n"
       << "\nMice: " << numMice
       << "\nBalls of Yarn: " << numYarn
       << "\nGryphon Feathers: " << numFeathers << "\n"
       << "\nFire Carrots: " << numCarrots
       << "\nCoin Hoards: " << numHoards
       << "\nDragon Scales: " << numScales << endl;
}