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
#include <stack>


using namespace std;



//--------------------- array to tree ------------------------------------------------------------


    Node* arrToTree(vector<Node*> &arr) {

        stack<Node*> stack ;

        for (Node* current : arr) {

            if (current-> type == 1) {
                Node* temp = new Node(NodeType::ELEMENT, current-> data);
                Node* top = stack.top();
                while (top-> type != NodeType::OPENINGTAG) {
                    temp-> children.push_back(top);
                    top = stack.top();
                    stack.pop();
                }

                top = ((stack.empty()) ? nullptr : stack.top());
                if (!stack.empty() && (top->data)._Equal(current->data)) {
                    top->type = NodeType::REPEATEDTAG;
                    if (temp->children.size() == 1)
                        top->children.push_back(temp->children[0]);
                    else {
                        temp->data = "";
                        if (top-> notFirst) {
                            top->children.push_back(temp);
                        }
                        else {
                            Node* e = new Node(NodeType::ELEMENT, "");
                            e->children = top->children;
                            top->children = vector<Node*>();
                            top->children.push_back(e);
                            top->children.push_back(temp);
                            top->notFirst = true;
                        }
                    }
                }
                else if (temp->children.size() == 1 && temp->children[0]->type == NodeType::DATA) {

                    temp->type = NodeType::DATAELEMENT;
                    stack.push(temp);
                }
                else {
                    stack.push(temp);
                }
            }
            else
            {
                stack.push(current);
            }


        }
        return stack.top();
    }

    //--------------------------- xml to array -------------------------------------------------

    vector<Node*> XML_Arr(string xmlFile_name) {

        string x;
        string y;

        ifstream f(xmlFile_name);
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
        return allNodes;
    }

    //----------------------------------------------------------------------------------------

    enum NodeType { OPENINGTAG, CLOSINGTAG, DATA, ELEMENT, REPEATEDTAG, DATAELEMENT };

    static class Node {

    public:

        NodeType type;
        string data;
        vector <Node*> children;
        bool notFirst ;

    public:


        Node(NodeType t, std::string d) {
            this->type = t;
            this->data = d;
            this->children = vector<Node*>();
            
        }

    };


    int main()
    {

    }
