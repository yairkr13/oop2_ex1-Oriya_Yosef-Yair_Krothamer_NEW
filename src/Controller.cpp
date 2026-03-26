//Check if its Work
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

//bool Controller::handleInput()
//{
//    std::string str;
//    std::cin >> str;
//    // קורא את המילה הראשונה את הפקודה
//
//    if (str == "exit")
//    {
//        std::cout << "Goodbye\n";
//        return false;
//    }
//    else if (str == "help")
//    {
//        printHelp();
//        return true;
//    }
//
//    std::string line;
//    std::getline(std::cin, line);
//    // קורא את שאר השורה אחרי הפקודה
//
//    std::istringstream iss(line);
//    // מאפשר לקרוא מתוך ליין כאילו זה קלט רגיל
//
//    if (str == "log")
//    {//ask yehazkel B!!!!!!!!!!!!!!!
//        double base;
//        iss >> base;
//        // קורא את המספר שאחרי הלוג
//
//        //log(base);
//        // כאן צריך שפונקציית לוג תקבל דאבל ולא סטרינג
//        // יוצר אובייקט חדש של לוג ומעביר את base 
//        m_simpleFunc.push_back(std::make_shared<LogFunc>(base));
//    }
//    else if (str == "poly")
//        m_simpleFunc.push_back(std::make_shared<PolyFunc>(line));
//    
//    else if (str == "add" || str=="mul")//fix!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!1
//    {
//        int index1, index2;
//        iss >> index1 >> index2;
//
//        // קריאה לפונקציית העזר במקום כל ה-if/else!
//        auto p1 = getFunc(index1);
//        auto p2 = getFunc(index2);
//
//        // חובה לבדוק שהאינדקסים באמת קיימים
//        if (p1 && p2)
//        {
//            if(str=="add")
//                m_complexFunc.push_back(std::make_shared<AddFunc>(p1, p2));
//            else if(str=="mul")
//                m_complexFunc.push_back(std::make_shared<MulFunc>(p1, p2));
//        }
//    }
//    
//    else if (str == "eval")
//    {
//        int index;
//        double x;
//        iss >> index >> x;
//        evalFunc(index, x);
//    }
//    else if (str=="scale")
//    {
//        int index;
//        double scalar;
//        iss >> index >> scalar;
//
//        if (index >= 0 && index < m_simpleFunc.size())
//            m_simpleFunc.push_back(std::make_shared<ScalarMul>(scalar, m_simpleFunc[index]->clone()));
//        
//	}
//    else if (str == "del")
//    {
//        int index;
//        iss >> index;
//        // קורא את האינדקס שאחרי הדל(דליט)ג
//
//        deleteFunc(index);
//    }
//    else
//        std::cout << "Unknown command\n";
//    
//    return true;
//}

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

    evalFunc(index, x);
    return true;
}

void Controller::evalFunc(int index, double x) const
{
    const auto funcPtr = getFunc(index); // קריאה לפונקציית העזר

    if (funcPtr != nullptr) // מוודאים שהאינדקס באמת היה קיים
    {
        funcPtr->calculate(x);
        // הערה: אם calculate רק מחזירה ערך ולא מדפיסה אותו, 
        // אולי תצטרכי להוסיף כאן std::cout
    }
}

bool Controller::scaleCommand(std::istringstream& iss)
{
    int index;
    double scalar;
    iss >> index >> scalar;

    if (index < 0 || index >= static_cast<int>(m_simpleFunc.size()))
    {
        std::cout << "Invalid function index\n";
        return true;
    }

    m_simpleFunc.push_back(
        std::make_shared<ScalarMul>(scalar, m_simpleFunc[index]->clone())
    );

    return true;
}

bool Controller::delCommand(std::istringstream& iss)
{
    int index;
    iss >> index;

    deleteFunc(index);
    return true;
}

void Controller::deleteFunc(int index)
{
    if (index < 0) return;
    int simpleSize = m_simpleFunc.size();
    if (index >= 0 && index < simpleSize)
        m_simpleFunc.erase(m_simpleFunc.begin() + index);
    else if (index < simpleSize + m_complexFunc.size())
        m_complexFunc.erase(m_complexFunc.begin() + (index - simpleSize));
}

std::shared_ptr<Function> Controller::getFunc(int index) const
{
    int simpleSize = m_simpleFunc.size();
    if (index >= 0 && index < simpleSize)
        return m_simpleFunc[index];
    if (index >= simpleSize && index < simpleSize + m_complexFunc.size())
        return m_complexFunc[index - simpleSize];

    return nullptr; // אם האינדקס לא חוקי
}
