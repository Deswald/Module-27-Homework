#include "logger.hpp"

Logger::Logger()
{
	_log_file.open("log.txt", std::fstream::in | std::fstream::out | std::fstream::app);
};
Logger::~Logger()
{
	_log_file.close();
};

void logWrite(Logger& logger, std::string& text)
{
	if (!logger._log_file.is_open())
	{
		std::cout << "ERROR: _log_file not open";
		return;
	}
	logger._sharedMutex.lock();
	logger.lastLine = logger._log_file.tellg();
	logger._log_file << text << std::endl;
	logger._sharedMutex.unlock();
}

void logRead(Logger& logger)
{
	if (!logger._log_file.is_open())
	{
		std::cout << "ERROR: _log_file not open";
		return;
	}
	logger._sharedMutex.lock_shared();
	logger._log_file.seekg(logger.lastLine, std::ios_base::beg);
	std::string read;
	while (std::getline(logger._log_file, read))
	{
		std::cout << "Result: " << read << std::endl;
	}
	logger._sharedMutex.unlock_shared();
}