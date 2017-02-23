#include <iostream>
#include <cmath>
#include <fstream>
#include "Board.h"

using namespace std;

Cell::Cell {
}

Cell::~Cell() {}

void Cell::print() { // will print out the grid                                                       
  for(int i=0; i < 9; i++) {
    for(int j=0; j < 9; j++) {
      cout << grid[i][j].value() << " ";
    }
    cout << endl;
  }
}

void Cell::load() { // load in the input matrix for the sudoku puzzle                                 
  for(int i=0; i < 9; i++) {
    for(int j=0; j < 9; j++) {

      if (grid[i][j] == 0) {
	grid[i][j].fixed = false;
	grid[i][j].value() = 0;
      }
      else {
	grid[i][j].fixed = true;
	grid[i][j].value() = grid[i][j];
      }
    }
  }
}

bool Board::CheckCol(int row, int col) { // Will check the numbers within the column for the grid     
  for (int i = 0; i < 9; i++) {

    if (i != row) {
      if ( grid[i][col].getValue() == grid[row][col].getValue() ) {
        return false;
      }
    }
  }
  return true;
}

bool Cell::CheckRow(int row, int col){ // Will check the numbers within the rows for the grid         
  for (int i = 0; i < 9, i++) {
    if (i!=col) {
      if ( grid[row][i].getValue == grid[row][column].getValue() ) {
        return false;
      }
    }
  }
  return true;
}

bool Cell::CheckCell(int row, int col) {
  int VerticalSquare = row/3;
  int HorizontalSquare = col/3;

  for (int i = VerticalSquare * 3; i < (VerticalSquare*3 + 3); i++) {
    for (int j = HorizontalSquare * 3; j < (HorizontalSquare*3 + 3);j++) {
      if ( !(i == row && j == column) ) {
	if( grid[row][column].getValue == grid[i][j].getValue() ) {
	  return false;
	}
      }
    }
    return true;
  }

}

bool Cell::solve(int row, int col) {
  for( int i = 0; i < 9; i++) {
    for( int j = 0; j < 9; j++) {
    if(grid[i][j].checkCell() == 0
       while (grid[row][col].fixed == true) {
	 col++;

	 if(col > 8) { // column                                                                         
	   col = 0;
	   row++;
	 }
	 if(row > 8) {
	   return true;
	 }
       }

       for (int n = 1; n < 10; n++) {
	 int nextr, nextcol;

	 grid[row][col].getValue() = n;

	 if(CheckCol(row,col) && CheckRow(row,col) && CheckCell(row,col) ) {
	   nextr = row;
	   nextcol = col;

	   nextcol++;
	   if(nextcol > 8) {
	     nextcol=0;
	     nextr++;
	   }
	   if(nextcol == 0 && nextr == 9) {
	     return true;
	   }
	   if( solve(nextr, nextcol) ) {
	     return true;
	   }
	 }
       }
       grid[row][col].getValue() = 0;
       return false;

       }
