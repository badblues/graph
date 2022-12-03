#include "src/Graph.h"
#include "src/Vertex.h"
#include "src/Edge.h"
#include <iostream>
#include <vector>

//TODO: GraphList
//TODO: ToList, ToMatrix
//TODO: ~Graph()
//TODO: Vertex iterator
//TODO: Edge iterator
//TODO: Vertex outer edges iterator
//TODO: hash_map for names and vertices in main app
//TODO: task1, task2;

int main() {
    vector<Vertex<int, int>*> vertices;
    Graph<Vertex<int, int>, Edge<Vertex<int, int>, int, int>> graph1(2, 1, false, false);
    return 0;
}
