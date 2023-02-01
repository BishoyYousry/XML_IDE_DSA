#ifndef COMPRESSION_H
#define COMPRESSION_H

#include <vector>
#include <queue>
#include <utility>
#include <string>
#include <stack>
#include <algorithm>
#include "Tree_Node.h"
using namespace std;

#define ASCII_26	"00011010"

enum SortSequence
{
	ASCENDING,
	DESCENDING
};

template<typename T1, typename T2>
int get_vector_index(vector<pair<T1, T2>>& codes, T1 t);

void merge(vector<Tree_Node*>& l, vector<Tree_Node*>& r, vector<Tree_Node*>& v, SortSequence ss);

void mergeSort(vector<Tree_Node*>& v, SortSequence ss);

priority_queue<pair<int, char>> get_chars_frq(string s);

Tree_Node* make_huffman_tree(priority_queue<pair<int, char>>pq);

void char_to_binary(Tree_Node* root, vector<pair<char, string>>& codes, string s);

string encode_str(string s, vector<pair<char, string>>& codes);

vector<unsigned char> encoded_to_symbol(string encodedStr);

vector<unsigned char> compress(string text);

#endif
