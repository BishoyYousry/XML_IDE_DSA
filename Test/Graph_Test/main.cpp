#include <bits/stdc++.h>
#include "Graph.h"
using namespace std;

string readFile(string path = "XMLFile.xml")
{
    string line;
    string wholeFile = "";
    ifstream inputFile(path);
    while (getline(inputFile, line))
        wholeFile += line + "\n";
    return wholeFile;
}

int main()
{
    Graph g;
    g.extract_data(readFile("XMLFile.xml"));

    //To test most influncer + most active + follower suggestion + mutual followers
    vector<string>result = g.get_most_influncer();
    //vector<string>result = g.get_most_active();
    //vector<string>result = g.get_followers_suggestions(3);
    //vector<string>result = g.get_mutual_followers(2,3);
    if (result.size() == 1 && result[0] == " ")
        cout << "error" << endl;
    else
       for (auto element : result)
        cout << element << " ";
    cout << endl;

    //To test Post search
    vector<pair<string, Post>>output = g.post_search("Lorem");
    for (auto element : output)
    {
        cout << element.first << ":\n" << "Body:" << element.second.body << "\n";
        for (auto e : element.second.topics)
        {
            cout << "Topics:" << e << "\n";
        }
        cout << endl;
    }


    return 0;
}