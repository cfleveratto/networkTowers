#include "helpers.h"
#include "Graph.h"
#include "List.h"
#include "Tower.h"
#include <fstream>

using namespace std;

readGraphAndLValues (Graph<Tower *> & TowerNet, const List<int> & LValues, ifstream & inputFile) {
  int numTowers; //this will hold the first integer in input file representing how many towers there are.
  inputFile >> numTowers;
  for (int index = 0; (index < numTowers); index ++) {
    Tower * newTower = new Tower(index);
    TowerNet.addVertex(newTower);
    //makeConnections(TowerNet, inputFile);
    //ASSERT: all the connections in previous Verticies were made to the current vertex and stored in TowerNet.
    
  }
  //ASSERT: all the tower connections were read in for all verticies in TowerNet. 
  //readSepRules(LValues, inputFile);
  //ASSERT: the seperation rules which are postive non-negative values were read in and stored in LValues
}
