#include <iostream>
#include <fstream>
#include <string>


#include "../include/lzw.hpp"


using namespace std;

int main(int argc, char** argv)
{

  if (argc < 3)
  {
    printf("Usage: my_compressor [input] [output]");
    exit(0);
  }


  LZW_Encoder encoder;

  if (argv[1] && argv[2])
    encoder.compress(argv[1], argv[2]);

  exit(0);
}