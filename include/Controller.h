#pragma once
#include <vector>
#include "SimpleFunc.h"
#include "ComplexFunc.h"

class Controller
{
public:
	Controller();
	//~Controller();//hiiiiiii
	void run();
private:
	void print() const;
	bool handleInput();
	void printHelp() const;
	void deleteFunc(int index);
	void evalFunc(int index, double x) const;
	std::shared_ptr<Function> getFunc(int index) const;
	//int inWhatVector(int index) const;
	std::vector<std::shared_ptr<SimpleFunc>> m_simpleFunc;
	std::vector<std::shared_ptr<ComplexFunc>> m_complexFunc;
};
