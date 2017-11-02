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

 public:

  //PRE: newData is a pointer of type T.
  //POST: This object contains T data and connections points
  //to NULL
  Vertex<T> (const T & newData) {
    *data = *newData;
    connections = NULL;
  };

  //PRE: V satisfies the CI
  //POST: This graph is a deep copy of G.
  Vertex<T> (const Vertex<T> & V) {
    *data = *(V.data);
    *connections = *(V.connections);
  };

  //PRE: V is defined
  //POST: RV is (a reference to) a Vertex objects that is a
  //deep copy of V. 
  Vertex<T> & operator = (const Vertex<T> & V) {
    *data = *(V.data);
    *connections = *(V.connections);
    return(*this);
  };

  //Destructor
  ~Vertex<T>() {
    if (connections != NULL) {
      delete connections;
    }
  };
};

#endif
