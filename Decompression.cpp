#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;
 
string decoding(vector<int>&op)
{
    string output = "";
    unordered_map<int, string> table;
    for (int i = 0; i <= 255; i++) {
        string ch = "";
        ch += char(i);
        table[i] = ch;
    }
    int old = op[0], n;
    string s = table[old];
    string c = "";
    c += s[0];
    output += s;
    int count = 256;
    for (int i = 0; i < op.size() - 1; i++) {
        n = op[i + 1];
        if (table.find(n) == table.end()) {
            s = table[old];
            s = s + c;
        }
        else {
            s = table[n];
        }
        output += s;
        c = "";
        c += s[0];
        table[count] = table[old] + c;
        count++;
        old = n;
    }
    return output;
}

vector<int> readFile(string path = "D:/ASU/Senior1/DSA/Project/Data_Structure_Project/XMLFile.xml")
{
	string line;
	string text = "";
	ifstream inputFile(path);
    vector<int>codes;
	while (getline(inputFile, line))
        text = text + line;
    string buffer = "";
	for (size_t i = 0; i < text.size(); i++)
    {
        if(text[i] != ' ')
            buffer += text[i];
        else
        {
            codes.push_back(stoi(buffer));
            buffer = "";
        }
    }
	return codes;
}

void writeFile(string decodedStr)
{
	fstream outputFile;
	outputFile.open("Sample.txt", ios::out);
    for (int i = 0; i < decodedStr.size(); i++) 
        outputFile << decodedStr[i];
    outputFile.close();
}

// int main()
// {
//     vector<int>codes = readFile();
//     string decodedStr = decoding(codes);
//     writeFile(decodedStr);
// }