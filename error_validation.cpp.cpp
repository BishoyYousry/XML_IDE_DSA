#include"error_validation.h"

string remove_spaces(string input) {
    istringstream in(input);
    string x;
    string noSpaces;
    while (getline(in, x)) {
        //if the line start with spaces delete them until finding the first character then leave the loop
        while (x[0] == ' ' || x[0] == '\t') {
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
        {
            y.insert(0, "\n");
        }
        for (int i = 0; i < y.length(); i++) {
            //at the end of each tag add add newline
            if (y[i] == '>')
            {
                y.insert((i + 1), "\n");
            }
            //at the beginning of the closing tag add newline (to separete the data from the closing tag) 
            else if (y[i] == '<' && y[i + 1] == '/')
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


//detect errors in angular brackets and add them to an error list
string angular_brackets_error_list(string input)
{
    istringstream in(input);
    string x;
    string angularBracketsErrorList;
    int counter = 0; 
    while (getline(in, x))
    {
        counter++;
        for (int i = 0; i < x.length(); i++)
        {
            //missing '>' in the closetag 
            if (x[i] == '<' && x[i + 1] == '/')
            {
                string closeTag;
                i += 2; //to get tag name after "</" characters
                while (x[i] != '>')
                {
                    if (x[i] == '<' || i == x.length() || x[i] == '\n' || x[i] == ' ')
                    {
                        //adding the error to the angualr brackets error list to be printed
                        angularBracketsErrorList += "there is a missing > in the closetag </" + closeTag + "> in the line " + to_string(counter) + "\n";
                        i--;
                        break;
                    }
                    closeTag.push_back(x[i]);
                    i++;
                }
            }

            //missing '>' in the openTag 
            else if (x[i] == '<')
            {
                string openTag;
                i++; //to get tag name after "<" character
                while (x[i] != '>')
                {
                    if (x[i] == '<' || i == x.length() || x[i] == '\n' || x[i] == ' ')
                    {
                        //adding the error to the angualr brackets error list to be printed
                        angularBracketsErrorList += "there is a missing > in the openTag <" + openTag + "> in the line " + to_string(counter) + "\n";
                        i--;
                        break;
                    }
                    openTag.push_back(x[i]);
                    i++;
                }
            }

            //missing '<' in any tag
            else if (x[i] == '>') 
            {
                string tag;
                //go back in the line to get the tag name 
                for (int i = 0; i >= 0; i--)
                {
                    //the missing '<' in a closeTag
                    if (x[i] == '/')
                    {
                        for (int j = i; x[j] != '>'; j++)
                            tag.push_back(x[j]);
                        angularBracketsErrorList += "there is a missing < in the closeTag <" + tag + "> in the line " + to_string(counter) + "\n";

                    }
                    //the missing '<' in a openTag
                    else if ( i == 0)
                    {
                        for (int j = i; x[j] != '>'; j++)
                            tag.push_back(x[j]);
                        angularBracketsErrorList += "there is a missing < in the openTag <" + tag + "> in the line " + to_string(counter) + "\n";
                    }
                }
            }
        }
    }
    return angularBracketsErrorList;
}


//correct angular brackets errors
string angular_brackets_error_correction(string input)
{
    istringstream in(input);
    string y;
    string angularBracketsErrorsCorrected;
    int flag = 0;// handle when a tag contain a missing '>' so it Don't go through the last elseif statement 

    while (getline(in, y))
    {
        for (int i = 0; i < y.length(); i++)
        {
            //correct missing '>' errors in  closeTag
            if (y[i] == '<' && y[i+1] == '/')
            {
                i+=2; //start iterating over the line after "</" characters
                while (y[i] != '>')
                {
                    if (y[i] == '<' || i == y.length() || y[i] == '\n' || y[i] == ' ')
                    {
                        //insert the missing '>' and set the flag 
                        y.insert(i, ">");
                        flag = 1;
                        i--;
                        break;
                    }
                    i++;
                }
            }

            //correct missing '>' errors in  openTag
            else if (y[i] == '<' && y[i + 1] != '/')
            {
                i++; //start iterating over the line after '<' character
                while (y[i] != '>')
                {
                    if (y[i] == '<' || i == y.length() || y[i] == '\n' || y[i] == ' ')
                    {
                        // insert the missing '>' and set the flag
                        y.insert(i, ">");
                        flag = 1;
                        i--;
                        break;
                    }
                    i++;
                }
            }

            //correct missing '<' errors in any tag
            else if (y[i] == '>' && flag == 0)
            {
                for (int j=i; j >= 0; j--)
                {
                    //the missing '<' in a closeTag
                    if (y[j] == '/')
                    {
                        y.insert(j, "<");
                        break;
                    }
                    //the missing '<' in a openTag
                    else if (j == 0)
                    {
                        y.insert(j, "<");   
                        break;
                    }
                }
                break;
            } 
        }

        //saving lines to the output string (angularBracketsErrorsCorrected)
        for (int i = 0; i < y.length(); i++) 
        {
            angularBracketsErrorsCorrected.push_back(y[i]);
        }
    }
    return angularBracketsErrorsCorrected;
}


string error_list(string input) {
    string str1 = angular_brackets_error_list(input);
    string errorList = str1 ;
    return errorList;
}
/*
string str2 = remove_spaces(input);
string str3 = one_line_file_handling(str2);
string str4 = tags_error_list(str3);
string errorList = str1 + "\n" + str4;
*/



string error_correction(string input) {
    string str1 = angular_brackets_error_correction(input);
    string str2 = remove_spaces(str1);
    string str3 = one_line_file_handling(str2);
    return str3;
}


