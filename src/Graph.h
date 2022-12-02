#pragma once

#include "Edge.h"
#include "Vertex.h"
#include "GraphMatrix.h"
#include "GraphList.h"
#include <vector>
#include <iostream>
using namespace std;

template<class Vertex, class Edge>
class Graph {
    public:
        Graph();
        Graph(int V, bool directed, bool dense);
        Graph(int V, int E, bool directed, bool dense);
        Graph(const Graph &copy);
        //~Graph();
        int V();
        int E();
        bool Directed();
        bool Dense();
        double K();
        // void ToListGraph();
        // void ToMatrixGraph();
        Vertex* InsertV();
        // bool DeleteV(Vertex V);
        // bool DeleteE(Vertex V1, Vertex V2); 
        // Edge* GetEdge(Vertex V1, Vertex V2);
        Edge* InsertE(Vertex* V1, Vertex* V2);
    private:
        bool directed;
        bool dense;
        int vertex_number;
        int edge_number;
        GraphList<Vertex, Edge>* g_list;
        GraphMatrix<Vertex, Edge>* g_matrix;
};
