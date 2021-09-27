#include "HighSchoolStudent.h"
#include <iostream>
#include <fstream>

HighSchoolStudent::HighSchoolStudent(std::string name, std::string id, std::string essay, std::vector <std::string> errorList, std::string nameOfSchool)
: Student(name, id, essay, errorList)
{
    this->nameOfSchool = nameOfSchool;
}

HighSchoolStudent::~HighSchoolStudent()
{
}

std::string HighSchoolStudent::getSchoolName()
{
    return nameOfSchool;
}
void HighSchoolStudent::setSchoolName(std::string schoolName)
{
    nameOfSchool = schoolName;
}
void HighSchoolStudent::writeToFile()
{
    std::string fileName = id + "_graded.txt";
    std::ofstream file(fileName);
    if (file.is_open())
    {
        file << "High School Student " + name + "\n";
        file << "Student ID: " + id + "\n";
        file << "School Name: " + nameOfSchool + "\n";
        file << getPrintableErrorList();
    }
    else
        std::cout << "Cannot write to file." << std::endl;
    file.close();
}