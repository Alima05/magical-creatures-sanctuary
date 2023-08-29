#ifndef SUPPLIESH
#define SUPPLIESH
#include <iostream>
using namespace std;

class Supplies {
public:
  Supplies(); //initializes taka to 100, numUnicorns to 1, and numGryphons and numDragons to 0, initializes pet vector with 1 unicorn, food vector with 5 daisies
  //void addPet(const Pet & newPet);
  int GetNumTaka();
  void SetNumTaka(int t);

  int GetNumDaisies();
  int GetNumMice();
  int GetNumCarrots();

  void SetNumDaisies(int d);
  void SetNumMice(int m);
  void SetNumCarrots(int c);

  int GetNumSaddles();
  int GetNumYarn();
  int GetNumHoards();

  void SetNumSaddles(int s);
  void SetNumYarn(int y);
  void SetNumHoards(int ch);

  int GetNumHairs();
  int GetNumFeathers();
  int GetNumScales();

  void SetNumHairs(int h);
  void SetNumFeathers(int f);
  void SetNumScales(int s);

  void printCertificate();
  void printSupplies();

private:
  int numTaka;
  int numDaisies, numMice, numCarrots;
  int numSaddles, numYarn, numHoards;
  int numHairs, numFeathers, numScales;
  bool certificate; //will only display ascii of certificate if this is true
};

#endif