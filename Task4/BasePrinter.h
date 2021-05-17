#pragma once

#include "Node.h"
#include <vector> 
#include <algorithm>   
class  BasePrinter
{
protected:
public:
	BasePrinter() {};
	static bool compare(Node* a, Node* b);
	virtual string refactor(vector<Node*>  array);
	static	string toString(vector<Node*>  array);
	~BasePrinter();

};