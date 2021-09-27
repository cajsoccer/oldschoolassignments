#include "Grader.h"
#include <fstream>

Grader::Grader(Dictionary dict)
{
    this->dict = dict;
    available = true;
    student = nullptr;
}

Grader::~Grader()
{
    delete student;
}

bool Grader::gradeStudent(std::string fileName)
{
    std::ifstream file;
    std::string line = "";
    std::string type, name, id, school, major, advisor;
    std::string essay = "";
    std::vector <std::string> errorList;
    file.open(fileName);
    if(file.is_open())
    {
        getline(file,line);
        type = line;
        getline(file,line);
        getline(file,line);
        name = line;
        getline(file,line);
        getline(file,line);
        id = line;
        getline(file,line);
        if (type == "HighSchool Student")
        {
            getline(file,line);
            school = line;
        }
        else if (type == "Undergraduate Student")
        {
            getline(file,line);
            major = line;
        }
        else if (type == "Graduate Student")
        {
            getline(file,line);
            major = line;
            getline(file,line);
            getline(file,line);
            advisor = line;
        }
        while (!file.eof())
        {
            file >> line;
            if (!dict.isWord(line))
            {
                int wordLen = line.length();
                if (line.at(wordLen - 1) == '.' || line.at(wordLen - 1) == ',' || line.at(wordLen - 1) == '?' || line.at(wordLen - 1) == ';' || line.at(wordLen - 1) == ':')
                    line = line.substr(0, wordLen - 1);
                errorList.push_back(line);
            }
            essay.append(line);
            essay.append(" ");
        }
        file.close();
        if (type == "HighSchool Student")
            student = new HighSchoolStudent(name, id, essay, errorList, school);
        else if (type == "Undergraduate Student")
            student = new UndergraduateStudent(name, id, essay, errorList, major);
        else if (type == "Graduate Student")
            student = new GraduateStudent(name, id, essay, errorList, major, advisor);
        available = false;
        return true;
    }
    else 
        return false;
}

bool Grader::isAvailable()
{
    if (student == nullptr && available == true)
        return true;
    else 
        return false;
}

Student* Grader::getStudent()
{
    return student;
}

void Grader::reset()
{
    delete student;
    student = nullptr;
    available = true;
}