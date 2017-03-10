#include <iostream>
#include <vector>
#include <array>

using namespace std;

#ifndef BOARD_H
#define BOARD_H

// using a struct for making the minigrid                                                                     
struct Cell {  // calling the minigrid 3x3 (not the whole matrix)                  
  int value;
  int row;
  int column;
  int numPossible[9]= {1,1,1,1,1,1,1,1,1}; // number of possible values for the cell                 
  int miniGrid() { // determining the minigrid    

    if (row < 3) {
      if (column < 3) {
        return 1;
      }
      else if(column < 6) {
        return 2;
      }
      else {
        return 3;
      }
    }
    else if (row < 6) {
      if (column < 3) {
        return 4;
      }
      else if (column < 6) {
        return 5;
      }
      else {return 6;}
    }

    else {
      if (column < 3) {
	return 7;
      }
     else if (column < 6) {
        return 8;
      }
      else {return 9;}
    }
  }

  int possibleVal() { // gives the possible value for the                                                        
    int sum = 0;
    for(int i = 0; i < 9; i++) {
      if(numPossible[i] == 1) {
        return i + 1;
      }
      return 0;
    }
  }

};

class Board {

 public:
  int grid[9][9];
  
  bool checkCol(Cell& );
  bool checkRow(Cell& );
  void setValue(int, int, int);

  void solve();
  void updateBoard(int, int, int);
  
  bool singleton();
  void print();

 private: 
  
};

#endif
