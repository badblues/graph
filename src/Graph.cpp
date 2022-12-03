#include "Graph.h"

template<class Vertex, class Edge>
Graph<Vertex, Edge>::Graph() {
    directed = false;
    dense = true;
    g_list = new GraphList<Vertex, Edge>(directed);
    g_matrix = new GraphMatrix<Vertex, Edge>(directed);
    cout << "Graph()\n";
}

template<class Vertex, class Edge>
Graph<Vertex, Edge>::Graph(int V, bool directed, bool dense) {
    this->directed = directed;
    this->dense = dense;
    g_list = new GraphList<Vertex, Edge>(directed);
    g_matrix = new GraphMatrix<Vertex, Edge>(directed);
    for (int i = 0; i < V; i++)
        dense ? g_list->InsertV() : g_matrix->InsertV();
    cout << "Graph()\n";
}

template<class Vertex, class Edge>
Graph<Vertex, Edge>::Graph(int V, int E, bool directed, bool dense) {
    this->directed = directed;
    this->dense = dense;
    g_list = new GraphList<Vertex, Edge>(directed);
    g_matrix = new GraphMatrix<Vertex, Edge>(directed);
    if (directed) {
        int max_edges = (V*(V-1) + V);
        if (E > max_edges) E = max_edges;
    } else {
        int max_edges = (V*(V-1)/2 + V);
        if (E > max_edges) E = max_edges;
    }
    vector<Vertex*> vertices;
    for (int i = 0; i < V; i++) {
        Vertex* vertex = dense ? g_list->InsertV() : g_matrix->InsertV();
        vertices.push_back(vertex);
    }
    srand(time(NULL));
    for (int i = 0; i < E;) {
        int id1 = rand() % V;
        int id2 = rand() % V;
        Edge* edge;
        if (dense) 
            edge = g_list->InsertE(vertices[id1], vertices[id2]);
        else
            edge = g_matrix->InsertE(vertices[id1], vertices[id2]);
        if (edge != nullptr)
            i++;
    }
    cout << "Graph()\n";
}

template<class Vertex, class Edge>
int Graph<Vertex, Edge>::V() {
    return dense ? g_list->V() : g_matrix->V();
}

template<class Vertex, class Edge>
int Graph<Vertex, Edge>::E() {
    return dense ? g_list->E() : g_matrix->E();
}

template<class Vertex, class Edge>
double Graph<Vertex, Edge>::K() {
    double E = dense ? g_list->E() : g_matrix->E();
    double V = dense ? g_list->V() : g_matrix->V();
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
    Vertex* vertex = dense ? g_list->InsertV() : g_matrix->InsertV();
    vertices.push_back(vertex);
    return vertex;
}

template<class Vertex, class Edge>
Edge* Graph<Vertex, Edge>::InsertE(Vertex* V1, Vertex* V2) {
    return dense ? g_list->InsertE(V1, V2) : g_matrix->InsertE(V1, V2);
}

template<class Vertex, class Edge>
Edge* Graph<Vertex, Edge>::GetEdge(Vertex* V1, Vertex* V2) {
    return dense ? g_list->GetEdge(V1, V2) : g_matrix->GetEdge(V1, V2);
}

template<class Vertex, class Edge>
bool Graph<Vertex, Edge>::DeleteE(Vertex* V1, Vertex* V2) {
    return dense ? g_list->DeleteE(V1, V2) : g_matrix->DeleteE(V1, V2);
}

template<class Vertex, class Edge>
bool Graph<Vertex, Edge>::DeleteV(Vertex* V) {
    for (int i = 0; i < vertices.size(); i++)
        if (vertices[i] == V)
            vertices.erace(vertices.begin()+i);
    return dense ? g_list->DeleteV(V) : g_matrix->DeleteV(V);
}

template<class Vertex, class Edge>
string Graph<Vertex, Edge>::StructureToString() {
    return dense ? g_list->StructureToString() : g_matrix->StructureToString();
}

template
class Graph<Vertex<int, int>, Edge<Vertex<int, int>, int, int>>;