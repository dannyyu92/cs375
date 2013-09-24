#include "Program3.h"
using namespace std;

Program3::Program3() {
  algNum = "";
  inputFileName = "";
  outputFileName = "";
  numOfItems = 0;
  weight = 0;
  max = 0;
  btMax = 0;
}

Program3::Program3(string inputFile, string outputFile, string num) {
  inputFileName = inputFile;
  outputFileName = outputFile;
  algNum = num;
}

Program3::~Program3() {
}


int Program3::compareProfits(const void* a, const void* b) {
  const Ratios *profit1 = (Ratios*)a;
  const Ratios *profit2 = (Ratios*)b;

  if (profit1->profitR < profit2->profitR) {
    return 1;
  }
  else if (profit1->profitR > profit2->profitR) {
    return -1;
  }
  else {
    return 0;
  }
}


int Program3::compareRatios(const void* a, const void* b) {
  const Ratios *ratio1 = (Ratios*)a;
  const Ratios *ratio2 = (Ratios*)b;

  if (ratio1->ratio < ratio2->ratio) {
    return 1;
  }
  else if (ratio1->ratio > ratio2->ratio) {
    return -1;
  }
  else {
    return 0;
  }
}

void Program3::greedy1() {
  max = 0;

  for (int i=0; i < numOfItems; i++) {
    boolSet[i] = false;
    include[i] = false;
    bestSet[i].profitR = (double)valueArray[i];
    bestSet[i].weightR = (double)weightArray[i];
    bestSet[i].ratio = (double)valueArray[i]/(double)weightArray[i]; 
  }

  qsort (bestSet, numOfItems, sizeof(Ratios), compareRatios);
  
  int currentWeight = 0;
  for (int i=0; i < numOfItems; i++) {
    currentWeight += bestSet[i].weightR;
    //cout << "currentWeight greedy1: " << currentWeight << endl;
    if (currentWeight <= weight) {
      max += bestSet[i].profitR;
      boolSet[i] = true;
      include[i] = true;
    }
    else {
      currentWeight -= bestSet[i].weightR;
    }
  }
  //cout << "currentWeight: " << currentWeight << endl;


/*
  for (int i=0; i < numOfItems; i++) {
    cout << "bestSet  = " << bestSet[i].ratio << endl;
  
  }
*/
}


void Program3::greedy2() {
  int greedy1MaxProfit, pmax;
  greedy1();
  greedy1MaxProfit = max;
  max = 0;

  qsort (bestSet, numOfItems, sizeof(Ratios), compareProfits);

/*
  for (int i=0; i < numOfItems; i++) {
    cout << "bestSet blah= " << bestSet[i].profitR << endl;
  
  }
*/
  int currentWeight = 0;
  for (int i=0; i < numOfItems; i++) {
    currentWeight += bestSet[i].weightR;
    //cout << "bestSet["<<i<<"].weightR: " << bestSet[i].weightR << endl; 
    //cout << "bestSet["<<i<<"].profitR: " << bestSet[i].profitR << endl;
    //cout << "bestSet["<<i<<"].ratio: " << bestSet[i].ratio << endl;
    if (currentWeight <= weight) {
      max += bestSet[i].profitR;
      
      break;
    }
    
  }
  //cout << "greedy1MaxProfit: " << greedy1MaxProfit <<endl;

  pmax = max;
//cout << "PMAX IS " << pmax << endl;
//cout << "GREEDYMAX IS " << greedy1MaxProfit << endl;

  if (greedy1MaxProfit > pmax) {
    max = greedy1MaxProfit;
  }
  else {
    max = pmax;
  }

  //cout << "MAX IS " << max << endl;
}

bool Program3::promising(int index, int currProfit, int currWeight) {
  int j, k, totalWeight;
  double bound;
  
  if (currWeight >= weight) {
    return false;
  }
  else {
    j = index+1;
    //cout << "j starts at: " << j << endl;
    bound = currProfit;
    //cout << "currProfit = " << currProfit <<endl;
    totalWeight = currWeight;
    //cout << "currWeight = " << currWeight << endl;
    while ((j < numOfItems) && ((totalWeight + bestSet[j].weightR) <= weight)) {
      totalWeight = totalWeight + bestSet[j].weightR;
      bound = bound + bestSet[j].profitR;
      //cout << "totalWeight = " << totalWeight << endl;
      //cout << "bound = " << bound << endl;
      j++;
    }
    //cout << "exited loop!"<<endl;
    //cout << "j = " << j <<endl;
    k = j;
    if (k < numOfItems) {
      bound = bound + ((double)(weight - totalWeight) * bestSet[k].ratio);
      //cout << k << endl;
      //cout << "Ratio: " << bestSet[k].ratio << endl;
    }
    //printf("bound = %f\n", bound);
    //cout << "bound > max is: " << (bound > max) << endl;
    
    return bound > max;
  }

}

