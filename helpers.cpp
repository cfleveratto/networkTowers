#include "helpers.h"

//PRE:TowerNet and LValues are defined and have a satisfied CI.
//    inputFile contains information pertaining to the
//    composition of an indirected graph and its coloring
//    seperation rules.  
//POST: TowerNet contains information, as a graph, about the
//       towers and their connectivity
//      TowerNet contains at least one vertex, and is a
//       connected undirected graph.
//      LValues contains the separation values for colours
//       assigned to towers at specified distances. If the
//       length of LValues is r, then any two vertices at
//       distance (r+1) or more can be coloured with the same
//       colour.
//      All separation values are non-zero, positive integers.
//       LValues contains at least one separation value.
void readGraphAndLValues (Graph<Tower *> & TowerNet,
			  List<int> & LValues, ifstream & inputFile) {
  int numTowers; //this will hold the first integer in input
		 //file representing how many towers there
		 //are.  
  inputFile >> numTowers;
  for (int index = 0; (index < numTowers); index ++) {
    Tower * newTower = new Tower(index);
    TowerNet.addVertex(newTower);
    makeConnections(TowerNet, index, inputFile);
    //ASSERT: all the connections in previous Verticies were
    //made to the current vertex and stored in TowerNet. 
    
  }
  //ASSERT: all the tower connections were read in for all
  //verticies in TowerNet.  
  readSepRules(LValues, numTowers, inputFile);
  //ASSERT: the seperation rules which are postive
  //non-negative values were read in and stored in LValues. 
}


//PRE: TowerNet is defined and has a satsfied CI.
//     currentVertex is index in graph that connections are
//     being made for.
//     inputFile stream contains information pertaining to
//     the connections of a vertex.
//POST: Edge objects were created that linked existing
//     verticies to one another. 
void makeConnections (Graph<Tower *> TowerNet, int currentVertex,
		      ifstream & inputFile) {
  bool readConnection; //will hold whether there is a
		       //connection between verticies.  
  for (int index = 0; (index < TowerNet.getNumVertices()); index++) {
    inputFile >> readConnection;
    if (readConnection) {
      //ASSERT: a 1 indicating true was read in from inputFile.
      Tower * fromData = TowerNet.getVertexInfo(currentVertex);
      Tower * toData = TowerNet.getVertexInfo(index);
      //ASSERT fromData and toData point to existing Tower
      //objects allocated on the heap.
      TowerNet.addEdge(fromData, toData);
      //ASSERT: an Edge object was added to the vertex
      //containing currentVertex data and connected it to a
      //vertext containing index data.
      TowerNet.addEdge(toData, fromData);
      //ASSERT: an Edge object was added to the vertex
      //containing index data and connected it to a
      //vertex containing currentVertex data. 
    }
  }
}
      
//PRE: LValues is defined and has a satisfied CI.
//     ruleMax is the largest distance there can be which is
//     equal to the number of towers being read. 
//     InputFile contains a stream of integers on one line
//     indicating a graphs coloring seperation Rules
//POST: LValues contains the separation values for colours
//       assigned to towers at specified distances.
void  readSepRules(List<int> & LValues, int ruleMax,
		   ifstream & inputFile) {
  int rule; //this will hold the seperation rule.
  int place; //this will hold the index in LValues.elements
	     //that rule should be stored
  List<int> readValues(ruleMax); //this will hold temporary rules read in.
  inputFile >> rule;
  while(rule != RULE_BOUND) {
    //ASSERT: rule was read in.
    readValues.addElement(rule, place);
    //ASSERT: rule was added to readValues.elements[place]
    inputFile >> rule;
    place++;
  }
  LValues = readValues;
}


//PRE: TowerNet is defined and has a satisfied CI.
//     outFile is a writeable stream.
//POST: OS contains on the first line the smallest value of
//       the largest colour used in colouring TowerNet. On
//       each of the following n lines, OS contains the
//       name of a tower followed by the colour assigned
//       to that tower followed by the smallest value of
//       colour separation between the colour assigned to
//       that tower and all its neighbouring towers.
//       The towers are on the OS in order of their
//       names.
void printGraph(Graph<Tower *> TowerNet, ofstream & outFile,
	   int largestColor) {
  outFile << "Smallest Value of Largest Color Used: "
	  << largestColor << endl;
  outFile << TowerNet;
}
  
