#pragma once
#include <vector>
#include <memory>
#include <sstream>
#include "SimpleFunc.h"
#include "ComplexFunc.h"

class Controller
{
public:
    Controller();
    void run();

private:
    void print() const;
    bool handleInput();
    void printHelp() const;
    std::shared_ptr<Function> getFunc(int index) const;

    bool logCommand(std::istringstream& iss);
    bool polyCommand(std::istringstream& iss);
    bool binaryCommand(std::istringstream& iss, const std::string& type);
    bool addCommand(std::istringstream& iss);
    bool mulCommand(std::istringstream& iss);
    bool evalCommand(std::istringstream& iss);
    bool scaleCommand(std::istringstream& iss);
    bool delCommand(std::istringstream& iss);

    std::vector<std::shared_ptr<SimpleFunc>> m_simpleFunc;
    std::vector<std::shared_ptr<ComplexFunc>> m_complexFunc;
};