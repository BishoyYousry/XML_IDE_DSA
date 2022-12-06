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
		if (vect.size() == 1) break;
	}
	return vect[0];
}

void char_to_binary(Node* root, map<char, string>&m, string s)
{
	if (!root) return;
	if (root->c != '~')
	{
		m[root->c] = s;
		return;
	}
	char_to_binary(root->left, m, s + "0");
	char_to_binary(root->right, m, s + "1");
}

void print_codes(map<char, string>&m)
{
	for (auto i : m)
		cout << i.first << " -> " << i.second << endl;
}


void print_encoded_str(string s, map<char, string>&m)
{
	for (size_t i = 0; i < s.size(); i++)
		cout << m[s[i]];
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
	map<char, string>m;
	char_to_binary(root, m, "");
	print_codes(m);
	print_encoded_str(str, m);
}