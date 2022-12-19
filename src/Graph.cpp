#include "Graph.h"

template <class Vertex, class Edge> Graph<Vertex, Edge>::Graph() {
  directed = false;
  dense = true;
  if (dense)
    graph = new GraphList<Vertex, Edge>(directed);
  else
    graph = new GraphMatrix<Vertex, Edge>(directed);
  cout << "Graph()\n";
}

template <class Vertex, class Edge>
Graph<Vertex, Edge>::Graph(int V, bool directed, bool dense) {
  this->directed = directed;
  this->dense = dense;
  if (dense)
    graph = new GraphList<Vertex, Edge>(directed);
  else
    graph = new GraphMatrix<Vertex, Edge>(directed);
  for (int i = 0; i < V; i++)
    graph->InsertV();
  cout << "Graph(), dense = " << dense << "\n";
}

template <class Vertex, class Edge> Graph<Vertex, Edge>::~Graph() {
  vertices.clear();
  delete graph;
}

template <class Vertex, class Edge>
Graph<Vertex, Edge>::Graph(int V, int E, bool directed, bool dense) {
  this->directed = directed;
  this->dense = dense;
  if (dense)
    graph = new GraphList<Vertex, Edge>(directed);
  else
    graph = new GraphMatrix<Vertex, Edge>(directed);
  if (directed) {
    int max_edges = (V * (V - 1) + V);
    if (E > max_edges)
      E = max_edges;
  } else {
    int max_edges = (V * (V - 1) / 2 + V);
    if (E > max_edges)
      E = max_edges;
  }
  vector<Vertex *> vertices;
  for (int i = 0; i < V; i++) {
    Vertex *vertex = graph->InsertV();
    vertices.push_back(vertex);
  }
  srand(time(NULL));
  for (int i = 0; i < E;) {
    int id1 = rand() % V;
    int id2 = rand() % V;
    Edge *edge;
    graph->InsertE(vertices[id1], vertices[id2]);
    if (edge != nullptr)
      i++;
  }
  cout << "Graph(), dense = " << dense << "\n";
}

template <class Vertex, class Edge> int Graph<Vertex, Edge>::V() {
  return graph->V();
}

template <class Vertex, class Edge> int Graph<Vertex, Edge>::E() {
  return graph->E();
}

template <class Vertex, class Edge> double Graph<Vertex, Edge>::K() {
  double E = graph->E();
  double V = graph->V();
  return directed ? (E / (V * (V - 1))) : (2 * E / (V * (V - 1)));
}

template <class Vertex, class Edge> bool Graph<Vertex, Edge>::Directed() {
  return directed;
}

template <class Vertex, class Edge> bool Graph<Vertex, Edge>::Dense() {
  return dense;
}
template <class Vertex, class Edge> void Graph<Vertex, Edge>::ToListGraph() {
  if (dense)
    return;
  dense = true;
  delete graph;
  graph = new GraphList<Vertex, Edge>(directed);
  for (int i = 0; i < vertices.size(); i++)
    graph->InsertV(vertices[i]);
  for (int i = 0; i < edges.size(); i++)
    graph->InsertE(edges[i]);
}

template <class Vertex, class Edge> void Graph<Vertex, Edge>::ToMatrixGraph() {
  if (!dense)
    return;
  dense = false;
  delete graph;
  graph = new GraphMatrix<Vertex, Edge>(directed);
  for (int i = 0; i < vertices.size(); i++)
    graph->InsertV(vertices[i]);
  for (int i = 0; i < edges.size(); i++)
    graph->InsertE(edges[i]);
}

template <class Vertex, class Edge> Vertex *Graph<Vertex, Edge>::InsertV() {
  Vertex *vertex = graph->InsertV();
  vertices.push_back(vertex);
  return vertex;
}

template <class Vertex, class Edge>
Edge *Graph<Vertex, Edge>::InsertE(Vertex *V1, Vertex *V2) {
  Edge *edge = graph->InsertE(V1, V2);
  edges.push_back(edge);
  return edge;
}

template <class Vertex, class Edge>
Edge *Graph<Vertex, Edge>::GetEdge(Vertex *V1, Vertex *V2) {
  return graph->GetEdge(V1, V2);
}

template <class Vertex, class Edge>
bool Graph<Vertex, Edge>::DeleteE(Vertex *V1, Vertex *V2) {
  Edge *edge = GetEdge(V1, V2);
  for (int i = 0; i < edges.size(); i++)
    if (edges[i] == edge)
      edges.erase(edges.begin() + i);
  return graph->DeleteE(V1, V2);
}

template <class Vertex, class Edge>
bool Graph<Vertex, Edge>::DeleteV(Vertex *V) {
  for (int i = 0; i < vertices.size(); i++)
    if (vertices[i] == V)
      vertices.erase(vertices.begin() + i);
  for (int i = 0; i < vertices.size(); i++)
    vertices[i]->SetIndex(i);
  return graph->DeleteV(V);
}

template <class Vertex, class Edge> void Graph<Vertex, Edge>::Clear() {
  graph->Clear();
  vertices.clear();
  edges.clear();
}

template <class Vertex, class Edge> string Graph<Vertex, Edge>::ToString() {
  return graph->ToString(vertices);
}

template <class Vertex, class Edge>
vector<Vertex *> Graph<Vertex, Edge>::GetVertices() {
  return vertices;
}

template <class Vertex, class Edge>
vector<Edge *> Graph<Vertex, Edge>::GetEdges() {
  return edges;
}

template <class Vertex, class Edge>
VIterator<Vertex, Edge> Graph<Vertex, Edge>::VBegin() {
  return VIterator<Vertex, Edge>(this, 0);
}

template <class Vertex, class Edge>
VIterator<Vertex, Edge> Graph<Vertex, Edge>::VEnd() {
  return VIterator<Vertex, Edge>(this, -1);
}

template <class Vertex, class Edge>
EIterator<Vertex, Edge> Graph<Vertex, Edge>::EBegin() {
  return EIterator<Vertex, Edge>(this, 0);
}

template <class Vertex, class Edge>
EIterator<Vertex, Edge> Graph<Vertex, Edge>::EEnd() {
  return EIterator<Vertex, Edge>(this, -1);
}

template <class Vertex, class Edge>
VEIterator<Vertex, Edge> Graph<Vertex, Edge>::VEBegin(Vertex *V) {
  return VEIterator<Vertex, Edge>(this, V, 0);
}

template <class Vertex, class Edge>
VEIterator<Vertex, Edge> Graph<Vertex, Edge>::VEEnd(Vertex *V) {
  return VEIterator<Vertex, Edge>(this, V, -1);
}

template class Graph<Vertex<int, int>, Edge<Vertex<int, int>, int, int>>;