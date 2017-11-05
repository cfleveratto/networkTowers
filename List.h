#ifndef INCLUDED_LIST
#define INCLUDED_LIST
#include <iostream>
using namespace std;

template <class T>
class List {
  //Class Invarient(CI): elements points to an array of
  //numElements objects allocated on the heap where
  //numElements > 0;  
  //Otherwise elements points to NULL

 private:
  T * elements; //this will point to a list of T type
		//objects allocated on the heap. 
  int numElements; //this will hold the amount of elements

 public:
  
  //PRE: None
  //POST: this object is empty.
  List<T> () {
    elements = NULL;
    numElements = 0;
  };

  //PRE: listMax is the maximum amount of T type objects in
  //an array that elements points to. 
  List<T> (int listMax) {
    elements = new T[listMax];
    numElements = 0;
  };

  //PRE: L is a defined List<T> object
  //POST: this object is a deep copy of L and has a satisfied CI.
  List<T> (const List<T> & L) {
    elements = new T[L.numElements];
    for (int index = 0; (index < numElements); index++) {
      elements[index] = L.elements[index];
    }
    numElements = L.numElements;
  };

  //PRE: L is a defined List<T> object
  //POST: RV is a reference to a List object that is a deep
  //copy of L. 
  List & operator = (const List<T> & L) {
    delete [] elements;
    elements = new T[L.numElements];
    for (int index = 0; (index < numElements); index++) {
      elements[index] = L.elements[index];
    }
    numElements = L.numElements;
    return (*this);
  };

  //PRE: element is a T type object 
  //POST: element was added to elements[index]
  void addElement(const T & element, int index) {
    elements[index] = element;
    numElements++;
  };
  //deconstructor
  //PRE: None
  //POST: deletes the objects that are stored in an array
  //that elements points to.  
  ~List<T> () {
    delete [] elements;
  };

  friend ofstream & operator << (ofstream & stream,
				 const List<T> & L) {
    for (int index = 0; (index < L.numElements); index++) {
      stream << "List Data"
	     << L.elements[index] << endl;
    }
    return (stream);
  };
};

#endif
