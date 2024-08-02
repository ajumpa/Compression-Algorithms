#include <iostream>
#include <fstream>
#include <string>


#include "../include/lzw.hpp"


using namespace std;

int main(int argc, char** argv)
{

  if (argc < 2)
  {
    cout << "No input file specified..." << endl;
    exit(0);
  }

  LZW_Encoder encoder(16, 9);
  encoder.compress(argv[1]);

  exit(0);
}