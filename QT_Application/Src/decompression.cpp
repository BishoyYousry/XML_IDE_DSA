#include"decompression.h"


using namespace std;

//Static global variable, it will be used in readFile function
static vector<pair<string, char>> codes;

/*Time complexity = O(log(n))*/
/*Space complexity = O(1)*/
template<typename T1, typename T2>
int get_vector_index(vector<pair<T1, T2>>& codes, T1 t)
{
    auto it = find_if(codes.begin(), codes.end(),
		[&](const auto& pair) { return pair.first == t; });
	if (it != codes.end())
		return (int)(it - codes.begin());
	return -1;
}

/*Time complexity = O(log(n)) , n -> no. of different chars*/
/*Space complexity = O(n)*/
vector<pair<string, char>> extract_char_codes(string& symboledStr, vector<int>& charSUBIndeces, int& lastSymbolBytes)
{
	int i = 0;
	string buffer = "";
	/*Extract no. of bytes of the last symbol*/
	while (symboledStr[i] != ' ' && symboledStr[i] != (char)4)
	{
		buffer += symboledStr[i];
		i++;
	}
	if (buffer.size())
	{
		lastSymbolBytes = stoi(buffer);
		i++;
	}

	buffer = "";
	char currentChar = symboledStr[i], previous = currentChar;
	/*Extract the indeces of SUB char in the vector -> charSUBIndeces*/
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

	/*Extract characters codes*/
	vector<pair<string, char>>codes;
	int startIndex = symboledStr.find('\n');
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

/*Time complexity = O(n), n -> no. of symbols after converting to symbols*/
/*Space complexity = O(n)*/
string symbols_to_binary_str(string symboledStr, vector<int>charSUBIndeces, int lastSymbolBytes)
{
	string binaryText = "";
	size_t startIndex = symboledStr.find('\n');
	int SUBIndex = 0, countSymbols = 0;		// To calculate the correct index of SUB char in encoding
	/*Convert symbols to binary ASCII*/
	for (size_t i = startIndex + 1; i < symboledStr.size(); i++)
	{
		/*If the current index is found in the vector charSUBIndeces then insert "00011010" -> SUB char*/
		if (SUBIndex < charSUBIndeces.size() && charSUBIndeces[SUBIndex] == countSymbols)
		{
			binaryText += ASCII_26;
			SUBIndex++;
			i--;
		}
		else if (i == symboledStr.size() - 2)	/*The last symbol*/
		{
			if (lastSymbolBytes == 1)
			{
                bitset<1>x((unsigned int)symboledStr[i]);
				binaryText += x.to_string();
			}
			else if (lastSymbolBytes == 2)
			{
                bitset<2>x((unsigned int)symboledStr[i]);
				binaryText += x.to_string();
			}
			else if (lastSymbolBytes == 3)
			{
                bitset<3>x((unsigned int)symboledStr[i]);
				binaryText += x.to_string();
			}
			else if (lastSymbolBytes == 4)
			{
                bitset<4>x((unsigned int)symboledStr[i]);
				binaryText += x.to_string();
			}
			else if (lastSymbolBytes == 5)
			{
                bitset<5>x((unsigned int)symboledStr[i]);
				binaryText += x.to_string();
			}
			else if (lastSymbolBytes == 6)
			{
                bitset<6>x((unsigned int)symboledStr[i]);
				binaryText += x.to_string();
			}
			else if (lastSymbolBytes == 7)
			{
                bitset<7>x((unsigned int)symboledStr[i]);
				binaryText += x.to_string();
			}
			else
			{
                bitset<8>x((unsigned int)symboledStr[i]);
				binaryText += x.to_string();
			}
			countSymbols++;
			i++;
		}
		else /*if (i != symboledStr.size() - 2)*/
		{
            bitset<8>x((unsigned int)symboledStr[i]);
			binaryText += x.to_string();
			countSymbols++;
		}
	}
	return binaryText;
}

/*Time complexity = O(nlog(n))*/
/*Space complexity = O(n)*/
string binary_to_text(vector<pair<string, char>>codes, string binaryText)
{
	/*Convert binary ASCII to the original chars*/
	string text = "", buffer = "";
	//O(n)
	for (size_t i = 0; i < binaryText.size(); i++)
	{
		buffer += binaryText[i];
		int index = get_vector_index<string, char>(codes, buffer);	//O(nlog(n))
		if (index != -1)
		{
			text += codes[index].second;
			buffer = "";
		}
	}
	return text;
}

/*Time complexity = O(nlog(n))*/
/*Space complexity = O(log(n))*/
string decompress(string symboledStr)
{
	vector<int>charSUBIndeces;
	int lastSymbolBytes = 8;	//Default value
	codes = extract_char_codes(symboledStr, charSUBIndeces, lastSymbolBytes);
	string binaryText = symbols_to_binary_str(symboledStr, charSUBIndeces, lastSymbolBytes);
	string text = binary_to_text(codes, binaryText);
    return text;
}

int detect_type(string s)
{
    for (size_t i = 0; i < codes.size(); i++)
    {
        // If we find '{' or '[' or '\\' or ':', this file was JSON
        switch (codes[i].second)
        {
        case '{':
        case '[':
        case '\\':
        case ':':
            return 1;
            break;

            // If we find '<', this file was XML
        case '<':
            return 0;
            break;
        }
    }
    return 2;
}
