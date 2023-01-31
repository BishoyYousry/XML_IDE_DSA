#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include<string>
#include <algorithm>
#include <cctype>
#include <vector>
#include <list>
#include <stack>


using namespace std;

//--------------------------------------- NODETYPE -------------------------------------------------

enum NodeType { OPENINGTAG, CLOSINGTAG, DATA, ELEMENT, REPEATEDTAG, DATAELEMENT };

//---------------------------------------- NODE ------------------------------------------------------

static class Node {

public:

    NodeType type;
    string data;
    vector <Node*> children;
    bool notFirst;

public:


    Node(NodeType t, std::string d);

};

//---------------------------------------------------------------------------------------------------

string repeat(string st, int count);

void treeToJson(Node* n, int TapCount, ostringstream& s);

Node* arrToTree(vector<Node*> arr);

vector<Node*> XML_Arr(string xmlFile_name);

string xmlToJson(string xml);

string XMLToString(string fileName);