#include "src/Edge.h"
#include "src/Graph.h"
#include "src/Iterator.h"
#include "src/Vertex.h"
#include <iostream>
#include <vector>

// TODO: menu
// TODO: iterators menu
// TODO: task1, task2;

int main() {
  vector<Vertex<int, int> *> vertices;
  Graph<Vertex<int, int>, Edge<Vertex<int, int>, int, int>> graph1(0, 0, false,
                                                                   false);
  cout << graph1.ToString();
  cout << "QWERTYUIOP\n";
  vertices.push_back(graph1.InsertV());
  cout << graph1.ToString();
  vertices.push_back(graph1.InsertV());
  cout << graph1.ToString();
  vertices.push_back(graph1.InsertV());
  cout << graph1.ToString();
  Edge<Vertex<int, int>, int, int> *edge =
      graph1.InsertE(vertices[0], vertices[1]);
  edge->SetW(1);
  edge->SetData(10);
  cout << graph1.ToString();
  graph1.ToListGraph();
  edge = graph1.InsertE(vertices[1], vertices[1]);
  edge->SetW(2);
  edge->SetData(20);
  cout << graph1.ToString();
  graph1.ToMatrixGraph();
  cout << graph1.ToString();
  cout << "VERTEX ITERATOR:\n";
  VIterator<Vertex<int, int>, Edge<Vertex<int, int>, int, int>> iter =
      graph1.VBegin();
  cout << (*iter)->GetIndex() << "\n";
  ++iter;
  cout << (*iter)->GetIndex() << "\n";
  ++iter;
  cout << (*iter)->GetIndex() << "\n";
  cout << "EDGE ITERATOR:\n";
  EIterator<Vertex<int, int>, Edge<Vertex<int, int>, int, int>> iter2 =
      graph1.EBegin();
  cout << (*iter2)->V1()->GetIndex() << "\n";
  ++iter2;
  cout << (*iter2)->V1()->GetIndex() << "\n";
  cout << "VERTEX EDGES ITERATOR:\n";
  VEIterator<Vertex<int, int>, Edge<Vertex<int, int>, int, int>> iter3(
      vertices[1]);
  iter3 = graph1.VEBegin(vertices[1]);
  cout << (*iter3)->V1()->GetIndex() << " " << (*iter3)->V2()->GetIndex()
       << "\n";
  ++iter3;
  cout << (*iter3)->V1()->GetIndex() << " " << (*iter3)->V2()->GetIndex()
       << "\n";
  return 0;
}
