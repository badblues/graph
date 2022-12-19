#include "menu.h"

#ifdef __linux__
#define clear_console_ "clear"
#else
#define clear_console_ "cls"
#endif

#define v_type string, int
#define e_type Vertex<v_type>, int, int
#define g_type Vertex<v_type>, Edge<e_type>
using namespace std;

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
          " 15 TEST ITERATOR\n"
          " 16 CLEAR\n"
          " 17 NEW GRAPH\n"
          " 18 INSERT VERTEXES\n"
          " 19 INSERT VERTEXES\n"
          "  0 EXIT\n"
          "===================\n";
}

void ShowIteratorMenu() {
  cout << "\n===================\n"
          "   MENU:\n"
          "  1 BEGIN\n"
          "  2 ++\n"
          "  3 *\n"
          "  0 EXIT\n";
}

Graph<g_type> *GetGraph() {
  bool directed, dense;
  int val = GetNumber(1, 2, "1 - DIRECTED\n2 - NOT DIRECTED\n");
  directed = (val == 1) ? true : false;
  val = GetNumber(1, 2, "1 - ADJACENCY LIST\n2 - ADJACENCY MATRIX\n");
  dense = (val == 1) ? true : false;
  return new Graph<g_type>(0, directed, dense);
}

bool GetVertex(map<string, Vertex<v_type>*> names, Vertex<v_type>** V) {
  string str;
  cout << "ENTER VERTEX NAME:\n";
  cin >> str;
  auto res = names.find(str);
  if (res == names.end()) {
    cout << "NOT FOUND\n";
    return false;
  }
  *V = res->second;
  return true;
}

bool GetVertexes(map<string, Vertex<v_type>*> names, Vertex<v_type>** V, Vertex<v_type>** V2) {
  string str, str2;
  cout << "ENTER FIRST VERTEX NAME:\n";
  cin >> str;
  cout << "ENTER SECOND VERTEX NAME:\n";
  cin >> str2;
  auto res = names.find(str);
  auto res2 = names.find(str2);
  if (res == names.end() || res2 == names.end()) {
    cout << "NOT FOUND\n";
    return false;
  }
  *V = res->second;
  *V2 = res2->second;
  return true;
}

void MainMenu() {
  int choice;
  bool flag = true;
  bool iterator_flag = false;
  string str;
  int val, val2;
  Vertex<v_type>* V;
  Vertex<v_type>* V2;
  Edge<e_type>* E;
  map<string, Vertex<string, int>*> names;

  Graph<g_type>* graph = GetGraph();

  while (flag) {
    V = nullptr;
    V2 = nullptr;
    E = nullptr;
    cout << graph->ToString();
    ShowMainMenu();
    choice = GetNumber(0, 19, "");
    switch (choice) {
    case 1: {
      cout << "ENTER NAME:\n";
      cin >> str;
      if (names.find(str)!=names.end()) {
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
      if (names.find(str)!=names.end() && names.find(str)->second != V) {
        cout << "NAME ALREADY EXIST\n";
        break;
      }
      val = GetNumber(INT32_MIN, INT32_MAX, "ENTER VALUE(INT):\n");
      V->SetName(str);
      V->SetData(val);
      break;
    }
    case 7: {

      break;
    }
    case 8: {

      break;
    }
    case 9: {
      break;
    }
    case 10: {

      break;
    }
    case 11: {

      break;
    }
    case 12: {

      break;
    }
    case 0:
      flag = false;
      break;
    }
  }
}