#pragma once

#include <vector>
#include <iostream>
using namespace std;

//adjacency list
template<class Vertex, class Edge>
class GraphList {
    private:
        int edge_number;
        int vertex_number;
        bool directed;
    public:
    
        GraphList(bool directed) {
            this->directed = directed;
            edge_number = 0;
            vertex_number = 0;
            cout << "GraphList()\n";
        }

        Vertex* InsertV() {
            return new Vertex(1, 1);
        }

        Edge* InsertE(Vertex* V1, Vertex* V2) {
            return nullptr;
        }

        // bool DeleteV(Vertex V);
        // bool DeleteE(Vertex V1, Vertex V2); 
        // Edge* GetEdge(Vertex V1, Vertex V2);
        // void Clear();
};