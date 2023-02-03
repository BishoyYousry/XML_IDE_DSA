#include "xml_minifying.h"
#include <sstream>

using namespace std;

string xml_minifying(string fileStr)
{
	istringstream stream(fileStr);
	string line;
	string result = "";

	while (getline(stream, line))
	{
		for (size_t i = 0; i < line.size(); i++)
		{
			if (line[i] == ' ')
			{
				if (i != 0 && line[i - 1] != '>' && i < line.size() - 1 && line[i + 1] != '<' && line[i + 1] != ' ') continue;
				else
				{
					line.erase(i, 1);
					i--;
				}
			}
			else if (line[i] == '\n' || line[i] == '\t')
			{
				line.erase(i, 1);
				i--;
			}
		}
		result = result + line;
	}
	return result;
}