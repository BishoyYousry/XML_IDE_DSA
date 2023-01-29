#ifndef Error detection_H
#define Error detection_H


#include<string>
#include<iostream>
#include <sstream>
#include<stack>
#include <vector>

using namespace std;

class tag
{
public:
    string data;
    int lineNum;
    int type;
    tag(int lineNum, string data, int type)
    {
        this->lineNum = lineNum;
        this->data = data;
        this->type = type;
    }
};


string angular_brackets_error_list(string);
string angular_brackets_error_correction(string);
string tags_error_list(string);
string tags_error_correction(string);
string error_list(string);
string error_correction(string);
string readFile(string);

#endif