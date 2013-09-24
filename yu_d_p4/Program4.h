#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <time.h>
#include <cstdlib>
#include <sys/time.h>

class Program4 {
   public:
      Program4();
      Program4(std::string inputFile, std::string outputFile);
      ~Program4();
      void parseInput();
      void maxProfit();
      void maxProfitLarge();
   private:
      int max;
      int numOfItems;
      int weight;
      int* valueArray;
      int* weightArray;
      int** P;
      int** twoRowP;
      std::string inputFileName;
      std::string outputFileName;
};
