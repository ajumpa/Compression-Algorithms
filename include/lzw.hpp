#pragma once


#include <fstream>
#include <iostream>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_MAX_BITS 16
#define DEFAULT_NUM_BITS 9
#define DEFAULT_TABLE_SIZE 512
#define MAX_TABLE_ENTRIES 65536

using namespace std;

struct Table_Value {
  uint32_t index;
  string symbol;
};

struct Symbol_Table {
  struct Table_Value** table;
  uint32_t size;
};

class LZW_Encoder {
  public:
    LZW_Encoder(int max_bits, int num_bits);
    LZW_Encoder();
    int compress(char* file_name, char* output_file_name);
    int decompress();

    void dump_table();

  private:
    int max_bits;
    int num_bits;
    struct Symbol_Table* table;

    void init_symbol_table();
    void output(ofstream& output_file, int i, int num_bits);
    int table_insert(string s);
    int table_get_index(string s);
};