#include "UndergraduateStudent.h"
#include <iostream>
#include <fstream>

UndergraduateStudent::UndergraduateStudent(std::string name, std::string id, std::string essay, std::vector <std::string> errorList, std::string major)
: Student(name, id, essay, errorList)
{
    this->major = major;
}

UndergraduateStudent::~UndergraduateStudent()
{
}

std::string UndergraduateStudent::getMajor()
{
    return major;
}
void UndergraduateStudent::setMajor(std::string major)
{
    this->major = major;
}
void UndergraduateStudent::writeToFile()
{
    std::string fileName = id + "_graded.txt";
    std::ofstream file(fileName);
    if (file.is_open())
    {
        file << "Undergraduate Student " + name + "\n";
        file << "Student ID: " + id + "\n";
        file << "Major: " + major + "\n";
        file << getPrintableErrorList();
    }
    else
        std::cout << "Cannot write to file." << std::endl;
    file.close();
}