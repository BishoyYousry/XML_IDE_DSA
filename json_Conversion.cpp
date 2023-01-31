
#include "json_Conversion"


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


//-----------------------------------------------------------------------------------------------------


Node::Node(NodeType t, std::string d) {
    this->type = t;
    this->data = d;
    this->children = vector<Node*>();

}

//-------------------------------------------------------------------------------------------------------

string repeat(string st, int count) {
    stringstream s;
    for (int i = 0; i < count; i++) {
        s << st;
    }
    return s.str();
}

//----------------------------------- TREE TO JSON -----------------------------------------------------------

void treeToJson(Node* n, int TapCount, ostringstream& s) {

    TapCount++;

    s << repeat("    ", TapCount);
    if (n->type == NodeType::DATA && typeid(n->data).name() != "i") {
        s << "\"" + n->data + "\"";
        return;
    }


    if (n->type == NodeType::DATAELEMENT) {
        if (typeid(n->children[0]->data).name() != "i")
            s << "\"" + n->data + "\": \"" + n->children[0]->data + "\"";
        else
            s << n->children[0]->data;

        return;
    }

    if (n->data != "") s << "\"" + n->data + "\": ";

    if (n->type == NodeType::REPEATEDTAG)
        s << "[\n";
    else
        s << "{\n";

    for (int i = 0; i < n->children.size(); i++) {

        treeToJson(n->children[i], TapCount, s);

        if (i < n->children.size() - 1)
            s << ", \n";
        else {

            s << '\n';
            s << repeat("    ", TapCount);

            if (n->type == NodeType::REPEATEDTAG)
                s << "]";
            else
                s << "}";
        }
    }
}


//---------------------------------------- ARRAY TO TREE ----------------------------------------------------------



Node* arrToTree(vector<Node*> arr) {

    stack<Node*> stack;


    for (Node* current : arr) {

        if (current->type == NodeType::CLOSINGTAG) {
            Node* temp = new Node(NodeType::ELEMENT, current->data);
            Node* top = stack.top();
            stack.pop();

            while (top->type != NodeType::OPENINGTAG) {
                temp->children.insert(temp->children.begin(), top);
                top = stack.top();
                stack.pop();
            }

            top = ((stack.empty()) ? nullptr : stack.top());
            if (!stack.empty() && top->data._Equal(current->data)) {
                top->type = NodeType::REPEATEDTAG;
                if (temp->children.size() == 1)
                    top->children.push_back(temp->children[0]);
                else {
                    temp->data = "";
                    if (top->notFirst) {
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

//--------------------------- xml to array ------------------------------------------------------


vector<Node*> XML_Arr(string xmlFile_name) {

    vector<Node*> allNodes = vector<Node*>();

    for (int i = 0; i < xmlFile_name.length(); i++) {
        if (xmlFile_name[i] == ' ' || xmlFile_name[i] == '\n')
            continue;

        stringstream ss;

        if (xmlFile_name.at(i) == '<') {
            i++;
            bool ct = false;
            if (xmlFile_name[i] == '/') {
                ct = true;
                i++;
            }
            while (xmlFile_name[i] != '>') {
                ss << xmlFile_name[i];
                i++;
            }

            Node* n = new Node(((ct) ? NodeType::CLOSINGTAG : NodeType::OPENINGTAG), ss.str());

            allNodes.push_back(n);
        }

        else {

            while (xmlFile_name[i] != '<')
                ss << xmlFile_name[i++];

            Node* n = new Node(NodeType::DATA, ss.str());
            allNodes.push_back(n);
            i--;
        }

    }

    return allNodes;
}


//---------------------------------- XML To JSON -----------------------------------------------------

string xmlToJson(string xml) {

    vector<Node*> arr = XML_Arr(xml);
    //reverse(arr.begin(), arr.end());
    Node* node = arrToTree(arr);
    ostringstream sb;
    treeToJson(node, 0, sb);
    return "{\n" + sb.str() + "\n}";
}

//---------------------------------- XML TO String -----------------------------------------------------

string XMLToString(string fileName) {
    stringstream ss;
    string x;
    ifstream f(fileName);

    while (getline(f, x)) {
        ss << x;
    }
    return ss.str();
}

//---------------------------------- MAIN ----------------------------------------------------------------

int main()
{
    string y;
    string x = XMLToString("XML.txt");
    y = xmlToJson(x);
    cout << y;
}

