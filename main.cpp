#include "GenStack.h"
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char** argv){
  ifstream sourceFile;
  GenStack <char> delimiterStack;
  GenStack <int> lineStack;

  sourceFile.open(argv[1]);
  while(sourceFile.is_open()){

  }

  return 0;
}
