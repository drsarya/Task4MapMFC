#define  _CRT_SECURE_NO_WARNINGS 
#include "Logger.h"
using namespace std;

string Logger::getCurrentDateTime(string s) {
	time_t now = time(0);
	struct tm  tstruct;
	char  buf[80];
	tstruct = *localtime(&now);
	if (s == "now")
		strftime(buf, sizeof(buf), "%Y-%m-%d %X", &tstruct);
	else if (s == "date")
		strftime(buf, sizeof(buf), "%Y-%m-%d", &tstruct);
	return string(buf);
}

Logger::~Logger()
{
}



void Logger::log(string logMsg, LOG_ENUM log) {

	string filePath = "C:/Users/Tom/source/repos/Task4MapMFC/Task4/" + getCurrentDateTime("date") + ".txt";
	string now = getCurrentDateTime("now");
	ofstream ofs(filePath.c_str(), ios_base::out | ios_base::app);

	ofs << now << '\t' << toString(log) << " " << logMsg << " " << '\n';
	ofs.close();
}