#include "menu.h"

#ifdef __linux__
#define clear_console_ "clear"
#else
#define clear_console_ "cls"
#endif

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
          "  0 EXIT\n"
}

void MainMenu() {
  int choice;
  int pos;
  uint list_size;
  bool flag = true;
  bool iterator_flag = false;
  bool cl_flag = true;
  string str;
  int val;
  string key;

  val = GetNumber(2, INT32_MAX, "ENTER COLLISION LIST SIZE:\n");
  CLHashTable<int> cltable(val);
  val = GetNumber(2, INT32_MAX, "ENTER OPEN ADDRESSING TABLE SIZE:\n");
  OAHashTable<int> oatable(val);

  while (flag) {
    cout << oatable.ToString();
    ShowMainMenu();
    choice = GetNumber(0, 12, "");
    switch (choice) {
    case 1: {

      break;
    }
    case 2: {

      break;
    }
    case 3: {

      break;
    }
    case 4: {

      break;
    }
    case 5: {

      break;
    }
    case 6: {

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