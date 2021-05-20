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
	string result = "";
	if (printer == nullptr) {

		result += BasePrinter::toString(words);
	}
	else {
		result = printer->refactor(words);
	}

	return result;
}

void MyMap::fromFile(string str)
{
	Logger::log("чтение словаря из файла", LOG_ENUM::OK);
	vector<Node*>* newMap = new vector<Node*>;
	const regex r("([a-zа-яёА-ЯЁ]+)\\s*:{1}\\s*(\\d+)|(\\d+)\\s*:{1}\\s*([a-zа-яёА-ЯЁ]+)", regex::icase);
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
string MyMap::toFile(BasePrinter* printer)
{
	Logger::log("сохранение словаря в файл", LOG_ENUM::OK);
	string text = "";
	if (printer == nullptr) {
		text += BasePrinter::toString(words);
	}
	else {
		text = printer->refactor(words);
	}
	return text;
}

//string MyMap::toString()
//{
//	string result = "";
//	for (Node* number : words) {
//		result += number->toString();
//		result += " ";
//		result += "\n";
//	}
//	return result;
//}

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