#ifndef Error_detection_H
#define Error_detection_H


#include<string>
#include<iostream>
#include <sstream>
#include<stack>
#include <vector>
#include <algorithm>

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

bool error_detection(string x);
string angular_brackets_error_list(string);
string angular_brackets_error_correction(string);
string tags_error_list(string);
string tags_error_correction(string);
string error_list(string);
string error_correction(string);

#endif
