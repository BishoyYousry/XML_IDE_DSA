#include <vector>
#include <string>
#include <utility>
#include <bitset>
#include <algorithm>
using namespace std;

#define ASCII_26	"00011010"

template<typename T1, typename T2>
int get_vector_index(vector<pair<T1, T2>>& codes, T1 t);

vector<pair<string, char>> extract_char_codes(string& symboledStr, vector<int>& charSUBIndeces, int& lastSymbolBytes);

string symbols_to_binary_str(string symboledStr, vector<int>charSUBIndeces, int lastSymbolBytes);

string binary_to_text(vector<pair<string, char>>codes, string binaryText);

string decompress(string symboledStr);
