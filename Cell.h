#include <iostream>
#include <array>
using namespace std;

#infedf CELL_H
#define CELL_H

class Cell {  // determines the cell and numbers within the matrix
  
 public:
    Cell(int = 0);  
    ~Cell(); 

    int number(int, int) const; // reads number at grid location and returns 0 for an empty cell
    void setNumber(int, int, int); // set number in grid location
    bool fixed(int, int) const; // number at grid location

    bool isSolved(int, int) const; // Cell at point is solved
    void setSolved(int, int);

    bool set(int, int, int) const; // value from 1 to 9 check
    bool anySet(int int) const; // Any values between 1 and 9
    void newSet(int, int, int); // set new values

  private:
    
    int array<array<grid[9][9]> squares;

};


#endif
