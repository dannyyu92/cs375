#include "Program1.h"
using namespace std;

Program1::Program1() {
  inputFileName = "";
  outputFileName = "";
  arrayCounter = 0;
  numOfItems = 0;
  weight = 0;
  max = 0;
  for (int i=0; i < 30; i++) {
    weightArray[i] = NULL;
    valueArray[i] = NULL;
  }
}

Program1::Program1(string inputFile, string outputFile) {
  inputFileName = inputFile;
  outputFileName = outputFile;
}

Program1::~Program1() {
}

void Program1::resetArrayCounter() {
  arrayCounter = 0;
}

void Program1::generateNextSubset(bool newArray[]){
  resetArrayCounter();
  while (newArray[arrayCounter] == true) {
    newArray[arrayCounter] = false;
    arrayCounter += 1;
  }
  newArray[arrayCounter] = true;
  resetArrayCounter();

}

void Program1::computeMaxProfit(int numSubsets) {

 int currentMax = 0;
 int currentWeight = 0;

 bool currentSet[numOfItems];
 for (int i=0; i < numOfItems; i++) {
   currentSet[i] = false;
 }

 //cout << "Weight: " << weight<< endl;
 //cout << "numOfItems:" <<numOfItems<<endl;

 for (int j=0; j < numOfItems; j++) {
     if (currentSet[j] == true) {
       currentWeight += weightArray[j];
       currentMax += valueArray[j];
     }
 }



int k = 0;
while (k < numSubsets) {
 for (int j=0; j < numOfItems; j++) {
     if (currentSet[j] == true) {
       currentWeight += weightArray[j];
       currentMax += valueArray[j];
     }
 }


  if (currentWeight <= weight) {
    if (currentMax > max) {
      max = currentMax;
    }
  }
  generateNextSubset(currentSet);
  k += 1;
  currentWeight = 0;
  currentMax = 0;
}


}





void Program1::parseInput() {
  ifstream input(inputFileName.c_str());
  if (input.is_open()) {
	    
    ofstream fout(outputFileName.c_str());


/*
        int k = 1;
	input >> numOfItems;
	    input >> weight;
//            cout << "Problem #" << k << endl;

	    for (int i=0; i < numOfItems; i++) {
	      input >> weightArray[i];
	      input >> valueArray[i];
	    }

            computeMaxProfit();
            k +=1;
*/	
        clock_t init, final;
	int k=1;
        int numSubsets = 1048576;
	while(input >> numOfItems) {
	    input >> weight;
//            cout << "Problem #" << k << endl;

	    for (int i=0; i < numOfItems; i++) {
	      input >> weightArray[i];
	      input >> valueArray[i];
	    }

            init = clock();
            computeMaxProfit(numSubsets);
            final = clock() - init;
            fout << numOfItems <<" " << max << " " << (double)final/((double)CLOCKS_PER_SEC) << endl;
            cout << numOfItems <<" " << max << " " << (double)final/((double)CLOCKS_PER_SEC) << endl;
            max = 0;
            k +=1;
            numSubsets *=2;


	}

	input.close();
	fout.close();
  }
  else {
	cout<< "Input file was not found." << endl;
  }
}




