#pragma once
#include <fstream>
#include <shared_mutex>
#include <string>
#include <iostream>
#include <thread>

class Logger
{
public:
	Logger();
	~Logger();

	std::shared_mutex _sharedMutex;
	std::fstream _log_file;
	int lastLine = 0;

private:
};

void logWrite(Logger& logger, std::string& text);
void logRead(Logger& logger);
