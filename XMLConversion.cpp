// XMLConversion.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include<string>
#include <algorithm>
#include <cctype>
#include <vector>
#include <list>


using namespace std;


int main()
{
    string x;
    string y;

    ifstream f("XML.txt");
    ofstream fileCreated("Testf.txt");


    vector<Node*> allNodes = vector<Node*>();

    while (getline(f, x)) {
        stringstream ss;
        for (int i = 0; i < x.length(); i++) {

            if (x.at(i) == '<') {
                i++;
                bool ct = false;
                if (x[i] == '/') {
                    ct = true;
                    i++;
                }
                while (x[i] != '>') {
                    ss << x[i];
                    i++;
                }

                Node* n = new Node(((ct) ? NodeType::CLOSINGTAG : NodeType::OPENINGTAG), ss.str());

                allNodes.push_back(n);
            }

            else {

                while (x[i] != '<')
                    ss << x[i++];

                Node* n = new Node(NodeType::DATA, ss.str());
                allNodes.push_back(n);
                i--;
            }
        }

    }
}

enum NodeType { OPENINGTAG, CLOSINGTAG, DATA, ELEMENT, REPEATEDTAG, DATAELEMENT };

 static class Node {

private:

    NodeType* type;
    string data;
    vector <Node*> children;

public:

    Node() {
        this->type = nullptr;
        this->data = nullptr;
        this->children = vector<Node*>();
    }


   Node(NodeType* t, std::string d) {
        this->type = t;
       this->data = d;
        this->children = vector<Node*>();
    }


};

