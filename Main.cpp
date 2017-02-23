#include <iostream>
#include <fstream>
#include "Board.h"

using namespace std;

int main() {

  cout << "Enter puzzle file name: "; // input the filename                                           
  string filename;
  cin >> filename;
  fstream ifs(filename);
  if (!ifs) {
    cout << "The file does not exist." << endl;
    return 0;
  }

  for (int i=0; i < 9; i++) {
    for (int j=0; j < 9; j++) {
      ifs >> input;
      grid1.elements[i][j].setValue(int) = int(input)-  48;
      if (grid1.elements[i][j].setValue() != 0) {
        for ( int g = 0; g< 9; g++) {
          grid1.elements[i][j].possiVal[g] = 0;
        }
      }
      grid1.elements[i][j].row = i;
      grid1.elements[i][j].column = j;
    }
  }
  ifs.close();

  do {
    grid1equal(grid1, grid2);
    while (!grid1.complete() ) {
      for (i=0;i < 9; i++) {
        for(j=0; j < 9; j++) {




	}

      }
    }

  }

}
