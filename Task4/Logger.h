#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <xiosbase>
#include <fstream>
#include "LogEnum.h"

using namespace std;



class Logger
{
public:

	static void	log(string logMsg, LOG_ENUM log);

private:
	static string getCurrentDateTime(string s);

	~Logger();
};