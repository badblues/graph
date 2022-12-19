#pragma once
#ifdef __linux__
#define clear_console_ "clear"
#else
#define clear_console_ "cls"
#endif

#include "Edge.h"
#include "Graph.h"
#include "Iterator.h"
#include "Task1.h"
#include "Vertex.h"
#include <iostream>
#include <map>
#include <stdlib.h>
#include <string>
#include <time.h>


typedef unsigned int uint;

#define v_type string, int
#define e_type Vertex<v_type>, int, int
#define g_type Vertex<v_type>, Edge<e_type>

using namespace std;

void VIteratorMenu(Graph<g_type> *graph);
void EIteratorMenu(Graph<g_type> *graph);
void VEIteratorMenu(Graph<g_type> *graph, Vertex<v_type> *V);

int GetNumber(int l_gap, int h_gap, const char *msg) {
  int number;
  cout << msg;
  while (true) {
    cin >> number;
    if ((number >= l_gap) && (number <= h_gap) && (cin.peek() == '\n'))
      break;
    else {
      cout << "INVALID INPUT\n";
      cin.clear();
      while (cin.get() != '\n') {
      }
    }
  }
  cin.get();
  return number;
}

void ShowMainMenu() {
  cout << "\n===================\n"
          "    MENU:\n"
          "  1 ADD VERTEX\n"
          "  2 REMOVE VERTEX\n"
          "  3 ADD EDGE\n"
          "  4 REMOVE EDGE\n"
          "  5 GET VERTEX DATA\n"
          "  6 SET VERTEX DATA\n"
          "  7 GET EDGE DATA\n"
          "  8 SET EDGE DATA\n"
          "  9 VERTEX NUMBER\n"
          " 10 EDGE NUMBER\n"
          " 11 K\n"
          " 12 IS DIRECTED\n"
          " 13 IS DENSE\n"
          " 14 CHANGE FORM\n"
          " 15 TEST VERTEX ITERATOR\n"
          " 16 TEST EDGE ITERATOR\n"
          " 17 TEST VERTEX EDGES ITERATOR\n"
          " 18 CLEAR\n"
          " 19 NEW GRAPH\n"
          " 20 INSERT VERTEXES\n"
          " 21 INSERT EDGES\n"
          " 22 TASK 1\n"
          " 23 TASK 2\n"
          "  0 EXIT\n"
          "===================\n";
}

Graph<g_type> *GetGraph() {
  bool directed, dense;
  int val = GetNumber(1, 2, "1 - DIRECTED\n2 - NOT DIRECTED\n");
  directed = (val == 1) ? true : false;
  val = GetNumber(1, 2, "1 - ADJACENCY LIST\n2 - ADJACENCY MATRIX\n");
  dense = (val == 1) ? true : false;
  return new Graph<g_type>(0, directed, dense);
}

bool GetVertex(map<string, Vertex<v_type> *> names, Vertex<v_type> **V) {
  string str;
  cout << "ENTER VERTEX NAME:\n";
  cin >> str;
  auto res = names.find(str);
  if (res == names.end()) {
    cout << "NOT FOUND\n";
    cin.get();
    cin.get();
    return false;
  }
  *V = res->second;
  return true;
}

bool GetVertexes(map<string, Vertex<v_type> *> names, Vertex<v_type> **V,
                 Vertex<v_type> **V2) {
  string str, str2;
  cout << "ENTER FIRST VERTEX NAME:\n";
  cin >> str;
  cout << "ENTER SECOND VERTEX NAME:\n";
  cin >> str2;
  auto res = names.find(str);
  auto res2 = names.find(str2);
  if (res == names.end() || res2 == names.end()) {
    cout << "NOT FOUND\n";
    cin.get();
    cin.get();
    return false;
  }
  *V = res->second;
  *V2 = res2->second;
  return true;
}

