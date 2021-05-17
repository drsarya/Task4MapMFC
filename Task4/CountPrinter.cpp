#include "CountPrinter.h"

bool CountPrinter::compare(Node* a, Node* b)
{
	return	 a->getWord() < b->getWord();
}

string CountPrinter::refactor(vector<Node*> array)
{
	sort(array.begin(), array.end(), compare);
	return toString(array);
}


CountPrinter::~CountPrinter()
{
}