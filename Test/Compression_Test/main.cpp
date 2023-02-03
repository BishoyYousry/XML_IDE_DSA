#include <iostream>
#include "Compression.h"
using namespace std;


int main()
{
	string text = readFile("XMLFile.xml");
	string symbols = compress(text);
	writeFile(symbols);
}