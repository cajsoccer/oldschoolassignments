#include "Student.h"

Student::Student()
{    
}

Student::Student(std::string name, std::string id, std::string essay, std::vector <std::string> errorList)
{
    this->name = name; 
    this->id = id;
    this->essay = essay;
    this->errorList = errorList;
}

Student::~Student()
{
}

std::string Student::getEssay()
{
    return essay;
}
void Student::setEssay(std::string essay)
{
    this->essay = essay;
}
std::string Student::getId()
{
    return id;
}
void Student::setId(std::string id)
{
    this->id = id;
}
std::string Student::getName()
{
    return name;
}
void Student::setName(std::string n)
{
    this->name = name;
}
std::vector <std::string> Student::getErrorList()
{
    return errorList;
}
void Student::setErrorList (std::vector <std::string> errorList)
{
    this->errorList = errorList;
}
std::string Student::getPrintableErrorList()
{
    std::string errors = "";
    int count = 1;
    for (auto word: errorList)
    {
        errors = errors + "(" + std::to_string(count) + ") " + word + "\n";
        count++;
    }
    return errors;
}
void Student::writeToFile()
{
}