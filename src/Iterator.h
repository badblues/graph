#pragma once

#include "Edge.h"
#include "Graph.h"
#include "Vertex.h"

using namespace std;

template <class Vertex, class Edge> class Graph;

template <class Vertex, class Edge> class VIterator {
public:
  VIterator() {
    graph = nullptr;
    id = -1;
  }

  VIterator(Graph<Vertex, Edge> *graph_, int id_) {
    graph = graph_;
    if (graph->V() == 0)
      id = -1;
    else
      id = id_;
  }

  VIterator &operator++() {
    if (id == -1)
      return *this;
    id++;
    if (id >= graph->V())
      id = -1;
    return *this;
  }

  Vertex *operator*() { return graph->GetVertices()[id]; }

  void operator=(const VIterator &iter) {
    graph = iter.graph;
    id = iter.id;
  }

  bool operator==(const VIterator &iter) {
    return (id == iter.id);
  }

  bool operator!=(const VIterator &iter) {
    return (id != iter.id);
  }

private:
  Graph<Vertex, Edge> *graph;
  int id;
};

template <class Vertex, class Edge> class EIterator {
public:
  EIterator() {
    graph = nullptr;
    id = -1;
  }

  EIterator(Graph<Vertex, Edge> *graph_, int id_) {
    graph = graph_;
    if (graph->E() == 0)
      id = -1;
    else
      id = id_;
  }

  EIterator &operator++() {
    if (id == -1)
      return *this;
    id++;
    if (id >= graph->E())
      id = -1;
    return *this;
  }

  Edge *operator*() { return graph->GetEdges()[id]; }
  void operator=(const EIterator &iter) {
    graph = iter.graph;
    id = iter.id;
  }

  bool operator==(const EIterator &iter) {
    return (id == iter.id);
  }

  bool operator!=(const EIterator &iter) {
    return (id != iter.id);
  }

private:
  Graph<Vertex, Edge> *graph;
  int id = 0;
};

template <class Vertex, class Edge> class VEIterator {
public:
  VEIterator(Vertex *V_) {
    graph = nullptr;
    V = V_;
    id = -1;
  }

  VEIterator(Graph<Vertex, Edge> *graph_, Vertex *V_, int id_) {
    graph = graph_;
    V = V_;
    if (id_ == -1) {
      id = -1;
      return;
    }
    for (id = 0; id < graph->E(); id++)
      if (graph->GetEdges()[id]->V1() == V ||
          (!graph->Directed() && graph->GetEdges()[id]->V2() == V))
        return;
    id = -1;
  }

  VEIterator &operator++() {
    if (id == -1)
      return *this;
    id++;
    for (; id < graph->E(); id++)
      if (graph->GetEdges()[id]->V1() == V ||
          (!graph->Directed() && graph->GetEdges()[id]->V2() == V))
        return *this;
    id = -1;
    return *this;
  }

  Edge *operator*() { return graph->GetEdges()[id]; }

  void operator=(const VEIterator &iter) {
    graph = iter.graph;
    id = iter.id;
  }

  bool operator==(const VEIterator &iter) {
    return (id == iter.id);
  }

  bool operator!=(const VEIterator &iter) {
    return (id != iter.id);
  }


private:
  Graph<Vertex, Edge> *graph;
  Vertex *V;
  int id = 0;
};