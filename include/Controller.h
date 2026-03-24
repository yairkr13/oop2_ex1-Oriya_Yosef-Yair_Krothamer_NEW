#pragma once
#include <vector>
#include "SimpleFunc.h"

class Controller
{
public:
	Controller();
	//~Controller();
	void run();
private:
	void print() const;
	bool handleInput();
	void printHelp() const;
	void deleteFunc(int index);
	std::vector<std::shared_ptr<SimpleFunc>> m_simplefunc;
	//std::vector<SimpleFunc *> m_functions
};
