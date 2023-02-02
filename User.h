#pragma once
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

class User
{
private:
	string name;
	vector<int>followers;
	int followeeNumber;
public:
	User(string& name);
	friend class Graph;
};

