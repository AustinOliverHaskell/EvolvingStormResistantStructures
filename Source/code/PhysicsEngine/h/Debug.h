#pragma once

#include <fstream>
#include <string>
#include <vector>

class Debug
{
	public:

		Debug(){};

		static void logf(std::string message);
		static void logs(std::string message);
		static void loga(std::string message);

		static void save(std::string path = "./", std::string name = "CLog.txt");
		static void open(std::string path = "CLog.txt");
		static void close();

		static void clear();
		static void disable();
		static void enable();

	protected:
		static std::ofstream file;
		static bool debugingEnabled;
		static bool fileOpened;
		static std::vector<std::string> *errorList; 
};

std::ofstream Debug::file;
bool Debug::debugingEnabled = true;
bool Debug::fileOpened = false;
std::vector<std::string> *Debug::errorList = NULL;

void Debug::open(std::string path)
{
	fileOpened = file.is_open();

	if (fileOpened)
	{
		// Do nothing
	}
	else
	{
		// Open the file for writing and to append data
		// To append or with std::ios::app
		file.open(path, std::ios::out);
		debugingEnabled = true;

		errorList = new std::vector<std::string>();

		// Make sure that this worked
		fileOpened = file.is_open();

		if (fileOpened == false)
		{
			std::cout << "File opening failed!" << std::endl;
			delete errorList;
		}
	}
}

void Debug::close()
{
	delete Debug::errorList;
	Debug::debugingEnabled = false;
	Debug::file.close();
}

void Debug::logf(std::string message)
{
	if (debugingEnabled)
	{
		message += "\n";
		errorList->push_back(message);
	}
}

void Debug::loga(std::string message)
{
	if (debugingEnabled)
	{
		message += "\n";
		errorList->push_back(message);
		std::cout << message << std::endl;
	}
}

void Debug::logs(std::string message)
{
	if (debugingEnabled)
	{
		std::cout << message << std::endl;
	}
}

void Debug::save(std::string path, std::string name)
{
	for (std::size_t i = 0; i < errorList->size(); i++)
	{
		file << errorList->at(i);
	}
}

void Debug::clear()
{
	// Clear the file
	errorList->clear();
}

void Debug::disable()
{
	Debug::debugingEnabled = false;
}

void Debug::enable()
{
	Debug::debugingEnabled = true;
}