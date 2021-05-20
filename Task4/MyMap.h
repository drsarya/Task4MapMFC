#pragma once
#include <string>
#include <vector>   

#include "BasePrinter.h"
using namespace std;
class MyMap {
private:
	vector<Node*> words;
public:
	MyMap() {};

	vector<Node*> getMap();

	string print(BasePrinter* printer);

	void fromFile(string str);

	string toFile(BasePrinter* printer);

	void addWords(string file);

	~MyMap();
private:
	bool  contains(string word, int count);
};
