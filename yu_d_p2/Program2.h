#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include "Node.h"

class Program2 {
   public:
      Program2();
      Program2(std::string inputFile, std::string outputFile);
      ~Program2();
      void parseInput();
      void find(int k, int* locationArray, Node* heapArray);
      void insert(int k, int p, Node* heapArray, int* locationArray);
      void deleteMin(Node* heapArray, int* locationArray);
      void changePriority(int k, int p, Node* heapArray, int* locationArray);
      void printHeap(Node* heapArray);
      void printLocation(int* locationArray);
      void heapSort(Node* heapArray, int* locationArray);
      void buildMinHeap(Node* heapArray, int* locationArray);
      void minHeapify(Node* heapArray, int i, int* locationArray);
      void clearOutputFile();
      int left(int i);
      int right(int i);
   private:
      int maxSize;
      int heapSize;
      std::string inputFileName;
      std::string outputFileName;
};