void Program3::backTracking(int index, int currProfit, int currWeight) {
 
  
/*
  for (int i=0; i<numOfItems; i++) {
   printf("%f\n", bestSet[i].ratio);
  }
*/
  //cout << "max = " << max <<endl;
  if (currWeight <= weight && currProfit > max) {
    //cout << "INSIDE HERE ADSFKDASJF " << endl;
    //cout << "currWeight inside: " << currWeight << endl;
    //cout << "currProfit inside: " << currProfit << endl;
    max = currProfit;
    
    for (int i=0; i<numOfItems; i++) {
      boolSet[i] = include[i];
    }
  }
  
  //cout << "index, currProfit, currWeight: " << index <<" " <<currProfit <<" " <<currWeight <<endl;
  if (promising(index, currProfit, currWeight)) {
    include[index+1] = true;
    //cout << "currProfit + bestSet[index+1].profitR       " << currProfit + bestSet[index+1].profitR << endl;
    backTracking(index+1, currProfit + bestSet[index+1].profitR, currWeight + bestSet[index+1].weightR);
    //cout <<"" << endl;
    include[index+1] = false;
    backTracking(index+1, currProfit, currWeight);
    //cout <<"" << endl;
  } 

}

void Program3::parseInput(string numIn) {
  
  ifstream input(inputFileName.c_str());
  if (input.is_open()) {
	    
    ofstream fout(outputFileName.c_str());
        max = 0;

        struct timeval start,end;
        

        //clock_t init, final;
	int k=1;
        //int numSubsets = 1048576;
	while(input >> numOfItems) {
            //cout << "numOfItems = " << numOfItems <<endl;
            weightArray = new int[numOfItems];
            valueArray = new int[numOfItems];
  	    bestSet = new Ratios[numOfItems];
  	    boolSet = new bool[numOfItems];
  	    include = new bool[numOfItems];


	    for (int i=0; i < numOfItems; i++) {
	      weightArray[i] = NULL;
	      valueArray[i] = NULL;
	    }

	    input >> weight;
            //cout << "weight = " << weight << endl;
//            cout << "Problem #" << k << endl;

	    for (int i=0; i < numOfItems; i++) {
	      input >> weightArray[i];
	      input >> valueArray[i];
	    }

	/*
	    for (int i=0; i < numOfItems; i++) {
	      cout<< "weightArray["<<i <<"] = " <<weightArray[i]<<endl;
	      cout<< "valueArray["<<i <<"] = " <<valueArray[i]<<endl;
	    }
	*/

            //init = clock();
	    gettimeofday(&start, NULL);
	    if (numIn == "0") {
	      greedy1();
            }
            else if (numIn == "1") {
              greedy2();
            }
            else if (numIn == "2") {
               greedy2(); 
               qsort (bestSet, numOfItems, sizeof(Ratios), compareRatios);
               for (int i=0; i<numOfItems; i++ ) {
                 cout << "bestSet["<<i<<"] = " << bestSet[i].ratio << endl;
               }
               backTracking(-1, 0, 0);
            }
            else {
	      cout << "Incorrect algorithm #" <<endl;
              break;
            }

	    gettimeofday(&end, NULL);
            double total = (double)((double(end.tv_sec - start.tv_sec) * 1000) + ((double)(end.tv_usec - start.tv_usec)/ 1000));
            cout << numOfItems << "  " << max << " " << total << endl;
            fout << numOfItems << "  " << max << " " << total << endl;
            //final = clock() - init;
            //fout << numOfItems <<" " << max << " " << 1000.00*(double)final/((double)CLOCKS_PER_SEC) << endl;
            //cout << numOfItems <<" " << max << " " << 1000.00*(double)final/((double)CLOCKS_PER_SEC) << endl;
            max = 0;
	    delete[] weightArray;
            delete[] valueArray;
            delete[] bestSet;
            delete[] boolSet;
            delete[] include;
            //k +=1;
            //numSubsets *=2;


	}

	input.close();
	fout.close();
  }
  else {
	cout<< "Input file was not found." << endl;
  }
}




