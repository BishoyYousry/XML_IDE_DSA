#pragma once
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>
#include <utility>
#include <algorithm>
#include "Utility.h"
#include "User.h"
#include "set.h"
using namespace std;

struct Post
{
	string body;
	vector<string>topics;
};

class Graph
{
private:
	unordered_map<int, User*>graph;
	unordered_map<string,Set>postByWord;
	unordered_map<int, pair<int,Post>>postById;
	pair<string, int>mostInfluncer; //name of most influncer user + number of its followers
	pair<string, int>mostActive;   //name of most active user + number of its followee
public:
	Graph();
	~Graph();
	void add_user(int id,string& name);
	void add_post(int userId, int postId, Post post);
	void add_followers(int srcId, int dstId);
	vector<string> get_most_influncer();
	vector<string> get_most_active();
	vector<string> get_mutual_followers(int firstId, int secondId);
	vector<string>get_followers_suggestions(int id);
};