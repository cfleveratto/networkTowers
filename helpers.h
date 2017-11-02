#ifndef INCLUDED_HELPERS
#define INCLUDED_HELPERS

//PRE:TowerNet and LValues are defined and have a satisfied CI.
//    inputFile is a changeable stream
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
readGraphAndLValues (Graph<Tower *> TowerNet, List<int> LValues, ifstream & inputFile);

#endif
