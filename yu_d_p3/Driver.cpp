#include "Program3.h"
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
  if (argc == 4) {
    Program3 streamObj(argv[1], argv[2], argv[3]);
    streamObj.parseInput(argv[3]);
  }
  else {
    cout << "Incorrect # of arguments." << endl;
  }

  return 0;

}
