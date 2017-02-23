#include <Board.h>
#include <iostream>
#include 'Board.h'
#include <fstream>
using namespace std;

Board::Board() {
  Cell elements [9][9];
}

Board::~Board() {

}


void Board::printgrid1() {
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      cout << grid[i][j].number << " ";
    }
    cout << endl;
  }
}


