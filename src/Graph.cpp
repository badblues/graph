#include "Graph.h"

template<class Vertex, class Edge>
Graph<Vertex, Edge>::Graph() {
    directed = false;
    dense = true;
    vertex_number = 0;
    edge_number = 0;
    g_list = new GraphList<Vertex, Edge>(directed);
    g_matrix = new GraphMatrix<Vertex, Edge>(directed);
    cout << "Graph()\n";
}

template<class Vertex, class Edge>
Graph<Vertex, Edge>::Graph(int V, bool directed, bool dense) {
    this->directed = directed;
    this->dense = dense;
    vertex_number = V;
    edge_number = 0;
    g_list = new GraphList<Vertex, Edge>(directed);
    g_matrix = new GraphMatrix<Vertex, Edge>(directed);
    cout << "Graph()\n";
}

template<class Vertex, class Edge>
Graph<Vertex, Edge>::Graph(int V, int E, bool directed, bool dense) {
    this->directed = directed;
    this->dense = dense;
    vertex_number = V;
    edge_number = E;
    g_list = new GraphList<Vertex, Edge>(directed);
    g_matrix = new GraphMatrix<Vertex, Edge>(directed);
    cout << "Graph()\n";
}

template<class Vertex, class Edge>
int Graph<Vertex, Edge>::V() {
    return vertex_number;
}

template<class Vertex, class Edge>
int Graph<Vertex, Edge>::E() {
    return edge_number;
}

template<class Vertex, class Edge>
double Graph<Vertex, Edge>::K() {
    double E = (double)edge_number;
    double V = (double)vertex_number;
    return directed ? (E/(V*(V-1))) : (2*E/(V*(V-1)));
}

template<class Vertex, class Edge>
bool Graph<Vertex, Edge>::Directed() {
    return directed;
}

template<class Vertex, class Edge>
bool Graph<Vertex, Edge>::Dense() {
    return dense;
}


template<class Vertex, class Edge>
Vertex* Graph<Vertex, Edge>::InsertV() {
    vertex_number++;
    return dense ? g_list->InsertV() : g_matrix->InsertV();
}

template<class Vertex, class Edge>
Edge* Graph<Vertex, Edge>::InsertE(Vertex* V1, Vertex* V2) {
    edge_number++;
    if (directed)
        dense ? g_list->InsertE(V2, V1) : g_matrix->InsertE(V2, V1);
    return dense ? g_list->InsertE(V1, V2) : g_matrix->InsertE(V1, V2);
}

template
class Graph<Vertex<int, int>, Edge<Vertex<int, int>, int, int>>;