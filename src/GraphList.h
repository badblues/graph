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

        int V() {
            return vertex_number;
        }

        int E() {
            return edge_number;
        }

        Vertex* InsertV() {
            return nullptr;
        }

        Edge* InsertE(Vertex* V1, Vertex* V2) {
            return nullptr;
        }

        Edge* GetEdge(Vertex* V1, Vertex* V2) {
            return nullptr;
        }

        bool DeleteE(Vertex* V1, Vertex* V2) {
            return false;
        }

        bool DeleteV(Vertex* V) {
            return false;
        }

        // void Clear();

        string StructureToString() {
            stringstream *sstr = new stringstream;
            *sstr << "list";
            return sstr->str();
        }
};