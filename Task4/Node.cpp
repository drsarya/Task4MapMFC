#include "Node.h"
Node::Node(string word, int count)
{
	this->count = count;
	this->word = word;
}

Node::~Node()
{
	delete this;
}

string Node::toString()
{
	return word + " : " + to_string(count);
}

int Node::getCount()
{
	return count;
}

string Node::getWord()
{
	return word;
}

void Node::add(int newCount)
{
	count += newCount;
}