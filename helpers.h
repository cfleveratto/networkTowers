#ifndef INCLUDED_HELPERS
#define INCLUDED_HELPERS
#include "Graph.h"
#include "List.h"
#include "Tower.h"
#include <fstream>

#define RULE_BOUND 0

using namespace std;


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
void readGraphAndLValues (Graph<Tower *> & TowerNet, List<int> & LValues,
		     ifstream & inputFile);

//PRE: TowerNet is defined and has a satsfied CI
//     currentVertex is index in graph that connections are
//     being made for.
//     inputFile stream contains information pertaining to
//     the connections of a vertex.
//POST: Edge objects were created that linked existing
//     verticies to one another. 
void makeConnections (Graph<Tower *> TowerNet, int currentVertex,
		      ifstream & inputFile);
//PRE: LValues is defined and has a satisfied CI.
//     ruleMax is the largest distance there can be which is
//     equal to the number of towers being read. 
//     InputFile contains a stream of integers on one line
//     indicating a graphs coloring seperation Rules
//POST: LValues contains the separation values for colours
//       assigned to towers at specified distances.
void  readSepRules(List<int> & LValues, int ruleMax,
		   ifstream & inputFile);

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
	   int largestColor);
#endif
