#pragma once
#include <iostream>
#include <vector>


using namespace std;

template <class Vertex, class Edge> class GraphForm {
public:
  GraphForm(bool directed) {
    this->directed = directed;
    edge_number = 0;
    vertex_number = 0;
    cout << "GraphForm()\n";
  }

  ~GraphForm() { Clear(); }
  
  void Clear() {
    cout << "clear\n";
    for (int i = 0; i < matrix.size(); i++)
      matrix[i].clear();
    matrix.clear();
    vertex_number = 0;
    edge_number = 0;
  }

  virtual Vertex *InsertV() = 0;

  virtual Edge *InsertE(Vertex *V1, Vertex *V2) = 0;

  virtual Vertex *InsertV(Vertex *V) = 0;

  virtual Edge *InsertE(Edge *edge) = 0;

  virtual Edge *GetEdge(Vertex *V1, Vertex *V2) = 0;

  virtual bool DeleteE(Vertex *V1, Vertex *V2) = 0;

  virtual bool DeleteV(Vertex *V) = 0;

  virtual string ToString(vector<Vertex *> vertices) = 0;

protected:
  int edge_number;
  int vertex_number;
  bool directed;
  vector<vector<Edge *>> matrix;
};