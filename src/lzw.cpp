#include "../include/lzw.hpp"

#include <cmath>

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

void LZW_Encoder::init_symbol_table()
{
  table = new Symbol_Table;
  table->table = new Table_Value*;

  for (int i=0; i < 256; i++)
  {
    string s(1, ((char) i));
    table->table[i] =  new Table_Value;

    if (table->table[i])
    {
      table->table[i]->index = i;
      table->table[i]->symbol = s;
      table->size++;
    }
  }
  printf("Table size %d\n", table->size);
}

void LZW_Encoder::dump_table()
{
  for (uint32_t i = 0; i < table->size; i++)
    printf("%d | %s\n", table->table[i]->index, table->table[i]->symbol.c_str());
}

void LZW_Encoder::output(ofstream& output_file, int i, int num_bits)
{

}

int LZW_Encoder::table_get_index(string s)
{

  Table_Value *v;
  int ix = 0;
  while( (v = table->table[ix]) )
  {
    printf("%s\n", v->symbol.c_str());
  }

  return 0;
}

int LZW_Encoder::table_insert(string s)
{
  return 0;
}

int LZW_Encoder::compress(char* input_file_name, char* output_file_name)
{
  assert(input_file_name && output_file_name);

  ifstream input_file;
  ofstream output_file;

  input_file.open(input_file_name, std::ios_base::in);
  if (!input_file.is_open())
  {
    cerr << "Failed to open " << input_file_name << endl;
    return 0;
  }

  output_file.open(output_file_name, std::ios_base::out);
  if (!output_file.is_open())
  {
    cerr << "Failed to open " << input_file_name << endl;
    return 0;
  }

  string working_str = "";
  while( input_file )
  {
    char c = input_file.get();
    string augmented_str = working_str + c;

    int ix = table_get_index(augmented_str);
    if (ix)
    {
      working_str = augmented_str;
    }

    else if (table->size >= MAX_TABLE_ENTRIES)
    {
      output(output_file, ix, num_bits);
      working_str.clear();
      working_str = c;
    }
    else 
    {
      // Insert str into table
      ix = table_insert(working_str);
      output(output_file, ix, num_bits);
      working_str.clear();
      
      if (table->size > pow(2,num_bits))
        num_bits++;
    }
  }

  output_file.close();
  input_file.close();

  return 1;
}
int LZW_Encoder::decompress()
{
  return 0;
}