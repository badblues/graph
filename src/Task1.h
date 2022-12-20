#include "Edge.h"
#include "Graph.h"
#include "Vertex.h"
#include <vector>

using namespace std;

template <class Vertex, class Edge> class Task1 {
public:
  Task1(Graph<Vertex, Edge> *graph_) {
    graph = graph_;
    Solve();
  }

  ~Task1() {}

  void Set(Graph<Vertex, Edge> *graph_) {
    graph = graph_;
    Solve();
  }

  void Restart() { Solve(); }

  Graph<Vertex, Edge> *Result() { return graph; }

private:
  void Solve() {
    int v = graph->V();
    vector<Vertex *> vertices = graph->GetVertices();
    Vertex *V1, *V2;
    for (int i = 0; i < v; i++) {
      int id1 = i, id2 = (i + 1) % v;
      for (int j = 0; j < vertices.size(); j++) {
        if (vertices[j]->GetIndex() == id1)
          V1 = vertices[j];
        if (vertices[j]->GetIndex() == id2)
          V2 = vertices[j];
      }
      Edge *E = graph->InsertE(V1, V2);
      if (E) {
        // FIXME: WON'T WORK WITH ALL TYPES :(
        E->SetW(0);
        E->SetData(0);
      }
    }
  }

  Graph<Vertex, Edge> *graph;
};