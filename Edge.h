#ifndef INCLUDED_EDGE
#define INCLUDED_EDGE

#include "Vertex.h"
#include <iostream>
#include <fstream>
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

  Edge<T> () {
    data = NULL;
    next = NULL;
    prev = NULL;
  };

  //PRE: connection is a pointer to a defined Vertex
  //object. 
  //POST: all pointers a set to None
  Edge<T> (Vertex<T> * connection) {
    data = connection;
    next = NULL;
    prev = NULL;
  };

  //PRE: this obejct satisfies CI.
  //POST: RV is a pointer to a Vertex<T> object
  Vertex<T> * getData() {
    return(data);
  };

  //Accessor to next member data
  Edge<T> * getNext() {
    return (next);
  };

  //Accessor to prev member data
  Edge<T> * getPrev() {
    return (prev);
  };

  //Modifier to next member data
  void setNextPointer(Edge<T> * nextEdge) {
    next = nextEdge;
  };

  //MOdifier to prev member data
  void setPrevPointer(Edge<T> * prevEdge) {
    prev = prevEdge;
  };
  
  Edge<T> & operator = (const Edge<T> & E) {
    data = E.data;
    if (E.next != NULL) {
      *next = *(E.next);
    }
    prev = E.prev;
  };
  //Deconstructor
  //POST: Deletes current Edge object off heap and all edge
  //objects next points to.
  ~Edge<T>() {
    if (next != NULL) {
      delete next;
      //prev does not need to be deleted since it was
      //already deleted in by its own deconstrucor.
    }
  };

  friend ostream & operator << (ostream & stream,
  				 const Edge<T> & E) {
    stream << "Connections for this Vertex:\n";
    stream << *(E.data);
    if (E.next != NULL) {
      stream << *(E.next);
    }
    stream << endl;
    return (stream);
  };

};

#endif
