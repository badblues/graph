#pragma once

#include "Edge.h"
#include "Node.h"



template<typename E, Typename N>
class Graph {
    public:
        Graph();
        Graph(int V, bool isDirected, bool isDense);
        Graph(int V, int E, bool isDirected, bool isDense, );
        Graph(const Graph &copy);
        ~Graph();
        V();
        E();
        Directed();
        Dense();
        K();
        ToListGraph();
        ToMatrixGraph();
        InsertV();
        DeleteV(Node<N> V);
        InsertE(Node<N> V1, Node<N> V1);
        DeleteE(Node<N> V2, Node<N> V2); 
        GetEdge(Node<N> V3, Node<N> V3);

    private:
        bool isDirected;
        bool isDense;
        Node<N>** matrix;
        Node<N>* list;
}

