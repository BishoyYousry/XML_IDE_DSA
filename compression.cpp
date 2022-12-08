#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

vector<int> encoding(string s1)
{
    unordered_map<string, int> table;
    for (int i = 0; i <= 255; i++) {
        string ch = "";
        ch += char(i);
        table[ch] = i;
    }
 
    string p = "", c = "";
    p += s1[0];
    int code = 256;
    vector<int> output_code;
    for (int i = 0; i < s1.length(); i++) {
        if (i != s1.length() - 1)
            c += s1[i + 1];
        if (table.find(p + c) != table.end()) {
            p = p + c;
        }
        else {
            output_code.push_back(table[p]);
            table[p + c] = code;
            code++;
            p = c;
        }
        c = "";
    }
    output_code.push_back(table[p]);
    return output_code;
}

string readFile(string path = "D:/ASU/Senior1/DSA/Project/Data_Structure_Project/XMLFile.xml")
{
	string line;
	string wholeFile = "";
	ifstream inputFile(path);
	while (getline(inputFile, line))
		wholeFile = wholeFile + line + "\n";
	return wholeFile;
}

void writeFile(vector<int>&encoded)
{
	fstream outputFile;
	outputFile.open("Sample.txt", ios::out);
    for (int i = 0; i < encoded.size(); i++) 
        outputFile << to_string(encoded[i]) << " ";
}

/*
int main()
{
	string text = readFile();
    vector<int> encoded = encoding(text);
    writeFile(encoded);
}
*/