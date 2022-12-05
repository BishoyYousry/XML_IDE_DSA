void xml_minifying()
{
	ifstream inputFile("C:/Users/future/Desktop/main/main/XMLFile.xml");
	fstream outputFile;
    outputFile.open("XMLFile.txt", ios::out);
	string line;
	
	while (getline(inputFile, line))
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
		outputFile << line;
	}
	outputFile.close();
}