#pragma once

#include "Edge.h"
#include "Vertex.h"
#include "GraphMatrix.h"
#include "GraphList.h"
#include "Iterator.h"
#include <vector>
#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

template<class Vertex, class Edge>
class Graph {
    public:
        Graph();
        Graph(int V, bool directed, bool dense);
        Graph(int V, int E, bool directed, bool dense);
        Graph(const Graph &copy);
        ~Graph();
        int V();
        int E();
        bool Directed();
        bool Dense();
        double K();
        void ToListGraph();
        void ToMatrixGraph();
        Vertex* InsertV();
        bool DeleteV(Vertex* V);
        bool DeleteE(Vertex* V1, Vertex* V2);
        Edge* GetEdge(Vertex* V1, Vertex* V2);
        Edge* InsertE(Vertex* V1, Vertex* V2);
        void Clear();
        string ToString();
        vector<Vertex*> GetVertices();
        vector<Edge*> GetEdges();
        VIterator<Vertex, Edge> VBegin();
        VIterator<Vertex, Edge> VEnd();
        EIterator<Vertex, Edge> EBegin();
        EIterator<Vertex, Edge> EEnd();
        VEIterator<Vertex, Edge> VEBegin(Vertex* V);
        VEIterator<Vertex, Edge> VEEnd(Vertex* V);
    private:
        bool directed;
        bool dense;
        GraphForm<Vertex, Edge>* graph;
        vector<Vertex*> vertices;
        vector<Edge*> edges;
};
