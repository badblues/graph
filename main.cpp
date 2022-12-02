#include "src/Graph.h"
#include "src/Vertex.h"
#include "src/Edge.h"
#include <iostream>
#include <vector>

int main() {
    vector<Vertex<int, int>*> vertices;
    Graph<Vertex<int, int>, Edge<Vertex<int, int>, int, int>> graph(0, false, false);
    cout << graph.V() << "\n";
    cout << graph.K() << "\n";
    cout << graph.Directed() << "\n";
    cout << graph.Dense() << "\n";
    vertices.push_back(graph.InsertV());
    vertices.push_back(graph.InsertV());
    graph.InsertE(vertices[0], vertices[1]);
    graph.InsertE(vertices[1], vertices[0]);
    return 0;
}
