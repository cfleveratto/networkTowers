#ifndef INCLUDED_TOWER
#define INCLUDED_TOWER

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
  
};

#endif
