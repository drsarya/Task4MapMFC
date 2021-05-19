#include "MyMap.h"
#include "BasePrinter.h"
#include <algorithm>   
#include <iostream>
#include <regex>
#include "Logger.h"
#include "LogEnum.h"


using namespace std;
vector<Node*> MyMap::getMap()
{
	return  words;
}

string MyMap::print(BasePrinter* printer)
{

	Logger::log("просмотр словаря", LOG_ENUM::OK);

	return printer->refactor(words);
}

void MyMap::fromFile(string str)
{
	Logger::log("чтение словаря из файла", LOG_ENUM::OK);
	vector<Node*>* newMap = new vector<Node*>;
	const regex r("([a-zа-яА-ЯЁ]+)\\s*:{1}\\s*(\\d+)|(\\d+)\\s*:{1}\\s*([a-zа-яА-ЯЁ]+)", regex::icase);
	smatch m;
	while (std::regex_search(str, m, r)) {
		if (m.size() == 5 && m[1] != "") {
			string word = m[1];
			int count = std::stoi(m[2]);
			contains(word, count);
		}
		else if (m.size() == 5) {
			Logger::log("Решён конфликт синтаксиса count:string ->  string:count ", LOG_ENUM::RESOLVE);

			string word = m[4];
			int count = std::stoi(m[3]);
			contains(word, count);
		}
		str = m.suffix().str();
	}
}
string MyMap::toFile()
{
	Logger::log("сохранение словаря в файл", LOG_ENUM::OK);
	BasePrinter * ip = new BasePrinter();
	string text = ip->toString(words);
	return text;
}

void MyMap::addWords(string file)
{
	const regex r("[a-zа-яёА-ЯЁ]+", regex::icase);
	smatch m;
	while (std::regex_search(file, m, r)) {
		contains(m[0], 1);
		file = m.suffix().str();
	}
}

bool MyMap::contains(string word, int count) {
	std::locale::global(std::locale("Russian"));
	std::wcout.imbue(std::locale());
	transform(word.begin(), word.end(), word.begin(), ::tolower);
 
 
	bool state = false;
	for (Node* number : words) {
		if (number->getWord() == word) {
			number->add(count);
			state = true;
		}
	}
	if (state == false) {
		Logger::log("Добавление нового слова: " + word, LOG_ENUM::OK);
		Node* node = new Node(word, count);
		words.push_back(node);
	}
	return state;
}
MyMap::~MyMap()
{
	delete this;
}