#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <time.h>
#include <cstdlib>
#include <sys/time.h>

class Program3 {
   public:
      typedef struct {
        int profitR;
        int weightR;
        double ratio;
      } Ratios;
      Program3();
      Program3(std::string inputFile, std::string outputFile, std::string num);
      ~Program3();
      void parseInput(std::string numIn);
      void greedy1();
      void greedy2();
      void backTracking(int index, int currProfit, int currWeight);
      bool promising(int index, int currProfit, int currWeight);
      static int compareRatios(const void* a, const void* b);
      static int compareProfits(const void* a, const void* b);
   private:
      int btMax;
      int arrayCounter;
      int max;
      int numOfItems;
      int weight;
      int* valueArray;
      int* weightArray;
      Ratios* bestSet;
      bool* boolSet;
      bool* include;
      std::string algNum;
      std::string inputFileName;
      std::string outputFileName;
};
