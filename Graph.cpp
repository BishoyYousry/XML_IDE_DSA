#include "Graph.h"

Graph::Graph()
{
	mostInfluncer.first = "";
	mostInfluncer.second = 0;

	mostActive.first = "";
	mostActive.second = 0;
}

Graph::~Graph()
{
	for (auto element : graph)
		delete element.second;
}

void Graph::add_user(int id,string& name)
{
	User* vertix = new User(name);
	graph[id] = vertix;
}

void Graph::add_post(int userId, int postId, Post post)
{
	/*
	  Assumptions:
	  a) there is a space before any word
	  b) Each topic is single word (has no space)
	*/
	postById[postId] = {userId,post};
	string word;
	stringstream iss(post.body);
	while (iss >> word)
	{
		word.erase(remove(word.begin(),word.end(), ','), word.end());
		word.erase(remove(word.begin(), word.end(), '.'), word.end());
		postByWord[word].insert(postId);
	}
	for (auto word : post.topics)
	{
		postByWord[word].insert(postId);
	}
}

void Graph::add_followers(int srcId, int dstId)
{
	//link goes out of src to destination 
	//And this means that destination are follower to src
	graph[srcId]->followers.push_back(dstId);
	graph[dstId]->followeeNumber++;

	//To get most influncer user
	if (graph[srcId]->followers.size() > mostInfluncer.second)
	{
		mostInfluncer.second = graph[srcId]->followers.size();
		mostInfluncer.first = graph[srcId]->name;
	}
	//To get most active user
	if (graph[dstId]->followeeNumber > mostActive.second)
	{
		mostActive.second = graph[dstId]->followeeNumber;
		mostActive.first = graph[dstId]->name;
	}
}

//The user that has the largest number of links go out from itself
vector<string> Graph::get_most_influncer()
{
	vector<string>mostInfluncerUsers;
	for (auto element : graph)
	{
		if (element.second->followers.size() == mostInfluncer.second)
			mostInfluncerUsers.push_back(element.second->name);
	}
	return mostInfluncerUsers;
}

//The user that has the largest number of links go into itself
vector<string> Graph::get_most_active()
{
	vector<string>mostActiveUsers;
	for (auto element : graph)
	{
		if (element.second->followeeNumber == mostActive.second)
			mostActiveUsers.push_back(element.second->name);
	}
	return mostActiveUsers;
}