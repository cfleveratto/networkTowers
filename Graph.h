#ifndef INCLUDED_GRAPH
#define INCLUDED_GRAPH
#include "Vertex.h"
#include "List.h"

// This class create a graph where the type T is the information, about
// the vertex, stored at each vertex.
template <class T>
class Graph {
  // Class Invarient (CI): this object will hold objects
  // that represent an undirected graph.

  // if numVerticies = 0 then root and tail point to NULL;
  // otherwise for i in n where 0 <= i <
  // n = numVerticies, i is a Vertex object containing T type
  // object in order of how it was read in.

  // root points to a Vertex object that was read in first and last
  // points to the (n - 1)th Vertex object that was read in
  // last. 

 private:
  Vertex<T> * root; //This will point the first Vertex object
		  //in the graph
  Vertex<T> * tail; //This will point to the last Vertex in the graph
  int numVerticies; //this will hold the number of verticies
		    //in this graph.
 
  // The graph class must store the vertices as a linked list. Each of
  // the nodes of this linked list must contain an object of type T,
  // i.e., the information for a vertex, and a linked list (or a
  // pointer to a linked list) that contains the edges that this
  // vertex is a member of. Each of the nodes in the list of edges
  // must contain, as its data, a pointer to the appropriate node in the
  // list of vertices.
  
 public:
  
  // PRE: None
  // POST: This graph is an empty graph.
  Graph<T> () {
    root = NULL;
    tail = NULL;
    numVerticies = 0;
  };
    

  // PRE: G satisfies the CI
  // POST: This graph is a deep copy of G.
  Graph<T> (const Graph<T> & G) {
    *root = *(G.root);
    //ASSERT: root is a hard copy of G.root
    Vertex<T> * nextVertex = root;
    while(nextVertex->getNext() != NULL) {
      nextVertex = nextVertex->getNext();
    }
    tail = nextVertex;
    //ASSERT: tail is a pointer to the last Vertex Node
    //contained in root.
    numVerticies = G.numVerticies;
  };
    
  // PRE: G is defined.
  // POST: RV is (a reference to) a graph that is a deep copy of G. 
  Graph<T> & operator = (const Graph<T> & G) {
    *root = *(G.root);
    //ASSERT: root is a hard copy of G.root
    Vertex<T> * nextNode = root;
    while(nextNode->getNext() != NULL) {
      nextNode = nextNode->getNext();
    }
    //ASSERT: last Vertex in graph in found
    tail = nextNode;
    //ASSERT: tail is a pointer to the last Vertex Node
    //contained in root.
    numVerticies = G.numVerticies;
    return(*this);
  };
    
  
  // PRE: data is defined, and there is no vertex in this graph
  //         containing data.
  // POST: This graph contains a vertex containing data.
  //         The new vertex is not a member of any edges.
  void addVertex (const T & data) {
    Vertex<T> * newNode = new Vertex<T>(data);
    //ASSERT: a new Vertex object containing T data was created.
    Vertex<T> * currentNode = root;
    //ASSERT: a pointer was created for the root Vertex
    //object. 
    while(currentNode->getNext() != NULL) {
      //ASSERT: the last Vertex object wasn't reached. 
      currentNode = currentNode->getNext();
    }
    currentNode->setNextPointer(newNode);
    //ASSERT: the Vertex Object that tail->next points to is newNode;
    tail = newNode;
    //ASSERT: tail now points to the memory location of
    //newNode
    numVerticies++;
  };

