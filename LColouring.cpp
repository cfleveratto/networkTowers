#include "helpers.h"
#include "List.h"
#include "Tower.h"
#include "Graph.h"
#include <fstream>
#include <iostream>

using namespace std;

// This program finds the least number of colours/frequencies that are
//   needed for assigning colours to towers in a network of towers so
//   that given constraints on the separation of colours between colours
//   assigned to towers are satisfied.
// The distance between two towers is the number of edges in a
//   shortest path between the two towers.
// The assigned colours are non-negative integers, 0, 1, 2, ....
// The separation between colours is the difference in the integer
//   values.
// The difference is calculated modulo the largest colour being
//   used. That is, if the largest colour being used is T, then the
//   difference between the colours 0 and T is 1, the difference
//   between the colours 1 and T is 2, etc.
// Note that if T is used to colour some tower, but there some colours
//   less than T that are not used to colour any tower, the largest
//   colour being used is still T. For example, a network of only two
//   towers that are connected, where the constraint is that
//   neighbouring towers must have colours separated by 3, could be
//   coloured with the colours 2 and 5 (but not by 0 and 3, or 1 and
//   4). Thus, in this case the largest colour used in 5. In this
//   case, 5 is also the smallest number such that the towers can be
//   coloured while satisfying the separation constraints.

// PRE: argc = 3. argv[1] is the input file name. argv[2] is the
//        output file name.
//      The first line of the input file will contain one integer, n >
//        0, indicating the number of towers.
//      The next n lines will contain information about the
//        connectivity of the towers named 0 through (n-1) in that
//        order. Each line will contain information about one
//        tower. Information for the connectivity of tower i will
//        consist of (i+1) integer values. Each of these integer value
//        will be a 0 or a 1. If the j-th (j >= 0) integer value is a
//        0 then the tower named i is not connected to the tower named
//        j. If the j-th integer value is a 1 then the tower named i
//        is connected to the tower named j. The integer values will
//        be separated by one space. Essentially, these n lines will
//        be the lower triangle (including the diagonal) of the
//        adjacency matrix for the graph corresponding to the network
//        of towers.
//      The last line of the file (i.e., the (n+2)-th line) will
//        contain (r+1) integers denoting the separation values for
//        colours assigned to towers at distances 1, ..., r. Each of
//        these r integer values will be positive, non-zero integers.
//        The (r+1)-th integer will be 0. 
//      An example input file:
//      ----------------------
//      4
//      0
//      0 0
//      1 1 0
//      0 1 0 0
//      3 1 0
//      ----------------------
//      This file indicates that there are 4 towers, where the tower named
//        0 is connected to tower 2, tower 1 is connected to towers 2
//        and 3, tower 2 is connected to towers 0 and 1 and tower 3 is
//        connected to tower 1.
//      The separation values indicate that towers at distance 1 need
//        to have a separation of at least 3 in their colours and
//        towers at distance 2 need to have a separation of at least 1
//        in their colours. Towers at distance 3 or more need not have
//        any separation in their colours.
//      Note that since this is an undirected graph, specifying only
//        the lower triangle of the adjacency matrix is adequate.
// POST: OS contains the smallest value of the largest colour needed
//        to colour all the towers in TowerNet satisfying the
//        constraints given, and for each tower, its name, the colour
//        assigned to the tower and the smallest separation between
//        this colour and colours assigned to the tower's neighbours.
int main (int argc, char * argv[]) {

  if (argc == 3) {
    // ASSERT: The number of arguments is correct.
    ifstream inFile (argv[1]); // inFile is the input file stream
			       // corresponding to the file with name in
			       // argv[1]. 
    ofstream outFile (argv[2]); // outFile is the output file stream
				// corresponding to the file with name
				// in argv[2]
    if ((inFile != NULL) && (outFile != NULL)) {

      Graph<Tower *> TowerNet; // TowerNet will hold a graph of all the
      // cell towers. The cell towers are "named"
      // by positive integers starting at 0.
        
      List<int> LValues;   // LValues will hold the separation
      // values for colours/frequencies
      // assigned to towers at specified
      // distances. In particular, if
      // LValues[i] = k, (i starting at 1) then
      // any two vertices at distance i must be
      // assigned colours whose difference (as
      // defined above) is at least k. 
        
      readGraphAndLValues (TowerNet, LValues, inFile);
      // ASSERT: TowerNet contains information, as a graph, about the
      //            towers and their connectivity
      //         TowerNet contains at least one vertex, and is a
      //            connected undirected graph.
      //         LValues contains the separation values for colours
      //           assigned to towers at specified distances. If the
      //           length of LValues is r, then any two vertices at
      //           distance (r+1) or more can be coloured with the same
      //           colour.
      //         All separation values are non-zero, positive integers.
      //         LValues contains at least one separation value.
    
      int largestColourNeeded = 3; // will hold the largest colour needed
      // for colouring TowerNet with the constraints
      // given by LValues.
      //colourGraph (TowerNet, LValues, largestColourNeeded);
      // ASSERT: numColoursUsed is the smallest value of the largest
      //           colour used to colour TowerNet while
      //           satisfying the constraints given by LValues.
      //         The vertices of TowerNet contain information about the
      //           towers, including the colours assigned to the towers.
    
      printGraph (TowerNet, outFile, largestColourNeeded);
      // ASSERT: OS contains on the first line the smallest value of
      //           the largest colour used in colouring TowerNet. On
      //           each of the following n lines, OS contains the
      //           name of a tower followed by the colour assigned
      //           to that tower followed by the smallest value of
      //           colour separation between the colour assigned to
      //           that tower and all its neighbouring towers.
      //           The towers are on the OS in order of their
      //           names. 
    }
    else {
      // ASSERT: Input file or output file could not be opened
      cout << "Input file or Output file could not be opened." << endl;
    }
  }
  else {
    // ASSERT: incorrect number of arguments
    cout << "Usage: ./LColouring <input file name> <output file name>"
	 << endl; 
  }
  return (0);
}
