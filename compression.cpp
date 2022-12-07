#include<bits/stdc++.h>
using namespace std;
 

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

bool compare(Node* n1, Node* n2)
{
	return n1->freq < n2->freq;
}

vector<pair<int, char>> get_chars_frq(string s)
{
	map<char, int>map;
	for (size_t i = 0; i < s.size(); i++)
		map[s[i]]++;
	vector<pair<int, char>>v;
	for (auto i : map)
		v.push_back({ i.second, i.first });
	sort(v.rbegin(), v.rend());
	return v;
}


Node* make_huffman_tree(vector<pair<int, char>>& v)
{
	vector<Node*>vect;
	for (size_t i = 0; i < v.size(); i++)
		vect.push_back(new Node(v[i].first, v[i].second));
	while (!vect.empty())
	{
		Node* leftNode = vect.back();
		vect.pop_back();
		Node* rightNode = vect.back();
		vect.pop_back();
		Node* parentNode = new Node(leftNode->freq + rightNode->freq, '~');
		parentNode->left = leftNode;
		parentNode->right = rightNode;
		vect.push_back(parentNode);
		sort(vect.rbegin(), vect.rend(), compare);
		if (vect.size() == 1) break;
	}
	return vect[0];
}

void char_to_binary(Node* root, map<char, string>& codes, string s)
{
	if (!root) return;
	if (root->c != '~')
	{
		codes[root->c] = s;
		return;
	}
	char_to_binary(root->left, codes, s + "0");
	char_to_binary(root->right, codes, s + "1");
}

void print_codes(map<char, string>& codes)
{
	for (auto i : codes)
		cout << i.first << " -> " << i.second << endl;
}


string encode_str(string s, map<char, string>& codes)
{
	string encodedStr = "";
	for (size_t i = 0; i < s.size(); i++)
		encodedStr += codes[s[i]];
	return encodedStr;
}

string decode_str(map<char, string>codes, string encodedStr)
{
	map<string, char>reverseCodes;
	for (auto i : codes)
		reverseCodes[i.second] = i.first;
	//Now the key -> string, the value -> char
	string buffer = "";
	string decodedStr = "";
	for (size_t i = 0; i < encodedStr.size(); i++)
	{
		buffer += encodedStr[i];
		if (reverseCodes.find(buffer) != reverseCodes.end())
		{
			decodedStr += reverseCodes[buffer];
			buffer = "";
		}
	}
	return decodedStr;
}

void print_frq(vector<pair<int, char>> v)
{
	for (auto i : v)
		cout << i.second << " -> " << i.first << endl;
}

int main()
{
	string str; cin >> str;
	vector<pair<int, char>>v = get_chars_frq(str);
	print_frq(v);
	Node* root = make_huffman_tree(v);
	map<char, string>codes;
	char_to_binary(root, codes, "");
	print_codes(codes);
	string encodedStr = encode_str(str, codes);
	string decodedStr = decode_str(codes, encodedStr);
	cout << encodedStr << endl;
	cout << decodedStr << endl;
	cout << endl;
}