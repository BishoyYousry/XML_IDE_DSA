#include <map>
#include <vector>
#include <iostream>

class Set {
private:
	std::map<int, bool> elements;

public:
	void insert(int element);
	void remove(int element);
	bool exists(int element);
	int size();
	void print();
};