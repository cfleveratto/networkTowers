#ifndef INCLUDED_VERTEX
#define INCLUDED_VERTEX
#include "Tower.h"
#include "Edge.h"
#include <iostream>
#include <fstream>

using namespace std;

template<class T>
class Vertex {
  //Class Invarient (CI): data is a pointer of type T.

  //If this vertex is connected to other verticies then
  //connections will hold edge objects that contains
  //pointers to those other Vertex objects and
  //numConnections > 0.

  //next points to the next vertex


 private:
  T data; //this will hold data of type T.
  Edge<T> * connections; //this will hold a pointer
                         //to a Edge object
  Vertex<T> * next; //this will hold the pointer to the next Vextex in
	           //this graph.
  int numConnections; //this will hold the number of edges
		      //this vertex is a member of.

 public:

  Vertex<T> () {
    data = NULL;
    connections = NULL;
    next = NULL;
    numConnections = 0;
  };

  //PRE: newData is a pointer of type T.
  //POST: This object contains T data and connections points
  //to NULL
  Vertex<T> (const T & newData) {
    data = newData;
    connections = NULL;
    next = NULL;
    numConnections = 0;
  };

  //PRE: V satisfies the CI
  //POST: This graph is a deep copy of G.
  Vertex<T> (const Vertex<T> & V) {
    *data = *(V.data);
    *connections = *(V.connections);3
    *next = *(V.connections);
    numConnections = V.numConnections;
  };

  //PRE: V is defined
  //POST: RV is (a reference to) a Vertex objects that is a
  //deep copy of V. 
  Vertex<T> & operator = (const Vertex<T> & V) {
    if (data != NULL) {
      cout << "if conndition for data" << endl;
      delete data;
      //prevents memory leak
      data = new Tower(*(V.getData()));
      //ASSERT copy is a pointer to the data at V.data memory location
    }
    else {
      *data = *(V.data); //ensures that data is always copied
    }
    
    if (connections != NULL) {
      cout << " If condition for connections : " << endl;
      //ensures that connections is copied only when V has connections
      delete connections;
      *connections = *(V.connections);
    }
    if (next != NULL) {
      cout << " If condition for next : " << endl;
      //ensures that connected is copied only when V has connections
      delete connections;
      *next = *(V.next);
    }
    numConnections = V.numConnections;
    cout << "Exiting overloaded = operator: " << endl;
    return(*this);
  };

  //==============================================
  //                  ACCESSORS
  //==============================================
  //PRE: this objects satisfies the CI
  //POST: RV equals data
  T getData() const {
    return(data);
  };

  //PRE: this objects satisfies the CI
  //POST: RV is a pointer to Vertex<T> object 
  Vertex<T> * getNext() const {
    return(next);
  };

  //access numConnections member data
  int getNumEdges() {
    return(numConnections);
  }

  Edge<T> * getConnections() {
    return(connections);
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
    if (data != NULL) {
      delete data;
    }
    if (connections != NULL) {
      delete connections;
    }
    if (next != NULL) {
      delete next;
    }
  };

  void addConnection(Vertex<T> * aPointer) {
    
    Edge<T> * newEdge = new Edge<T>(aPointer);
    if (numConnections == 0) {
      connections = newEdge;
    }
    else {
      Edge<T> * currentEdge = connections;
      while(currentEdge->getNext() != NULL) {
	//ASSERT: last Edge wasn't reached.
	currentEdge = currentEdge->getNext();
      }
      newEdge->setPrevPointer(currentEdge);
      currentEdge->setNextPointer(newEdge);
    }
    numConnections++;
  };
    
  friend ofstream & operator << (ofstream & stream,
				 const Vertex<T> & V) {
    stream << *(V.data);
    /* if (V.numConnections != 0) { */
    /*   stream << *(V.connections); */
    /* }	 */
    return (stream);
  };

  friend ostream & operator << (ostream & stream,
				 const Vertex<T> & V) {
    stream << *(V.data);
    /* if (V.numConnections != 0) { */
    /*   stream << *(V.connections); */
    /* } */	
    return (stream);
  };

};

#endif
