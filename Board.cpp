#include <iostream>
#include <cmath>
#include <array>
#include <fstream>
#include "Board.h"

using namespace std;

bool Board::checkCol(Cell& c) { // Will check the numbers within the column for the grid
   
  for (int i = 0; i < 9; i++) {
    if ( grid[i][c.column] != c.numPossible[i] ) {
      if ( grid[i][c.column].numPossible[i] == c.numPossible[i] ) {
	return false;
      }
    }
  }
  return true;
}

void Board::checkRow(Cell& c){ // Will check the numbers within the rows for the grid
  
  for (int i = 0; i < 9, i++) {
    if (i!=c.column) {
      if ( grid[c.row][i].numPossible == c.numPossible[i] ) {
	return false;
      }
    }
  }
  return true;
}

void Board::setValue(int v, int i, int k) {
  grid[i][k].value = val;
  
}
 
bool Board::singles() {
  int num, count = 0, val;
  bool current = false;

  for(int i = 0; i < 9; i++) {
    for(int k = 0; k < 9; k++) {
      num = grid[i][k].value;
      if( num == 0) {
	for(int j = 0; j < 9; j++) {
	  if(grid[i][k].possibleVal[j] == 0) {
	    count++;
	  }
	  else {
	    val = j + 1;
	  }
	  if(count == 8) {
	    grid[i][k].value = val;
	    current = true;
	  }
	  count = 0;
	}
      }
    }
    if(current) {
      return true;
    }
    else {
      return false;
    }
  }
}
   
void Board::solve(Cell& c) {
  while (singles() || singleton() ) {
    Board();
  }
  print();
      
}




void updateBoard(int i, int j, int excludedValue){
  Cell& c = cells[i][j];
  if (c.constraints[excludedValue]) {
    return true;
  }
  if (c.value == excludedValue) {
    return false;
  }
  c.constraints.set(excludedValue);
  if (--c.numPossibilities > 1)
    return true;
  for (int v = 1; v <= 9; v++) {
    if (!c.constraints[v]) {
      return set(i, j, v);
    }
  }
  return false;
}

bool singleton() {
  int v, r=0, col=0;
  bool current = false;

  for(int i = 0; i < 9; i++) {
    for(int k = 0; k < 9; k++){
      v = grid[i][k].value;
      if( v = 0) {
	for(int j = 0; j < 9; j++) {
	  if(grid[i][k].possibleVal[j] == 1) {
	    for (int m = 0; m < 9; m++) {

	      if(grid[m][k].possibleVal[j] == 0) {
		r++;
	      }
	      if(grid[i][m].possibleVal[j] == 0) {
		col++;
	      }

	    }
	    if( (r == 8) || (col == 8) ) {
	      grid[i][k].value = j + 1;
	      current = true;
	    }
	    else {
	      r = 0;
	      col = 0;
	
	    }
	  }
	}	
      }
    }
  }
  if(current) {
    return true;
  }
  else {
    return false;
  }
}



void print() { // will print out the matrix                                                                     

  for( int i = 0; i < 9; i++) {
    for(int j = 0; j < 9; j++) {
      cout << grid[i][j].value << " ";
    }
    cout << endl;
  }
}

