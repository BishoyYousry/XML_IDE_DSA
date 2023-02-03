#ifndef DECOMPRESSION_H
#define DECOMPRESSION_H

#include <vector>
#include <string>
#include <bitset>
#include <fstream>
#include <sstream>
#include <algorithm>

#define ASCII_26	"00011010"

using namespace std;

template<typename T1, typename T2>
int get_vector_index(vector<pair<T1, T2>>& codes, T1 t);

vector<pair<string, char>> extract_char_codes(string& symboledStr, vector<int>& charSUBIndeces);

string symbols_to_binary_str(string& symboledStr, vector<int>charSUBIndeces);

string binary_to_text(vector<pair<string, char>>codes, string binaryText);

string decompress(string symboledStr);

string modify_file(string str);

int detect_type(string s);

#endif
