#pragma once
#include <string>
using namespace std;
class Node
{
public:
	Node(string word, int count);
	~Node();
	string toString();
	int getCount();
	string getWord();
	void add(int count);
private:
	int count;
	string word;
};