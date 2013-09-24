#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <time.h>

class Program1 {
   public:
      Program1();
      Program1(std::string inputFile, std::string outputFile);
      ~Program1();
      void parseInput();
      void computeMaxProfit(int numSubsets);	
      void nextMask();
      void generateNextSubset(bool newArray[]);
      void resetArrayCounter();
   private:
      int arrayCounter;
      int max;
      int numOfItems;
      int weight;
      int valueArray[30];
      int weightArray[30];
      std::string inputFileName;
      std::string outputFileName;
};
