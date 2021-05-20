
#include "BasePrinter.h"
#include <string>


bool BasePrinter::compare(Node* a, Node* b)
{
	return	 a->getWord() < b->getWord();
}

string BasePrinter::refactor(vector<Node*> array)
{
	sort(array.begin(), array.end(), compare);
	return toString(array);
}

string BasePrinter::toString(vector<Node*> array)
{
	string result = "";
	for (Node* number : array) {
		result += number->toString();
		result += " ";
		result += "\n";
	}
	return result;
}

BasePrinter::~BasePrinter()
{
	delete this;
}
