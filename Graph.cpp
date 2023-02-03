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
	postById[postId] = {graph[userId]->name,post};
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

vector<string> Graph::get_mutual_followers(int firstId, int secondId)
{
	//sorting the vectors
	//if()
	Utility::quick_sort(graph[firstId]->followers);
	Utility::quick_sort(graph[secondId]->followers);
	vector<int>commonId(graph[firstId]->followers.size() + graph[secondId]->followers.size());
	//declaring result vector to store the common elements
	vector<string>mutualFollowers;
	//iterator to store return type
	vector<int>::iterator it, end;
	end = set_intersection(
		             graph[firstId]->followers.begin(), graph[firstId]->followers.end(),
	               	 graph[secondId]->followers.begin(), graph[secondId]->followers.end(),
		             commonId.begin()
	                 );

	for (it = commonId.begin(); it != end; it++)
		mutualFollowers.push_back(graph[*it]->name);

	return mutualFollowers;
}

vector<string> Graph::get_followers_suggestions(int userId)
{
	vector<int>id_suggestion;
	Set s;
	vector<string>suggestions;
	//This loop get the id of followers of followers
	for (auto follower : graph[userId]->followers)
		id_suggestion.insert(id_suggestion.end(), graph[follower]->followers.begin(), graph[follower]->followers.end());
	//This loop inserts Id in set to be sorted ,remove repeated elements
	//and remove the id of src if found 
	for (auto id : id_suggestion)
	{
		if(id!=userId)
			s.insert(id);
	}
	//This loop check if any id in set is found in src, if so it will remove it
	for (auto id : graph[userId]->followers)
	{
		if (s.exists(id))
			s.remove(id);
	}
	//get items of set in vector so we can access them one by one 
	id_suggestion = s.getElements();
	//Get the name of user eqiovalent to its id
	for (auto id: id_suggestion)
		suggestions.push_back(graph[id]->name);
	return suggestions;
}

vector<pair<string,Post>> Graph::post_search(string word)
{
	vector<pair<string, Post>>result;
	Set postIdSet = postByWord[word]; //Get set of post Id that have this word
	vector<int>postIdVec = postIdSet.getElements(); //get elements from set into vector to access them
	for (auto id : postIdVec)
		result.push_back(postById[id]); //Get pair consists of userName + Post
	return result;
}

//collect the data from XML file 
void Graph::extract_data(string fileStr)
{
	string tempStr = remove_spaces(fileStr);
	istringstream str(one_line_file_handling(tempStr));
	string line, userName;
	stack<string>tags;
	vector<pair<int, int>>followers;		//followers.push_back({srcId, dstId})
	Post post;
	int userId = -1;		//Default value
	int postId = 0;			//Default value
	//To separate user id from followers ids (the default is *user*)
	//switch to follower if we find <follower>
	string userOrFollower = "user";
	while (getline(str, line))
	{
		//Closing tag
		if (line[0] == '<' && line[1] == '/')
		{
			if (line == "</post>")
			{
				//reset post struct to store another one 
				post.body.clear();
				post.topics.clear();
			}
			else if (line == "</user>")
			{
				//Reset userName and userId
				userId = -1;
				userName.clear();
				userOrFollower = "user";
			}
			tags.pop();
		}
		//Opening tag
		else if (line[0] == '<' && line[1] != '/')
		{
			tags.push(line);
			if (tags.top() == "<post>")	postId++;
			else if (tags.top() == "<followers>") userOrFollower = "follower";
		}
		//Data
		else
		{
			if (tags.top() == "<id>")
			{
				if (userOrFollower == "user")
				{
					userId = stoi(line);
					if (!userName.empty())
						add_user(userId, userName);
				}

				else if (userOrFollower == "follower")
					followers.push_back({ userId, stoi(line) });

			}
			else if (tags.top() == "<name>")
			{
				userName = line;
				if (userId >= 0) add_user(userId, userName);
			}
			else if (tags.top() == "<body>")
			{
				post.body = line;
				if (!post.topics.empty()) add_post(userId, postId, post);
			}
			else if (tags.top() == "<topic>")
			{
				post.topics.push_back(line);
				if (!post.body.empty()) add_post(userId, postId, post);
			}
		}
	}
	//Add followers
	for (size_t i = 0; i < followers.size(); i++)
		add_followers(followers[i].first, followers[i].second);
}