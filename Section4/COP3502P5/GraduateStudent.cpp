#include "GraduateStudent.h"
#include <iostream>
#include <fstream>

GraduateStudent::GraduateStudent(std::string name, std::string id, std::string essay, std::vector <std::string> errorList, std::string major, std::string advisor)
: Student(name, id, essay, errorList)
{
    this->major = major;
    this->advisor = advisor;
}

GraduateStudent::~GraduateStudent()
{
}

std::string GraduateStudent::getMajor()
{
    return major;
}
void GraduateStudent::setMajor(std::string major)
{
    this->major = major;
}
std::string GraduateStudent::getAdvisor()
{
    return advisor;
}
void GraduateStudent::setAdvisor(std::string advisor)
{
    this->advisor = advisor;
}
void GraduateStudent::writeToFile()
{
    std::string fileName = id + "_graded.txt";
    std::ofstream file(fileName);
    if (file.is_open())
    {
        file << "Graduate Student " + name + "\n";
        file << "Student ID: " + id + "\n";
        file << "Major: " + major + "\n";
        file << "Advisor: " + advisor + "\n";
        file << getPrintableErrorList();
    }
    else
        std::cout << "Cannot write to file." << std::endl;
    file.close();
}