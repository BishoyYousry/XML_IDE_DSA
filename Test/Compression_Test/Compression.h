#ifndef COMPRESSION_H
#define COMPRESSION_H

#include <vector>
#include <queue>
#include <string>
using namespace std;


#define ASCII_26	"00011010"


class Node
{
public:
	int freq;
	char c;
	Node* left;
	Node* right;
	Node(int freq, char c)
	{
		this->freq = freq;
		this->c = c;
		this->left = nullptr;
		this->right = nullptr;
	}
};

enum SortSequence
{
	ASCENDING,
	DESCENDING
};

template<typename T1, typename T2>
int get_vector_index(vector<pair<T1, T2>>& codes, T1 t);

void merge(vector<Node*>& l, vector<Node*>& r, vector<Node*>& v, SortSequence ss);

void mergeSort(vector<Node*>& v, SortSequence ss);

priority_queue<pair<int, char>> get_chars_frq(string s);

Node* make_huffman_tree(priority_queue<pair<int, char>>pq);

void char_to_binary(Node* root, vector<pair<char, string>>& codes, string s);

string encode_str(string s, vector<pair<char, string>>& codes);

string encoded_to_symbol(string encodedStr);

string readFile(string path);

void writeFile(string s);

void print_codes(vector<pair<char, string>>& codes);

string compress(string text);

#endif