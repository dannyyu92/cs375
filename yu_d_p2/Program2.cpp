/*I have done this assignment completely on my own.  I have not copied it, nor have I given my solution to anyone else.  I understand that if I am involved in plagiarism I will have to sign an official form that I have cheated and that this form will be stored in my student’s records. I also understand that I will receive a grade of 0 for all programming and theoretical assignments so that my maximum grade will be 60%.

Danny Yu, dyu6
*/



#include "Program2.h"
using namespace std;

Program2::Program2() {
  inputFileName = "";
  outputFileName = "";
  maxSize = 0;
  heapSize = 0;
}

Program2::Program2(string inputFile, string outputFile) {
  inputFileName = inputFile;
  outputFileName = outputFile;
}

Program2::~Program2() {
}

void Program2::clearOutputFile() {
  ofstream fout(outputFileName.c_str());
  fout.close();
}


int Program2::left(int i) {
  return 2*i;
}

int Program2::right(int i) {
  return 2*i+1;
}

void Program2::buildMinHeap(Node* heapArray, int* locationArray) {
  //heapSize = maxSize;
  //cout << "heapSize = " << heapSize <<endl;
  for (int i=maxSize/2; i > 0; i--) {
    minHeapify(heapArray, i, locationArray);
  }
}



void Program2::minHeapify(Node* heapArray, int i, int* locationArray){
  int l = left(i);
  int r = right(i);
  int smallest;

    
    if (l <= heapSize && heapArray[l].getPriority() < heapArray[i].getPriority()) {
      smallest = l;
    }
    else {
      smallest = i;
    }
    if (r <= heapSize &&  heapArray[r].getPriority() < heapArray[smallest].getPriority()) {
      smallest = r;
    }
  
  if (smallest != i) {
    //cout << "left = " << heapArray[r].getPriority() << endl;
    //cout << "right = " << heapArray[r].getPriority() << endl;
    //cout << "smallest3 = " << smallest << endl;
    Node temp;
    temp.setNode(heapArray[i].getID(),heapArray[i].getPriority());

    //cout << heapArray[i].getID() << " = " << smallest << endl;
    //cout << heapArray[smallest].getID() << " = " << i < endl;

    locationArray[heapArray[i].getID()] = smallest;
    locationArray[heapArray[smallest].getID()] = i;
    
    heapArray[i] = heapArray[smallest];
    heapArray[smallest] = temp;

    minHeapify(heapArray, smallest, locationArray);
  }

}

void Program2::insert(int k, int p, Node* heapArray, int* locationArray) {
  ofstream fout(outputFileName.c_str(), ios::app);
  int i=1;
  while (i<=maxSize) {
    if (heapArray[i].isEmpty()) {
      heapArray[i].setNode(k,p);
      heapSize +=1;
      locationArray[k] = i;
      fout << "inserted " << k << " with priority " << p << endl;
      break;
    }
    else {
      i+=1;
    }
  }
  fout.close();
  buildMinHeap(heapArray, locationArray);
}

void Program2::printHeap(Node* heapArray) {
  //cout << "heapSize: " << heapSize << endl;
  ofstream fout(outputFileName.c_str(), ios::app);
  for (int i=1; i<=heapSize; i++) {
    //cout << "This should print " << i << endl;
    fout << "node " << i << " = " << heapArray[i].getID() << " " << heapArray[i].getPriority() << endl;
  }
  fout.close();
}


void Program2::printLocation(int* locationArray) {
  ofstream fout(outputFileName.c_str(), ios::app);
  for(int i=1; i<=maxSize; i++) {
    fout << "node " << i << " = " << locationArray[i] << endl;
  }
  fout.close();
}



void Program2::find(int k, int* locationArray, Node* heapArray) {
  ofstream fout(outputFileName.c_str(), ios::app);
  if (locationArray[k] != -1) {
    fout << k << " is in the extended heap with priority " << heapArray[locationArray[k]].getPriority() << endl;
  }
  else {
    fout << k << " is not in the extended heap" << endl;
  }
  fout.close();

}
void Program2::deleteMin(Node* heapArray, int* locationArray) {
  ofstream fout(outputFileName.c_str(), ios::app);
  if (heapSize < 1) {
    fout << "delete failed since the extended heap is empty" << endl;
    fout.close();
  }
  else {
    fout << "deleted " << heapArray[1].getID() << " with priority " << heapArray[1].getPriority() << endl;
    locationArray[heapSize] = 1;
    locationArray[1] = -1;
    heapArray[1] = heapArray[heapSize];
    heapArray[heapSize].setNode(-1,-1);
    heapSize -= 1;
    fout.close();
    minHeapify(heapArray, 1, locationArray);
  }
}
void Program2::changePriority(int k, int p, Node* heapArray, int* locationArray) {
  ofstream fout(outputFileName.c_str(), ios::app);
  if (locationArray[k] != -1) {
    heapArray[locationArray[k]].setPriority(p);
    minHeapify(heapArray, 1, locationArray);
    fout << "changed priority of " << k << " to " << p << endl;
  }
  else {
    fout << k << " is not in the extended heap" <<endl;
  }
  fout.close();

}






void Program2::parseInput() {
  ifstream input(inputFileName.c_str());
  if (input.is_open()) {
    int input1, input2;
    string inputString, word;
    stringstream ss;

    heapSize = 0;
    input >> maxSize;
    //cout << "maxSize: " << maxSize << endl;

    Node* heapArray = new Node[maxSize];
    int locationArray[maxSize];
    for (int i=1; i<=maxSize; i++) {
      locationArray[i] = -1;
    }


	while(!input.eof()) {
          getline(input, inputString);
          ss << inputString;
          if(!ss.eof() && inputString !="") {
            ss >> word;
            if (word == "insert") {
              ss >> input1;
              ss >> input2;
              ofstream fout(outputFileName.c_str(), ios::app);
              fout << "insert " << input1 << " " << input2 << endl;
	      fout.close();
              insert(input1, input2, heapArray, locationArray);  

            }  
            else if (word == "find") {
              ss >> input1;
              ofstream fout(outputFileName.c_str(), ios::app);
              fout << "find " << input1 << endl;
	      fout.close();
              find(input1, locationArray, heapArray);

            }  
            else if (word == "deleteMin") {
              ofstream fout(outputFileName.c_str(), ios::app);
              fout << "deleteMin" << endl;
	      fout.close();
              deleteMin(heapArray, locationArray);        

            }  
            else if (word == "printHeap") {
              ofstream fout(outputFileName.c_str(), ios::app);
              fout << "printHeap" << endl;
              printHeap(heapArray);        
	      fout.close();
            }
            else if (word == "changePriority") {
              ofstream fout(outputFileName.c_str(), ios::app);
              ss >> input1;
              ss >> input2;
              fout << "changePriority " << input1 << " " << input2 << endl;
	      fout.close();
  	      changePriority(input1, input2, heapArray, locationArray); 
            }
            else if (word == "printLocation") {
              ofstream fout(outputFileName.c_str(), ios::app);
              fout << "printLocation" << endl;
	      fout.close();
              printLocation(locationArray);

            }
            else {}
          ss.clear();
          }
	}
	input.close();
	
  }
  else {
	cout<< "Input file was not found." << endl;
  }
}




