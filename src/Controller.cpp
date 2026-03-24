//Check if its Work
#include "Controller.h"
#include <iostream>
#include <string>
#include <sstream>	
#include <LogFunc.h>

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

bool Controller::handleInput()
{
    std::string str;
    std::cin >> str;
    // קורא את המילה הראשונה את הפקודה

    if (str == "exit")
    {
        std::cout << "Goodbye\n";
        return false;
    }
    else if (str == "help")
    {
        printHelp();
        return true;
    }

    std::string line;
    std::getline(std::cin, line);
    // קורא את שאר השורה אחרי הפקודה

    std::istringstream iss(line);
    // מאפשר לקרוא מתוך ליין כאילו זה קלט רגיל

    if (str == "log")
    {//ask yehazkel B!!!!!!!!!!!!!!!
        double base;
        iss >> base;
        // קורא את המספר שאחרי הלוג

        //log(base);
        // כאן צריך שפונקציית לוג תקבל דאבל ולא סטרינג
        // יוצר אובייקט חדש של לוג ומעביר את base 
        m_simpleFunc.push_back(std::make_shared<LogFunc>(base));
    }
    else if (str == "eval")
    {
        calculateFunc();
    }
    else if (str == "del")
    {
        int index;
        iss >> index;
        // קורא את האינדקס שאחרי הדל(דליט)ג

        deleteFunc(index);
    }
    else
        std::cout << "Unknown command\n";
    
    return true;
}

void Controller::deleteFunc(int index)
{
    int simpleSize = m_simpleFunc.size();
    if (index >= 0 && index < simpleSize)
        m_simpleFunc.erase(m_simpleFunc.begin() + index);
    else if (index < simpleSize + m_complexFunc.size())
        m_complexFunc.erase(m_complexFunc.begin() + (index - simpleSize));
}

void Controller::calculateFunc(int index, double x) const 
{
    int simpleSize = m_simpleFunc.size();
    if (index >= 0 && index < simpleSize)
        simpleSize
}
//bool Controller::handleInput()
//{
//	std::string str;
//	std::cin >> str;
//	if (str == "exit")
//	{
//		std::cout << "Goodbye \n";
//		return false;
//	}
//	else if (str == "help")
//	{
//		printHelp();
//		return true;
//	}
//	std::string line;
//	std::getline(std::cin, line);
//	//
//	//
//	//
//	if (str == "log")
//		log(line); //add to the vector 
//
//	else if (str == "del")//fix!!!!!!!!!!!!!!!!!!!
//		deleteFunc((int)line);
//	
//	else	
//		std::cout << "Unknown command\n";
//	return true;
//}
//  
//void Controller::deleteFunc(int index)
//{
//	int simpleSize = m_simpleFunc.size();
//	if (index >= 0 && index < simpleSize)
//		m_simpleFunc.erase(m_simpleFunc.begin() + index);
//	else if (index < simpleSize + m_complexFunc.size())
//		m_complexFunc.erase(m_complexFunc.begin() + (index - simpleSize));
//}