void MainMenu() {
  int choice;
  bool flag = true;
  string str;
  int val, val2;
  Vertex<v_type> *V, *V2;
  Edge<e_type> *E;
  map<string, Vertex<string, int> *> names;

  Graph<g_type> *graph = GetGraph();

  while (flag) {
    system(clear_console_);
    V = nullptr;
    V2 = nullptr;
    E = nullptr;
    srand(time(NULL));
    cout << graph->ToString();
    ShowMainMenu();
    choice = GetNumber(0, 23, "");
    switch (choice) {
    case 1: {
      cout << "ENTER NAME:\n";
      cin >> str;
      if (names.find(str) != names.end()) {
        cout << "NAME ALREADY EXIST\n";
        break;
      }
      val = GetNumber(INT32_MIN, INT32_MAX, "ENTER VALUE(INT):\n");
      V = graph->InsertV();
      V->SetName(str);
      V->SetData(val);
      names.insert({str, V});
      break;
    }
    case 2: {
      cout << "ENTER NAME:\n";
      cin >> str;
      auto res = names.find(str);
      if (res == names.end()) {
        cout << "NOT FOUND\n";
        cin.get();
        cin.get();
        break;
      }
      V = res->second;
      graph->DeleteV(V);
      break;
    }
    case 3: {
      if (!GetVertexes(names, &V, &V2))
        break;
      E = graph->InsertE(V, V2);
      if (!E) {
        cout << "ALREADY EXIST\n";
        break;
      }
      E->SetW(GetNumber(INT32_MIN, INT32_MAX, "ENTER WEIGHT(INT)\n"));
      E->SetData(GetNumber(INT32_MIN, INT32_MAX, "ENTER DATA(INT)\n"));
      break;
    }
    case 4: {
      if (!GetVertexes(names, &V, &V2))
        break;
      graph->DeleteE(V, V2);
      break;
    }
    case 5: {
      if (!GetVertex(names, &V))
        break;
      cout << "Name = " << V->GetName() << ", DATA = " << V->GetData() << "\n";
      cin.get();
      break;
    }
    case 6: {
      if (!GetVertex(names, &V))
        break;
      cout << "ENTER NAME:\n";
      cin >> str;
      if (names.find(str) != names.end() && names.find(str)->second != V) {
        cout << "NAME ALREADY EXIST\n";
        break;
      }
      val = GetNumber(INT32_MIN, INT32_MAX, "ENTER VALUE(INT):\n");
      V->SetName(str);
      V->SetData(val);
      break;
    }
    case 7: {
      if (!GetVertexes(names, &V, &V2))
        break;
      E = graph->GetEdge(V, V2);
      if (!E) {
        cout << "NOT FOUND\n";
        break;
      }
      cout << "WEIGHT = " << E->GetW() << ", DATA = " << E->GetData() << "\n";
      cin.get();
      break;
    }
    case 8: {
      if (!GetVertexes(names, &V, &V2))
        break;
      E = graph->GetEdge(V, V2);
      if (!E) {
        cout << "NOT FOUND\n";
        break;
      }
      E->SetW(GetNumber(INT32_MIN, INT32_MAX, "ENTER WEIGHT(INT)\n"));
      E->SetData(GetNumber(INT32_MIN, INT32_MAX, "ENTER DATA(INT)\n"));
      break;
    }
    case 9: {
      cout << "VERTEX NUMBER = " << graph->V() << "\n";
      cin.get();
      break;
    }
    case 10: {
      cout << "EDGE NUMBER = " << graph->E() << "\n";
      cin.get();
      break;
    }
    case 11: {
      cout << "DENSITY COEFFICIENT = " << graph->K() << "\n";
      cin.get();
      break;
    }
    case 12: {
      if (graph->Directed())
        cout << "GRAPH IS DIRECTED\n";
      else
        cout << "GRAPH ISN'T DIRECTED\n";
      cin.get();
      break;
    }
    case 13: {
      if (graph->Dense())
        cout << "GRAPH MADE OF ADJACENCY LIST\n";
      else
        cout << "GRAPH MADE OF ADJACENCY MATRIX\n";
      cin.get();
      break;
    }
    case 14: {
      if (graph->Dense())
        graph->ToMatrixGraph();
      else
        graph->ToListGraph();
      break;
    }
    case 15: {
      VIteratorMenu(graph);
      break;
    }
    case 16: {
      EIteratorMenu(graph);
      break;
    }
    case 17: {
      if (!GetVertex(names, &V))
        break;
      VEIteratorMenu(graph, V);
      break;
    }
    case 18: {
      graph->Clear();
      break;
    }
    case 19: {
      delete graph;
      graph = GetGraph();
      break;
    }
    case 20: {
      val = GetNumber(0, 20, "HOW MANY(0-20)?\n");
      for (int i = 0; i < val;) {
        str = "";
        str += 'A' + rand() % 26;
        str += 'A' + rand() % 26;
        if (names.find(str) != names.end())
          continue;
        V = graph->InsertV();
        V->SetName(str);
        V->SetData(rand() % 10);
        names.insert({str, V});
        i++;
      }
      break;
    }
    case 21: {
      int V_ = graph->V();
      int max_edges =
          graph->Directed() ? V_ * (V_ - 1) + V_ : V_ * (V_ - 1) / 2 + V_;
      cout << "HOW MANY(0-" << max_edges << ")?\n";
      int E_ = GetNumber(0, max_edges, "");
      for (int i = 0; i < E_;) {
        int id1 = rand() % V_;
        int id2 = rand() % V_;
        for (auto iter : names) {
          if (iter.second->GetIndex() == id1)
            V = iter.second;
          if (iter.second->GetIndex() == id2)
            V2 = iter.second;
        }
        E = graph->InsertE(V, V2);
        if (E) {
          i++;
          E->SetW(rand() % 100);
          E->SetData(rand() % 100);
        }
        E = nullptr;
      }
      break;
    }
    case 22: {
      if (!graph->Directed())
        Task1<g_type> task1(graph);
      else
        cout << "GRAPH MUST NOT BE DIRECTED\n";
      break;
    }
    case 23: {
      break;
    }
    case 0:
      flag = false;
      break;
    }
  }
}

