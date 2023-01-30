#include "Tree_Node.h"

Tree_Node::Tree_Node(int freq, char c)
{
	this->freq = freq;
	this->c = c;
	this->left = nullptr;
	this->right = nullptr;
}
