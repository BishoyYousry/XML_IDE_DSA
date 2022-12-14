#include<bits/stdc++.h>
using namespace std;

template<typename T1, typename T2>
int get_vector_index(vector<pair<T1, T2>>& codes, T1 t)
{
	auto it = std::find_if(codes.begin(), codes.end(),
		[&](const auto& pair) { return pair.first == t; });
	if (it != codes.end())
		return it - codes.begin();
	return -1;
}

string readFile(string path = "Sample.hm")
{
	string line;
	string wholeFile = "";
	ifstream inputFile(path);
	while (getline(inputFile, line))
		wholeFile += line + "\n";
	return wholeFile;
}

void writeFile(string s)
{
	fstream outputFile;
	outputFile.open("XMLFile(1).xml", ios::out);
	outputFile << s;
}

vector<pair<string, char>> extract_char_codes(string& symboledStr, vector<int>&charSUBIndeces)
{
	/*Store the indeces of SUB char in the vector -> charSUBIndeces*/
	int i = 0;
	string buffer = "";
	char currentChar = symboledStr[0], previous = currentChar;
	while (previous != (char)4)
	{
		if (currentChar != ' ' && currentChar != (char)4) buffer += currentChar;
		else
		{
			charSUBIndeces.push_back(stoi(buffer));
			buffer = "";
		}
		previous = currentChar;
		currentChar = symboledStr[++i];
	}
	
	/*Erase the indeces of SUB char*/
	while(symboledStr[0] != (char)4)
		symboledStr.erase(0, 1);
	symboledStr.erase(0, 1);

	/*Get characters codes*/
	vector<pair<string, char>>codes;
	int startIndex = symboledStr.find('\n');
	i = 0;
	while (i != startIndex)
	{
		currentChar = symboledStr[i];
		i++;
		while (symboledStr[i] == '0' || symboledStr[i] == '1')
		{
			buffer += symboledStr[i];
			i++;
		}
		/*Substitute for (char)1, (char)2, (char)3 by '0', '1', '\n' as the original values*/
		if (currentChar == (char)1)
			codes.push_back({ buffer, '0' });
		else if (currentChar == (char)2)
			codes.push_back({ buffer, '1' });
		else if (currentChar == (char)3)
			codes.push_back({ buffer, '\n' });
		else
			codes.push_back({ buffer, currentChar });
		buffer = "";
	}
	return codes;
}

string symbols_to_binary_str(string& symboledStr, vector<int>charSUBIndeces)
{
	string binaryText = "";
	int startIndex = symboledStr.find('\n');
	int SUBIndex = 0;
	/*Convert symbols to binary ASCII*/
	for (size_t i = startIndex + 1; i < symboledStr.size(); i++)
	{
		/*If the current index is found in the vector charSUBIndeces then insert "00011010" -> SUB char*/
		if (!charSUBIndeces.empty() && charSUBIndeces[SUBIndex] == i)
		{
			binaryText.insert(i, "00011010");
			i += 8;
			SUBIndex++;
		}
		bitset<8>x((int)symboledStr[i]);
		binaryText += x.to_string();
	}
	return binaryText;
}

string binary_to_text(vector<pair<string, char>>codes, string binaryText)
{
	/*Convert binary ASCII to the original chars*/
	string text = "", buffer = "";
	for (size_t i = 0; i < binaryText.size(); i++)
	{
		buffer += binaryText[i];
		int index = get_vector_index<string, char>(codes, buffer);
		if (index != -1)
		{
			text += codes[index].second;
			buffer = "";
		}
	}
	return text;
}


string decompress(string&symboledStr)
{
	vector<int>charSUBIndeces;
	vector<pair<string, char>>codes = extract_char_codes(symboledStr, charSUBIndeces);
	string binaryText = symbols_to_binary_str(symboledStr, charSUBIndeces);
	string text = binary_to_text(codes, binaryText);
	return text;
}



int main()
{
	string symbols = readFile();
	string text = decompress(symbols);
	writeFile(text);
}