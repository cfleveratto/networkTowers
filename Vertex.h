#ifndef INCLUDED_VERTEX
#define INCLUDED_VERTEX

#include "Edge.h"
#include <iostream>
#include <fstream>

using namespace std;

template<class T>
class Vertex {
  //Class Invarient (CI): data is a pointer of type T.

  //If this vertex is connected to other verticies then Edge
  //points to those connections

 private:
  T data; //this will hold data of type T.
  Edge<T> * connections; //this will hold a pointer
                         //to a Edge object
  Vertex<T> * next; //this will hold the pointer to the next Vextex in
	           //this graph.
  int numConnections; //this will hold the number of edges
		      //this vertex is a member of.

 public:

  //PRE: newData is a pointer of type T.
  //POST: This object contains T data and connections points
  //to NULL
  Vertex<T> (const T & newData) {
    *data = *newData;
    connections = NULL;
    next = NULL;
    numConnections = 0;
  };

  //PRE: V satisfies the CI
  //POST: This graph is a deep copy of G.
  Vertex<T> (const Vertex<T> & V) {
    *data = *(V.data);
    *connections = *(V.connections);
    *next = *(V.connections);
    numConnections = V.numConnections;
  };

  //PRE: V is defined
  //POST: RV is (a reference to) a Vertex objects that is a
  //deep copy of V. 
  Vertex<T> & operator = (const Vertex<T> & V) {
    *data = *(V.data);
    *connections = *(V.connections);
    if (next != NULL) {
      *next = *(V.next);
    }
    numConnections = V.numConnections;
    return(*this);
  };

  //==============================================
  //                  ACCESSORS
  //==============================================
  //PRE: this objects satisfies the CI
  //POST: RV equals data
  T getData() {
    return(data);
  };

  //PRE: this objects satisfies the CI
  //POST: RV is a pointer to Vertex<T> object 
  Vertex<T> * getNext() {
    return(next);
  };

  //=============================================
  //                  MODIFIERS
  //=============================================

  //PRE:
  //POST:
  void setNextPointer(Vertex<T> * nextVertex) {
    next = nextVertex;
  };
  
  //Destructor
  ~Vertex<T>() {
    if (connections != NULL) {
      delete connections;
    }
    if (next != NULL) {
      delete next;
    }
  };

  void addConnection(Vertex<T> * aPointer) {
    Edge<T> * newEdge = new Edge<T>(aPointer);
    Edge<T> * currentEdge = connections;
    while(currentEdge->getNext() != NULL) {
      //ASSERT: last Edge wasn't reached.
      currentEdge = currentEdge->getNext();
    }
    newEdge->setPrevPointer(currentEdge);
    currentEdge->setNextPointer(newEdge);
  };
    
  friend ofstream & operator << (ofstream & stream,
				 const Vertex<T> & V) {
    stream << V.data;
    return (stream);
  };
};

#endif
