#include "Decompression.h"
#include <string>

int main()
{
	string symbols = readFile("Sample.hm");
	string text = decompress(symbols);
	writeFile(text);
}