void ShowIteratorMenu() {
  cout << "\n===================\n"
          "   MENU:\n"
          "  1 BEGIN\n"
          "  2 ++\n"
          "  3 *\n"
          "  0 EXIT\n";
  "===================\n";
}

void VIteratorMenu(Graph<g_type> *graph) {
  int choice;
  bool flag = true;
  VIterator<g_type> iter;
  while (flag) {
    system(clear_console_);
    cout << graph->ToString();
    ShowIteratorMenu();
    choice = GetNumber(0, 3, "");
    switch (choice) {
    case 1: {
      iter = graph->VBegin();
      cout << "DONE!\n";
      cin.get();
      break;
    }
    case 2: {
      ++iter;
      break;
    }
    case 3: {
      if (iter == graph->VEnd())
        cout << "LOST ITERATOR";
      else
        cout << "NAME = " << (*iter)->GetName()
             << ", DATA = " << (*iter)->GetData() << "\n";
      cin.get();
      break;
    }
    case 0: {
      flag = 0;
      break;
    }
    }
  }
}

void EIteratorMenu(Graph<g_type> *graph) {
  int choice;
  bool flag = true;
  EIterator<g_type> iter;
  while (flag) {
    system(clear_console_);
    cout << graph->ToString();
    ShowIteratorMenu();
    choice = GetNumber(0, 3, "");
    switch (choice) {
    case 1: {
      iter = graph->EBegin();
      cout << "DONE!\n";
      cin.get();
      break;
    }
    case 2: {
      ++iter;
      break;
    }
    case 3: {
      if (iter == graph->EEnd())
        cout << "LOST ITERATOR";
      else
        cout << "V1 = " << (*iter)->V1()->GetName()
             << ", V2 = " << (*iter)->V2()->GetName() << "\n";
      cin.get();
      break;
    }
    case 0: {
      flag = 0;
      break;
    }
    }
  }
}

void VEIteratorMenu(Graph<g_type> *graph, Vertex<v_type> *V) {
  int choice;
  bool flag = true;
  VEIterator<g_type> iter(V);
  while (flag) {
    system(clear_console_);
    cout << graph->ToString();
    ShowIteratorMenu();
    choice = GetNumber(0, 3, "");
    switch (choice) {
    case 1: {
      iter = graph->VEBegin(V);
      cout << "DONE!\n";
      cin.get();
      break;
    }
    case 2: {
      ++iter;
      break;
    }
    case 3: {
      if (iter == graph->VEEnd(V))
        cout << "LOST ITERATOR";
      else
        cout << "V1 = " << (*iter)->V1()->GetName()
             << ", V2 = " << (*iter)->V2()->GetName() << "\n";
      cin.get();
      break;
    }
    case 0: {
      flag = 0;
      break;
    }
    }
  }
}