  // PRE: fromData and toData are defined, and this graph contains a
  //        vertex, u, containing fromData as 
  //        information, and a vertex, v, containing toData as
  //        information.
  // POST: An edge is added connecting u and v.
  void addEdge (const T & fromData, const T & toData) {
    int fromVertex = vIndexOf(fromData); //will hold position in
				     //graph containing
				     //fromData. 
    int toVertex = vIndexOf(toData); //will hold position in
				     //graph containing toData
    Vertex<T> * currentVertex = root; //will hold pointer to
				      //current Vertex
    int currentIndex = 0; //will hold current index of
			  //Vertex being visited in this
			  //object.
    Vertex<T> * fromPtr; //will point to vertex at index
			 //fromVertex
    Vertex<T> * toPtr; // will point ot vertex at index
		       // toVertex
    
    bool foundFrom = false;
    bool foundTo = false;
    while (!foundFrom || !foundTo) {
      if(!fromFrom && (fromVertex == currentIndex)) {
	foundFrom = true;
	fromPtr = currentVertex;
      }
      else if(!foundTo && (toVertex == currentIndex)) {
	foundTo = true;
	toPtr = currentVertex;
      }
      currentIndex++;
    }
    fromPtr->addConnection(toPtr);
    //ASSERT: an edge object was added to the linked list of
    //edge object that fromPtr.Edges contains
    toPtr->addConnection(fromPtr);
    //ASSERT: an edge object was added to the linked list of
    //edge object that toPtr.Edges contains
  };
    

  };

  // PRE: data is defined.
  // POST: RV = the index of the vertex, if any, containing data.
  //          If no such vertex exists, RV = -1.
  int vIndexOf (const T & data) const {
    int index = -1; //will hold the index in Graph of where
		   //Vertex with data is held.  
    bool found = false; //will hold the whether the vertex
			//was found.
    Vertex<T> * currentVertex; //will point to current
			       //Vertex
    currentVertex = root;
    while (!found && (index < numVerticies)) {
      if (*(currentVertex->getData()) == data) {
	found = true;
      }
      currentVertex = currentVertex->getNext();
      index++;
    }
    if (!found) {
      index = -1;
    }
    return(index);
  };
  
  // POST: RV = the number of vertices in this graph.
  int getNumVertices () const {
    return (numVerticies);
  };

  // PRE: vIndex < number of vertices in this graph
  // POST: RV = the vertex information for vertex at vIndex.
  T getVertexInfo (int vIndex) const {
    Vertex<T> * currentVertex = root;
    int currentIndex = 0;
    while(currentIndex < vIndex) {
      currentVertex = currentVertex->getNext();
    }
    return(currentVertex->getData());
  };
      


  // PRE: vIndex < number of vertices in this graph
  // POST: RV = the number of edges that the vertex at vIndex is a
  //              member of. 
  int getNumEdges (int vIndex) const {

  };

  // POST: RV = a pointer to a list of vertices in some order (perhaps
  //              the order in which the vertices were created).
  //              This is a dynamically created list
  //              and needs to be deleted after use.
  //            The returned list must be a deep copy of the list of
  //              vertices stored in the graph.
  //List<T> * getVertices () const;


  // PRE: This is a connected graph.
  // POST: RV = a pointer to a list of vertices in depth-first order
  //              traversal. 
  //              This is a dynamically created list
  //              and needs to be deleted after use.
  //List<T> * getVerticesDepthFirst () const;

  
  // PRE: vIndex < number of vertices in this graph
  // POST: RV = a pointer to a list of vertices (in any order) that
  //              contain information for those vertices v such that u-v is an
  //              edge in the graph (where u is the vertex at vIndex).
  //              This is a dynamically created list
  //              and needs to be deleted after use.
  //            The returned list must be a deep copy of the list of
  //              edges stored in the graph.
  //List<T> * getNeighbours (int vIndex) const;

  // PRE: data is defined, and a vertex, u, in the graph contains data.
  // POST: RV = a pointer to a list of vertices (in any order) that
  //              contain information for those vertices v such that u-v is an
  //              edge in the graph.
  //              This is a dynamically created list
  //              and needs to be deleted after use.
  //            The returned list must be a deep copy of the list of
  //              edges stored in the graph.
  //List<T> * getNeighbours (const T & data) const;

  // PRE: vIndex < number of vertices in this graph.
  // POST: The vertex at vIndex is removed from the graph along with
  //          any edges that the vertex is a member of.
  void deleteVertex (int vIndex) {

  };

  // PRE: data is defined.
  // POST: The vertex, if any, containing data is removed from the
  //          graph along with any edges that the vertex is a member
  //          of. 
  void deleteVertex (const T & data) {

  };

  // PRE: vInindex < number of vertices in this graph.
  //      eIndex < number of edges that the vertex at vIndex is a
  //         member of
  // POST: The edge at eIndex that the vertex at vIndex is a part of
  //         is removed from the graph.
  void deleteEdge (int vIndex, int eIndex) {

  };

  // PRE: fromData and toData are defined.
  // POST: The edge, if any, containing the vertex, if any, containing
  //         fromData and the vertex, if any, containing toData is
  //         removed from the graph.
  void deleteEdge (const T & fromdata, const T & toData) {

  };

  // Destructor
  ~Graph<T>() {
    tail = NULL;
    delete root;
  };

  friend ofstream & operator << (ofstream & stream,
				 const Graph<T> & G) {
    Vertex<T> * currentVertex = G.root;
    while (currentVertex != NULL) {
      stream << *currentVertex;
      currentVertex = currentVertex->getNext();
    };
    return (stream);
  };
  
};

#endif
