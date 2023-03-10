#include"Error_detection.h"
#include "XMLformatting.h"

bool error_detection(string x)
{
    stack<string> st;
    int i = 0;

    for (i = 0; i < x.length(); i++)
    {
        if (x[i] == '<' && x[i + 1] == '/')
        {
            string poped_str;
            i += 2;
            while (x[i] != '>')
            {
                poped_str.push_back(x[i]);
                i++;
            }

            if ((poped_str.compare(st.top())) == 0)
                st.pop();
            else
            {
                cout << "0.0";
                return false;
            }
        }

        else if (x[i] == '<' && x[i + 1] != '/')
        {
            string pushed_str;
            i++;
            while (x[i] != '>')
            {
                pushed_str.push_back(x[i]);
                i++;
            }
            st.push(pushed_str);
        }
    }

    if (st.empty())
    {
        cout << "1";
        return true;
    }
    else
    {
        cout << "0";
        return false;
    }
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
                for (int j = i - 1; j >= 0; j--)
                {
                    //the missing '<' in a closeTag
                    if (x[j] == '/')
                    {
                        while (x[j+1] != '>')
                        {
                            j++;
                            tag.push_back(x[j]);
                        }
                        angularBracketsErrorList += "there is a missing < in the closeTag </" + tag + "> in the line " + to_string(counter) + "\n";
                        break;
                    }
                    //the missing '<' in a openTag
                    else if (x[j] == '>' || x[j] == '\n' || x[j] == ' ' || j == 0)
                    {
                        while (x[j + 1] != '>')
                        {
                            j++;
                            tag.push_back(x[j]);
                        }

                        angularBracketsErrorList += "there is a missing < in the openTag <" + tag + "> in the line " + to_string(counter) + "\n";
                        break;
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

    while (getline(in, y))
    {
        for (int i = 0; i < y.length(); i++)
        {
            //correct missing '>' errors in any tag
            if (y[i] == '<')
            {
                while (y[++i] != '>')
                {
                    if (y[i] == '<' || i == y.length() || y[i] == '\n' || y[i] == ' ')
                    {
                        y.insert(i, ">");
                        break;
                    }
                }
            }

            //correct missing '<' errors in any tag
            else if (y[i] == '>')
            {

                for (int j = i - 1; j >= 0; j--)
                {
                    if (y[j] == '>' || y[j] == '\n' || y[j] == ' ')
                    {
                        y.insert(j + 1, "<");
                        i++;
                        break;
                    }
                    else if (j == 0 || y[j] == '/')
                    {
                        y.insert(j, "<");
                        i++;
                        break;
                    }
                }
            }
        }
        angularBracketsErrorsCorrected = angularBracketsErrorsCorrected + y + "\n";

    }
    return angularBracketsErrorsCorrected;
}

string  tags_error_list(string input)
{
    istringstream in(input);
    string tagsErrorList;
    vector<tag> list;
    vector<tag>::iterator it;
    vector<int> DataLines;
    vector<int>::iterator tt;
    string x, y;
    int lineNum = 0;
    int comparasonLength = 2;
    int flag = 0;

    DataLines.push_back(0);
    while (getline(in, x))
    {
        lineNum++;
        for (int i = 0; i < x.length(); i++)
        {
            //missing openTag
            if (x[i] == '<' && x[i + 1] != '/')
            {
                i++;
                do
                {
                    y.push_back(x[i++]);
                } while (x[i] != '>');
                tag temp = tag(lineNum, y, 0);
                y = "";
                list.push_back(temp);
                //cout << temp.data;
            }
            //missing closeTag
            else if (x[i] == '<' && x[i + 1] == '/')
            {
                i += 2;
                do
                {
                    y.push_back(x[i++]);
                } while (x[i] != '>');
                x.erase(i + 1, 1);
                for (int j = 0; j < (list.size()); j++)
                {
                    if (j > comparasonLength)
                        break;
                    if (!y.compare((list[list.size() - (1 + j)].data)))
                    {
                        it = (list.begin() + (list.size() - (1 + j)));
                        list.erase(it);
                        flag = 1;
                        break;
                    }
                }
                x.insert(i + 1, "/");
                if (!flag)
                {
                    tag temp = tag(lineNum, y, 1);
                    list.push_back(temp);
                    comparasonLength += 2;
                }
            }
            flag = 0;
            y = "";
        }
    }

    //DataLines.push_back(0);
    tag temp = tag(-1, "", -1);
    list.push_back(temp);
    //***********PRINTING_VECTOR_TAGS***************
    if (!list.empty())
    {
        for (int j = 0; j < list.size(); j++)
        {
            //cout << list[j].data << '\n';
        }
    }
    //***********TROWING_ERRORS******************
    for (int j = 0; j < list.size(); j++)
    {
        tt = find(DataLines.begin(), DataLines.end(), (list[j].lineNum));
        if (list[j].type == 0 && list[j + 1].type == 1 && !(((list[j + 1].lineNum - list[j].lineNum) > 2) && (tt != DataLines.end())) && ((list[j + 1].lineNum - list[j].lineNum) != 1))
        {
            tagsErrorList += "in the line " + to_string(list[j].lineNum) + " the opentag " + list[j].data + " does not match with its expected closetag " + list[j + 1].data + " in the line " + to_string(list[j + 1].lineNum) + " or they both have missing tags  " + "\n";
            j++;
            continue;
        }
        else if (list[j].type == 0)// open tag case 
        {
            tagsErrorList += "in the line " + to_string(list[j].lineNum) + " there is missing closetag for the opentag " + list[j].data + "\n";
        }
        else if (list[j].type == 1)// closeTag case 
        {
            tagsErrorList += "in the line " + to_string(list[j].lineNum) + " there is missing opentag for the closetag " + list[j].data + "\n";
        }
    }
    return tagsErrorList;
}


string tags_error_correction(string input)
{
    istringstream in(input);
    string output;
    vector<tag> list;
    vector<tag>::iterator it;
    vector<int> DataLines;
    vector<int>::iterator tt;
    vector<int>::iterator tt2;
    vector<int> RybishLines;
    vector<int>::iterator Rubishit;
    string x;
    int lineNum = 0;
    int comparasonLength = 2;
    int flag = 0;

    DataLines.push_back(0);
    while (getline(in, x))
    {
        lineNum++;
        //******OPENTAG**************
        if (x[0] == '<' && x[1] != '/')
        {
            tag temp = tag(lineNum, x, 0);
            list.push_back(temp);

        }
        //******CLOSETAG**************
        else if (x[0] == '<' && x[1] == '/')
        {
            x.erase(1, 1);
            for (int j = 0; j < (list.size()); j++)
            {
                if (j > comparasonLength)
                    break;
                if (!x.compare((list[list.size() - (1 + j)].data)))
                {
                    it = (list.begin() + (list.size() - (1 + j)));
                    list.erase(it);
                    flag = 1;
                    break;
                }
            }
            x.insert(1, "/");
            if (!flag)
            {
                tag temp = tag(lineNum, x, 1);
                list.push_back(temp);
                comparasonLength += 2;
            }
        }
        flag = 0;
        //******DATA**************
        if (x[0] != '<')
        {
            DataLines.push_back(lineNum);
        }
    }
    for (int j = 0; j < list.size(); j++)
    {
        RybishLines.push_back(list[j].lineNum);
    }
    DataLines.push_back(0);
    RybishLines.push_back(0);
    tag temp = tag(-1, " ", -1);
    list.push_back(temp);

    //***********PRINTING_Rubish_TAGS***************
    if (!list.empty())
    {
        for (int j = 0; j < list.size(); j++)
        {
            //cout << list[j].data << '\n';
        }
    }
    //***********VALIDATE******************
    int j = 0;
    lineNum = 0;
    int case1_flag = 0;
    int case2_flag = 0;
    string y;
    istringstream on(input);

    while (getline(on, x))
    {
        lineNum++;
        if (case2_flag == 1)
        {
            output += x + "\n";
            case2_flag = 0;
            output += y + "\n";
            continue;
        }

        Rubishit = find(RybishLines.begin(), RybishLines.end(), lineNum);
        if (Rubishit == RybishLines.end())
        {
            output += x + "\n";
            continue;
        }

        if (case1_flag == 1)
        {
            case1_flag = 0;
            output += y + "\n";
            continue;
        }

        tt = find(DataLines.begin(), DataLines.end(), (lineNum + 1));
        tt2 = find(DataLines.begin(), DataLines.end(), (list[j + 1].lineNum - 1));
        if (list[j].type == 0 && list[j + 1].type == 1 && !(((list[j + 1].lineNum - list[j].lineNum) > 2) && ((tt2 != DataLines.end()) || (tt != DataLines.end()))) && ((list[j + 1].lineNum - list[j].lineNum) != 1))
        {
            case1_flag = 1;
            output += x + "\n";
            y = x;
            y.insert(1, "/");
            j++;
            continue;
        }

        tt = find(DataLines.begin(), DataLines.end(), (lineNum + 1));
        if (list[j].type == 0)// open tag case 
        {
            if (tt != DataLines.end())
            {
                output += x + "\n";
                case2_flag = 1;
                x.insert(1, "/");
                y = x;
            }
            else
            {
                output += x + "\n";
                x.insert(1, "/");
                output += x + "\n";
            }
            j++;
            continue;
        }

        tt = find(DataLines.begin(), DataLines.end(), (lineNum - 1));
        if (list[j].type == 1)// closeTag case 
        {
            if (tt != DataLines.end())
            {
                int k = output.length();
                while (output[k] != '>')
                {
                    k--;
                }
                k += 2;
                x.erase(1, 1);
                output.insert(k, (x + "\n"));
                x.insert(1, "/");
                output += x + "\n";
            }
            else
            {
                x.erase(1, 1);
                output += x + "\n";
                x.insert(1, "/");
                output += x + "\n";
            }
            j++;
            continue;
        }
    }
    return output;
}

string error_list(string input) {

    string str1 = angular_brackets_error_list(input);
    string str2 = angular_brackets_error_correction(input);
    string str4 = tags_error_list(str2);
    string errorList = str1 + str4;
    //cout << "\n\n\n" << input;
    return errorList;
}


string error_correction(string input) {
    string str1 = angular_brackets_error_correction(input);
    string str2 = remove_spaces(str1);
    string str3 = one_line_file_handling(str2);
    string str4 = tags_error_correction(str3);
    string str5 = formatting(str4);
    return str5;
}
