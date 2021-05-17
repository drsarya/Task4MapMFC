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

	string print(BasePrinter* prinster);

	void fromFile(string str);

	void toFile();

	void addWords(string file);

	~MyMap();
private:
	bool  contains(string word, int count);
};
