#include "Controller.h"
#include <iostream>
#include <string>
#include <sstream>	
#include "LogFunc.h"
#include "AddFunc.h"
#include "MulFunc.h"
#include "PolyFunc.h"
#include "ScalarMul.h"
#include <memory>

Controller::Controller()
{
	m_simpleFunc.push_back(std::make_shared<LogFunc>(10));
}

void Controller::run()
{
	while(true)
	{
		std::cout << "This is the function list: \n";
		print();
		std::cout << "Please enter a command ('help' for command list): ";
		if (!handleInput()) //the user enter "exit"
			break;
        std::cout << std::endl;
	}
}

void Controller::print() const
{
    //print the simple functions
    for (int i = 0; i < m_simpleFunc.size(); i++)
    {
        std::cout << i << ": ";
        m_simpleFunc[i]->print();
        std::cout << std::endl;
    }
    //print the complex functions
    for (int i = 0; i < m_complexFunc.size(); i++)
    {
        std::cout << m_simpleFunc.size() + i << ": ";
        m_complexFunc[i]->print();
        std::cout << std::endl;
    }
}

bool Controller::handleInput()
{
    std::string command;
    if (!std::getline(std::cin, command))
        return false;

    if (command.empty())
        return true;

    std::istringstream iss(command);
    std::string cmd;
    iss >> cmd;

    if (cmd == "exit")
    {
        std::cout << "Goodbye\n";
        return false;
    }

    if (cmd == "help")
    {
        printHelp();
        return true;
    }
    else if (cmd == "log")
        return logCommand(iss);
    else if (cmd == "poly")
        return polyCommand(iss);
    else if (cmd == "add")
        return addCommand(iss);
    else if (cmd == "mul")
        return mulCommand(iss);
    else if (cmd == "eval")
        return evalCommand(iss);
    else if (cmd == "scale")
        return scaleCommand(iss);
    else if (cmd == "del")
        return delCommand(iss);

    std::cout << "Unknown command\n";
    return true;
}

void Controller::printHelp() const
{
    std::cout << R"(Following is the list of the calculator's available commands:
	eval(uate) num x              - Evaluates function #num on x
	log X                         - Creates a Log function with X base
	poly(nomial) N c0 c1 ... cN-1 - Creates a polynomial with N coefficients
	add num1 num2                 - Creates a function that is the sum of function #num1 and function #num2
	mul(tiply) num1 num2          - Creates a function that is the multiplication of function #num1 and function #num2
	scale num c                   - Creates a function that is a copy of *simple* function #num with its output scaled by the given scalar c
	del(ete) num                  - Deletes function #num from function list
	help                          - Prints this help screen
	exit                          - Exits the program
	)";
}

bool Controller::logCommand(std::istringstream& iss)
{
    double base;
    iss >> base;

    m_simpleFunc.push_back(std::make_shared<LogFunc>(base));
    return true;
}

bool Controller::polyCommand(std::istringstream& iss)
{
    std::string restOfLine;
    std::getline(iss, restOfLine);

    m_simpleFunc.push_back(std::make_shared<PolyFunc>(restOfLine));
    return true;
}

bool Controller::addCommand(std::istringstream& iss)
{
    return binaryCommand(iss, "add");
}

bool Controller::mulCommand(std::istringstream& iss)
{
    return binaryCommand(iss, "mul");
}

bool Controller::binaryCommand(std::istringstream& iss, const std::string& type)
{
    int index1, index2;
    iss >> index1 >> index2;

    auto p1 = getFunc(index1);
    auto p2 = getFunc(index2);

    if (!p1 || !p2)
    {
        std::cout << "Invalid function index\n";
        return true;
    }

    if (type == "add")
        m_complexFunc.push_back(std::make_shared<AddFunc>(p1, p2));
    else if (type == "mul")
        m_complexFunc.push_back(std::make_shared<MulFunc>(p1, p2));

    return true;
}

bool Controller::evalCommand(std::istringstream& iss)
{
    int index;
    double x;
    iss >> index >> x;

    const auto funcPtr = getFunc(index);

    if (!funcPtr)
    {
        std::cout << "Invalid function index\n";
        return true;
    }

    funcPtr->printRes(x); 
    return true;
}

bool Controller::scaleCommand(std::istringstream& iss)
{
    int index;
    double scalar;
    iss >> index >> scalar;

    if (index < 0 || index >= m_simpleFunc.size())
    {
        std::cout << "Invalid function index\n";
        return true;
    }
    m_simpleFunc.push_back(m_simpleFunc[index]->multiplyByScalar(scalar));

    return true;
}

bool Controller::delCommand(std::istringstream& iss)
{
    int index;
    iss >> index; 

    int simpleSize = static_cast<int>(m_simpleFunc.size());
    int totalSize = simpleSize + static_cast<int>(m_complexFunc.size());

    if (index < 0 || index >= totalSize)
    {
        std::cout << "Invalid function index\n";
        return true; 
    }

    if (index < simpleSize)
        m_simpleFunc.erase(m_simpleFunc.begin() + index);
    else
        m_complexFunc.erase(m_complexFunc.begin() + (index - simpleSize));

    return true;
}

std::shared_ptr<Function> Controller::getFunc(int index) const
{
    size_t simpleSize = m_simpleFunc.size();
    if (index >= 0 && index < simpleSize)
        return m_simpleFunc[index];
    if (index >= simpleSize && index < simpleSize + m_complexFunc.size())
        return m_complexFunc[index - simpleSize];

    return nullptr; // the index out of range
}
