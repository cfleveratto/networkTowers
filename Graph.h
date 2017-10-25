// This class create a graph where the type T is the information, about
// the vertex, stored at each vertex.
template <class T>
class Graph {

  // Objects of this class store undirected graphs.
  
  // ADD CI

 private:

  // MEMBER DATA HERE

  // The graph class must store the vertices as a linked list. Each of
  // the nodes of this linked list must contain an object of type T,
  // i.e., the information for a vertex, and a linked list (or a
  // pointer to a linked list) that contains the edges that this
  // vertex is a member of. Each of the nodes in the list of edges
  // must contain, as its data, a pointer to the appropriate node in the
  // list of vertices.
  
 public:
  // PRE:
  // POST: This graph is an empty graph.
  Graph<T> ();

  // PRE: G satisfies the CI
  // POST: This graph is a deep copy of G.
  Graph<T> (const Graph<T> & G);

  // PRE: G is defined.
  // POST: RV is (a reference to) a graph that is a deep copy of G. 
  Graph<T> & operator = (const Graph<T> & G);
  
  // PRE: data is defined, and there is no vertex in this graph
  //         containing data.
  // POST: This graph contains a vertex containing data.
  //         The new vertex is not a member of any edges.
  void addVertex (const T & data);

  // PRE: fromData and toData are defined, and this graph contains a
  //        vertex, u, containing fromData as 
  //        information, and a vertex, v, containing toData as
  //        information.
  // POST: An edge is added connecting u and v.
  void addEdge (const T & fromData, const T & toData);

  // PRE: data is defined.
  // POST: RV = the index of the vertex, if any, containing data.
  //          If no such vertex exists, RV = -1.
  int vIndexOf (const T & data) const;
  
  // POST: RV = the number of vertices in this graph.
  int getNumVertices () const;

  // PRE: vIndex < number of vertices in this graph
  // POST: RV = the vertex information for vertex at vIndex.
  T getVertexInfo (int vIndex) const;

  // PRE: vIndex < number of vertices in this graph
  // POST: RV = the number of edges that the vertex at vIndex is a
  //              member of. 
  int getNumEdges (int vIndex) const;

  // POST: RV = a pointer to a list of vertices in some order (perhaps
  //              the order in which the vertices were created).
  //              This is a dynamically created list
  //              and needs to be deleted after use.
  //            The returned list must be a deep copy of the list of
  //              vertices stored in the graph.
  List<T> * getVertices () const;


  // PRE: This is a connected graph.
  // POST: RV = a pointer to a list of vertices in depth-first order
  //              traversal. 
  //              This is a dynamically created list
  //              and needs to be deleted after use.
  List<T> * getVerticesDepthFirst () const;

  
  // PRE: vIndex < number of vertices in this graph
  // POST: RV = a pointer to a list of vertices (in any order) that
  //              contain information for those vertices v such that u-v is an
  //              edge in the graph (where u is the vertex at vIndex).
  //              This is a dynamically created list
  //              and needs to be deleted after use.
  //            The returned list must be a deep copy of the list of
  //              edges stored in the graph.
  List<T> * getNeighbours (int vIndex) const;

  // PRE: data is defined, and a vertex, u, in the graph contains data.
  // POST: RV = a pointer to a list of vertices (in any order) that
  //              contain information for those vertices v such that u-v is an
  //              edge in the graph.
  //              This is a dynamically created list
  //              and needs to be deleted after use.
  //            The returned list must be a deep copy of the list of
  //              edges stored in the graph.
  List<T> * getNeighbours (const T & data) const;

  // PRE: vIndex < number of vertices in this graph.
  // POST: The vertex at vIndex is removed from the graph along with
  //          any edges that the vertex is a member of.
  void deleteVertex (int vIndex);

  // PRE: data is defined.
  // POST: The vertex, if any, containing data is removed from the
  //          graph along with any edges that the vertex is a member
  //          of. 
  void deleteVertex (const T & data);

  // PRE: vInindex < number of vertices in this graph.
  //      eIndex < number of edges that the vertex at vIndex is a
  //         member of
  // POST: The edge at eIndex that the vertex at vIndex is a part of
  //         is removed from the graph.
  void deleteEdge (int vIndex, int eIndex);

  // PRE: fromData and toData are defined.
  // POST: The edge, if any, containing the vertex, if any, containing
  //         fromData and the vertex, if any, containing toData is
  //         removed from the graph.
  void deleteEdge (const T & fromdata, const T & toData);

  // Destructor
  ~Graph<T>();
};
