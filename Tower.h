#ifndef INCLUDED_TOWER
#define INCLUDED_TOWER

#include <iostream>
#include <fstream>

using namespace std;
class Tower {
  //CLASS INVARIENT (CI): name and color are nonnegative
  //integers representing the name and coloring of this
  //tower.

  

 private:
  int name;
  int coloring;

 public:

  //default consructor
  Tower();
  
  //PRE: None
  //POST: towerName is now held at name
  Tower(int towerName);

  //PRE: T is defined
  //POST: this objects contains the data member objects of T
  Tower(const Tower & T);

  //PRE: This object is defined
  //POST: RV is (a reference to) a Tower object that is a
  //copy of T
  Tower & operator = (const Tower & T);

  void assignColor(int color);

  //PRE: This object and T are defined
  //POST: RV = true if the name member both are the same integer
  bool operator == (const Tower & T) const;

  //Overloaded output file stream
  friend ofstream & operator << (ofstream & stream,
				  const Tower & T);
  friend ostream & operator << (ostream & stream,
				 const Tower & T);

};

#endif
