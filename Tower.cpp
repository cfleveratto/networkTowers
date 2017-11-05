#include "Tower.h"

Tower::Tower() {
  name = -1;
  coloring = -1;
}

Tower::Tower(int towerName) {
  name = towerName;
  coloring = -1;
}

Tower::Tower(const Tower & T) {
  name = T.name;
  coloring = T.coloring;
}

Tower & Tower::operator = (const Tower & T) {
  name = T.name;
  coloring = T.coloring;
  return (*this);
}


//PRE: This object and T are defined
//POST: RV = true if the name member both are the same integer
bool Tower::operator == (const Tower & T) const {
  return(name == T.name);
}

ofstream & operator << (ofstream & stream,
			 const Tower & T) {
  stream << "Tower Name: "
	 << T.name << endl;
  stream << "Tower Coloring: "
	 << T.coloring << endl;
  return (stream);
}

