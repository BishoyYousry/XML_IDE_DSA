#include "XMLformatting.h"

//make each open tag in the beggining of the line without any spaces before it 

string remove_spaces(string input) {
	istringstream in(input);
	string x;
	string noSpaces;
	while (getline(in, x)) {
		//if the line start with spaces delete them until finding the first character then leave the loop
		while (x[0] == ' ') {
			x.erase(0, 1);
		}
		//saving lines to the output string (noSpaces)
		for (int i = 0; i < x.length(); i++) {
			noSpaces.push_back(x[i]);
		}
	}
	return noSpaces;
}

//handling if many tags and data in the same line 

string one_line_file_handling(string input) {
	istringstream in(input);
	string y;
	string organizedInput;
	int flag = 0; //handle the case when 2 closing tags come consecutively
	while (getline(in, y)) {
		//handle multiple data lines
		if (y[0] != '<')
			y.insert(0, "\n");
		for (int i = 0; i <= y.length(); i++) {
			//at the end of each tag add add newline
			if (y[i] == '>') 
			{
				y.insert((i + 1), "\n");
			}
			//at the beginning of the closing tag add newline (to separete the data from the closing tag) 
			else if (y[i] == '<' && y[i+1] == '/')
			{
				//if the last tag was NOT a closing tag then add newline else DON'T
				if (flag == 0) {
					y.insert(i, "\n");
					i++;
					flag = 1;
				}
			}
			else if (y[i] == '<' && y[i + 1] != '/')
				flag = 0;

		}
		//saving lines to the output string (organiedInput)
		for (int i = 0; i < y.length(); i++) {
			organizedInput.push_back(y[i]);
		}
	}
	return organizedInput;
}

//format the input file 

string formatting(string input) {
	string space = "";
	string z;
	string formattedOutput;
	string str1 = one_line_file_handling(input);  
	string str2 = remove_spaces(str1);
	string str3 = one_line_file_handling(str2);
	istringstream in(str3);
	while (getline(in, z)) {
		//if the line is open tag
		if (z[0] == '<' && z[1] != '/')
		{
			z.insert(0, space);
			space.push_back(' ');
			space.push_back(' ');
			space.push_back(' ');
			space.push_back(' ');
		}
		//if the line is close tag
		else if (z[0] == '<' && z[1] == '/')
		{
			space.pop_back();
			space.pop_back();
			space.pop_back();
			space.pop_back();
			z.insert(0, space);
		}
		//if the line is data
		else if (z[0] != '<')
		{
			z.insert(0, space);
		}
		//saving lines to the output string (formattedOutput)
		for (int i = 0; i < z.length(); i++) {
			formattedOutput.push_back(z[i]);
		}
		formattedOutput.push_back('\n');
	}
	return formattedOutput;
}
