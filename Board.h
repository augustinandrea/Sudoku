#include <iostream>
#include <vector>
#include <array>

using namespace std;

#ifndef BOARD_H
#define BOARD_H

Class Board {

 public:
  Board(int = 9);
  ~Board();

  void setSpace(int, int, int);
  int spaceVal(int, int);
  int numSolve();
  void CellPossible(int, int);
  void solve();
  void setReg();
  bool checkDone();

  void checkCol();
  void checkRow();
  void print(); // will display the board                                                             
  void grid1equalsgrid2();
  bool grid1isgrid2();

 private:

  int gridSize;
  Cell grid[9][9];


};

#endif
