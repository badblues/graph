#include "src/Graph.h"
#include "src/Vertex.h"
#include "src/Edge.h"
#include <iostream>
#include <vector>

//TODO: ToString приятный для глаз
//TODO: ToList, ToMatrix
//TODO: ~Graph()
//TODO: Vertex iterator
//TODO: Edge iterator
//TODO: Vertex outer edges iterator
//TODO: hash_map for names and vertices in main app
//TODO: task1, task2;

int main() {
    vector<Vertex<int, int>*> vertices;
    Graph<Vertex<int, int>, Edge<Vertex<int, int>, int, int>> graph1(0, 0, true, true);
    cout << graph1.ToString();
    vertices.push_back(graph1.InsertV());
    cout << graph1.ToString();
    vertices.push_back(graph1.InsertV());
    cout << graph1.ToString();
    vertices.push_back(graph1.InsertV());
    cout << graph1.ToString();
    graph1.InsertE(vertices[0], vertices[1]);
    cout << graph1.ToString();
    cout << graph1.InsertE(vertices[1], vertices[1]) << "\n";
    cout << graph1.ToString();
    cout << "edge[0,1] = " << graph1.GetEdge(vertices[0], vertices[1]) << "\n";
    cout << "edge[1,1] = " << graph1.GetEdge(vertices[1], vertices[1]) << "\n";
    graph1.DeleteV(vertices[1]);
    cout << graph1.ToString();
    return 0;
}
