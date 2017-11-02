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
