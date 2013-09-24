#include "Program1.h"
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
  if (argc == 3) {
    Program1 streamObj(argv[1], argv[2]);
    streamObj.parseInput();
  }
  else {
    cout << "Incorrect # of arguments." << endl;
  }

  return 0;

}
