#include<bits/stdc++.h>
#include"Compression.h"
using namespace std;

string readFile(string path = "XMLFile.xml")
{
	string line;
	string wholeFile = "";
	ifstream inputFile(path);
	while (getline(inputFile, line))
		wholeFile += line + "\n";
	wholeFile = wholeFile.erase(wholeFile.size() - 1, 1);
	return wholeFile;
}

void writeFile(string s)
{
	fstream outputFile;
	outputFile.open("Sample.hm", ios::out);
	outputFile << s;
}


template<typename T1, typename T2>
int get_vector_index(vector<pair<T1, T2>>& codes, T1 t)
{
	auto it = std::find_if(codes.begin(), codes.end(),
		[&](const auto& pair) { return pair.first == t; });
	if (it != codes.end())
		return it - codes.begin();
	return -1;
}

void merge(vector<Node*>& l, vector<Node*>& r, vector<Node*>& v, SortSequence ss)
{
	int i, j, k;
	i = j = k = 0;
	switch (ss)
	{
	case ASCENDING:
		while (i < l.size() && j < r.size())
		{
			if (l[i]->freq <= r[j]->freq)	// Sort Ascending
			{
				v[k++] = l[i];
				i++;
			}
			else
			{
				v[k++] = r[j];
				j++;
			}
		}
		break;
	case DESCENDING:
		while (i < l.size() && j < r.size())
		{
			if (l[i]->freq > r[j]->freq)	// Sort Descending
			{
				v[k++] = l[i];
				i++;
			}
			else
			{
				v[k++] = r[j];
				j++;
			}
		}
	}
	while (i < l.size()) v[k++] = l[i++];
	while (j < r.size()) v[k++] = r[j++];
}

void mergeSort(vector<Node*>& v, SortSequence ss)
{
	int lSize = v.size() / 2;
	int rSize = v.size() - lSize;
	if (v.size() < 2) return;       //Base case
	vector<Node*>lv(lSize);
	vector<Node*>rv(rSize);
	for (size_t i = 0; i < lSize; i++)
		lv[i] = v[i];
	for (size_t i = 0; i < rSize; i++)
		rv[i] = v[lSize + i];
	mergeSort(lv, ss);
	mergeSort(rv, ss);
	merge(lv, rv, v, ss);
}

priority_queue<pair<int, char>> get_chars_frq(string s)
{
	int charsFreq[256] = { 0 };
	for (size_t i = 0; i < s.size(); i++)
		charsFreq[(int)s[i]]++;
	priority_queue<pair<int, char>>pq;
	for (size_t i = 0; i < 256; i++)
	{
		if (charsFreq[i] == 0) continue;
		pq.push({ charsFreq[i], (char)i });
	}
	return pq;
}

Node* make_huffman_tree(priority_queue<pair<int, char>>pq)
{
	vector<Node*>vect;
	while (!pq.empty())
	{
		vect.push_back(new Node(pq.top().first, pq.top().second));
		pq.pop();
	}
	//Now we have vector of nodes which is called vect
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
		mergeSort(vect, DESCENDING);
		if (vect.size() == 1) break;
	}
	return vect[0];
}

void char_to_binary(Node* root, vector<pair<char, string>>& codes, string s)
{
	if (!root) return;
	if (root->c != '~')
	{
		codes.push_back({ root->c, s });
		return;
	}
	char_to_binary(root->left, codes, s + "0");
	char_to_binary(root->right, codes, s + "1");
}

string encode_str(string s, vector<pair<char, string>>& codes)
{
	string encodedStr = "";
	for (size_t i = 0; i < codes.size(); i++)
	{
		/*We will add "(char)1", "(char)2", "(char)3" instead of '0', '1', '\n' respectively
		to differentiate them among the binary
		Ex: "'(char)1'1110'(char)2'10100" -> means that '0' -> 1110 and '1' -> 10100*/
		if (codes[i].first == '0')
			encodedStr = encodedStr + char(1) + codes[i].second;
		else if (codes[i].first == '1')
			encodedStr = encodedStr + char(2) + codes[i].second;
		else if (codes[i].first == '\n')
			encodedStr = encodedStr + char(3) + codes[i].second;
		else
			encodedStr += codes[i].first + codes[i].second;
	}

	/*Make the first line for the data needed for decompression*/
	/*Replace the characters by codes*/
	encodedStr += '\n';
	for (size_t i = 0; i < s.size(); i++)
	{
		int index = get_vector_index<char, string>(codes, s[i]);
		encodedStr += codes[index].second;
	}
	return encodedStr;
}

string encoded_to_symbol(string encodedStr)
{
	string strBuffer = "";
	string symboledStr = "";
	//Search for the first '\n' to start symboling from the second line which is the compressed encoded data
	int startIndex = encodedStr.find('\n');
	//Store the first line only which is the data needed for decompression
	for (size_t i = 0; i <= startIndex; i++)
		symboledStr += encodedStr[i];
	// insert the character (char)4 to separate btn the indeces of SUB char and the codes of chars
	symboledStr.insert(0, 1, (char)4);

	stack<int>charSUBIndeces;	// store the indeces in which SUB char appears
	int countSymbols = 0;
	string noOfBytesLastSymbol;
	for (size_t i = startIndex + 1; i < encodedStr.size(); i++)
	{
		strBuffer += encodedStr[i];
		if (strBuffer.size() == 8 || (strBuffer.size() < 8 && i == encodedStr.size() - 1))
		{
			// char 26 which is SUB that makes a problem when the file is read in decompression
			if (strBuffer == "00011010")
			{
				charSUBIndeces.push(countSymbols);
			}
			/*We must store no. of bytes of The last group of bytes*/
			else if (/*strBuffer.size() < 8 && */i == encodedStr.size() - 1)
			{
				/*Last symbol must not be writen in 8 bits
				so we will store the no. of bytes of this symbol in the 1st line*/
				noOfBytesLastSymbol = to_string(strBuffer.size()) + " ";
				symboledStr += (char)stoi(strBuffer, 0, 2);	// Store the symbol
				countSymbols++;
			}

			else
			{
				symboledStr += (char)stoi(strBuffer, 0, 2);
				countSymbols++;
			}
			strBuffer = "";
		}
	}

	// insert the indeces of SUB char at the beginig of the file but after the last symbol bytes
	while (!charSUBIndeces.empty())
	{
		symboledStr.insert(0, to_string(charSUBIndeces.top()));
		charSUBIndeces.pop();
		if (!charSUBIndeces.empty())
			symboledStr.insert(0, 1, ' ');
	}
	symboledStr.insert(0, noOfBytesLastSymbol);
	return symboledStr;
}

void print_codes(vector<pair<char, string>>& codes)
{
	for (auto i : codes)
		cout << i.first << " -> " << i.second << endl;
}

string compress(string text)
{
	priority_queue<pair<int, char>>pq = get_chars_frq(text);
	Node* root = make_huffman_tree(pq);
	vector<pair<char, string>>codes;
	char_to_binary(root, codes, "");
	string encodedStr = encode_str(text, codes);
	//writeFile(encodedStr);
	string symboledStr = encoded_to_symbol(encodedStr);
	return symboledStr;
}

int main()
{
	string text = readFile();
	string symbols = compress(text);
	writeFile(symbols);
}