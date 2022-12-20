#include "Edge.h"
#include "Graph.h"
#include "Iterator.h"
#include "Vertex.h"
#include <vector>


using namespace std;

template <class Vertex, class Edge> class Task2 {
public:
  Task2(Graph<Vertex, Edge> *graph_) {
    graph = graph_;
    Solve();
  }

  ~Task2() {}

  void Set(Graph<Vertex, Edge> *graph_) {
    graph = graph_;
    Solve();
  }

  void Restart() { Solve(); }

  vector<Vertex *> Result() { return solution; }

private:
  void Solve() {
    solution.clear();
    int v = graph->V();
    vector<Vertex *> vertices = graph->GetVertices();
    Vertex *V1, *V2;
    int diameter = 0;
    for (int i = 0; i < v; i++) {
      int eccentricity = 0;
      for (int j = 0; j < v; j++) {
        int d = Distance(i, j, vertices);
        eccentricity = (d > eccentricity) ? d : eccentricity;
      }
      if (eccentricity > diameter) {
        diameter = eccentricity;
        solution.clear();
        solution.push_back(vertices[i]);
      } else if (eccentricity == diameter) {
        solution.push_back(vertices[i]);
      }
      cout << "i = " << i << ", e = " << eccentricity << ", d = " << diameter
           << "\n";
    }
  }

  int Distance(int id1, int id2, vector<Vertex *> vertices) {
    // Dijkstra
    int v = graph->V();
    int weight[v];
    bool selected[v];
    for (int i = 0; i < v; i++) {
      weight[i] = INT32_MAX;
      selected[i] = false;
    }
    weight[id1] = 0;
    for (int i = 0; i < v; i++) {
      int min_w = INT32_MAX;
      int min_w_id = -1;
      for (int j = 0; j < v; j++) {
        if (!selected[j] && weight[j] < min_w) {
          min_w = weight[j];
          min_w_id = j;
        }
      }
      if (min_w_id == -1)
        break;
      for (int z = 0; z < v; z++) {
        Edge *E = graph->GetEdge(vertices[min_w_id], vertices[z]);
        if (E) {
          int matrix_w = E->GetW();
          if (weight[min_w_id] + matrix_w < weight[z])
            weight[z] = weight[min_w_id] + matrix_w;
        }
      }
      selected[min_w_id] = true;
    }
    if (weight[id2] == INT32_MAX)
      return -1;
    return weight[id2];
  }

  vector<Vertex *> solution;
  Graph<Vertex, Edge> *graph;
};