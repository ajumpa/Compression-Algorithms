#include "../include/lzw.hpp"

LZW_Encoder::LZW_Encoder()
{
  this->max_bits = DEFAULT_MAX_BITS;
  this->num_bits = DEFAULT_NUM_BITS;
  init_symbol_table();
}

LZW_Encoder::LZW_Encoder(int max_bits, int num_bits)
{
  assert(max_bits >= 8 && num_bits >= 8);
  this->max_bits = max_bits;
  this->num_bits = num_bits;

  init_symbol_table();
}

int LZW_Encoder::compress(char* file_name)
{
  assert(file_name);

  ifstream input_file;
  input_file.open(file_name, std::ios_base::in);

  if (!input_file.is_open())
  {
    cerr << "Failed to open " << file_name << endl;
    return 0;
  }

  while( input_file )
  {
    char c = input_file.get();
    cout << c << endl;
  }


  input_file.close();

  return 1;
}

int LZW_Encoder::decompress()
{
  return 0;
}

void LZW_Encoder::init_symbol_table()
{
  table = new struct Symbol_Table;

  for (int i=0; i < 256; i++)
  {
    /*
    string s = {'0'+i};

    struct Table_Value table_value =  {i, };
    */
  }
}