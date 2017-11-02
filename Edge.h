#ifndef INCLUDED_EDGE
#define INCLUDED_EDGE

#include "Vertex.h"
#include <iostream>
using namespace std;

template <class T> class Vertex;
template <class T>
class Edge {
  //CLASS INVARIENT(CI): data points to an existing Vertex
  //object located on the heap to which an existing Vertex
  //object is connected to. 

  //next and prev points to the next and prev Edge oject
  //that an existing Vertex object is connected to.

 private:
  Vertex<T> * data;
  Edge<T> * next;
  Edge<T> * prev;
  
 public:

  //PRE: None
  //POST: all pointers a set to None
  Edge<T> (Vertex<T> * connection) {
    data = connection;
    next = NULL;
    prev = NULL;
  };

  
  //Deconstructor
  ~Edge<T>() {
    delete data;
    delete next;
    delete prev;
  };
  
};

#endif
