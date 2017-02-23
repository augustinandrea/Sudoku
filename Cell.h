#include <iostream>
#include <array>
using namespace std;

#ifndef CELL_H
#define CELL_H

class Cell {  // determines the cell and numbers within the matrix                                    

 public:
  Cell(int = 0);
  ~Cell();

  void print(); // Will print out the matrix puzzle                                                   
  void load(); // Will load in a puzzle                                                               
  int getValue(int);

  bool CheckCol(int, int); // Checks the Column                                                       
  bool CheckRow(int, int); // Checks the row                                                          
  bool CheckCell(int, int);

  bool solve(int, int); // solves the puzzle                                                          

 private:
  int value;
  int row;
  int column;
  int grid[9][9];

};


#endif
