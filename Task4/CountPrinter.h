#pragma once
#include "BasePrinter.h"
#include "Node.h"
class CountPrinter : public  BasePrinter {
public:
	CountPrinter() :BasePrinter() {};

	static bool compare(Node* a, Node* b);
	string refactor(vector<Node*>  array);
	~CountPrinter();

};
