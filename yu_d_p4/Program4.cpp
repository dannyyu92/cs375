#include "Program4.h"
using namespace std;

Program4::Program4() {
  inputFileName = "";
  outputFileName = "";
  numOfItems = 0;
  weight = 0;
  max = 0;
}

Program4::Program4(string inputFile, string outputFile) {
  inputFileName = inputFile;
  outputFileName = outputFile;
}

Program4::~Program4() {
}


void Program4::maxProfit() {
  for (int c=0; c<weight+1; c++) {
    P[0][c] = 0;
  }
  for (int i=1; i<numOfItems+1; i++) {
    P[i][0] = 0;
    for (int c=1; c<weight+1; c++) {
      if (weightArray[i-1] <= c) {
        if ((P[i-1][c-weightArray[i-1]] + valueArray[i-1]) > P[i-1][c]) {
          P[i][c] = P[i-1][c-weightArray[i-1]] + valueArray[i-1];
        }
        else {
          P[i][c] = P[i-1][c];
        }
      }
      else {
        P[i][c] = P[i-1][c];
      }
    }
  }

}

void Program4::maxProfitLarge() {
  for (int c=0; c<weight+1; c++) {
    P[0][c] = 0;
  }
  for (int i=1; i<2; i++) {
    P[i][0] = 0;
  }

  for (int i=1; i<numOfItems+1; i++) {
    for (int c=1; c<weight+1; c++) {
      if (weightArray[i-1] <= c) {
        if ((P[0][c-weightArray[i-1]] + valueArray[i-1]) > P[0][c]) {
          P[1][c] = P[0][c-weightArray[i-1]] + valueArray[i-1];
        }
        else {
          P[1][c] = P[0][c];
        }
      }
      else {
        P[1][c] = P[0][c];
      }
    }

    for (int j=0; j<weight+1; j++) {
      P[0][j] = P[1][j];
      P[1][j] = NULL;
    }

  }

}



void Program4::parseInput() {
  
  ifstream input(inputFileName.c_str());
  if (input.is_open()) {
	    
    ofstream fout(outputFileName.c_str());
        max = 0;

        clock_t init, final;
	int k=1;
	while(input >> numOfItems) {
            //cout << "numOfItems = " << numOfItems <<endl;
            weightArray = new int[numOfItems];
            valueArray = new int[numOfItems];

            // initializes arrays to null
	    for (int i=0; i < numOfItems; i++) {
	      weightArray[i] = NULL;
	      valueArray[i] = NULL;
	    }

            //gets total weight
	    input >> weight;
            //cout << "weight = " << weight << endl;



	    // gets weight and profit of each individual item
	    for (int i=0; i < numOfItems; i++) {
	      input >> weightArray[i];
	      input >> valueArray[i];
	    }

            
	    if (inputFileName == "largeInput.txt") {
              // makes 2 dimensional arrays
              P = new int *[2];
              for (int i=0; i<2; i++) {
                P[i] = new int[weight+1];
              }
              // initializes 2 dimensional array to null
              for (int i=0; i<2; i++) {
                for (int j=0; j<weight+1; j++) {
                  P[i][j] = NULL; 
                }
              }
              init = clock();
              maxProfitLarge();
              final = clock() - init;
              max = P[0][weight];
              for (int i=0; i< 2; i++) {
                delete[] P[i];
              }
              delete[] P;
            }
            else {
              // makes 2 dimensional arrays
              P = new int *[numOfItems+1];
              for (int i=0; i<numOfItems+1; i++) {
                P[i] = new int[weight+1];
              }
              // initializes 2 dimensional array to null
              for (int i=0; i<numOfItems+1; i++) {
                for (int j=0; j<weight+1; j++) {
                  P[i][j] = NULL; 
                }
              }
              init = clock();
              maxProfit();
              final = clock() - init;
              max = P[numOfItems][weight];
              for (int i=0; i< numOfItems+1; i++) {
                delete[] P[i];
              }
              delete[] P;
            }

            fout << numOfItems <<" " << max << " " << (double)final/((double)CLOCKS_PER_SEC) << endl;
            cout << numOfItems <<" " << max << " " << (double)final/((double)CLOCKS_PER_SEC) << endl;
            max = 0;
	    delete[] weightArray;
            delete[] valueArray;
	}
	input.close();
	fout.close();
  }
  else {
	cout<< "Input file was not found." << endl;
  }
}




