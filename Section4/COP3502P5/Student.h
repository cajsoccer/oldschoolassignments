#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include <vector>

class Student
{
protected: 
    std::string name;
    std::string id;
    std::string essay;
    std::vector <std::string> errorList;    
public:
    Student();
    Student(std::string name, std::string id, std::string essay, std::vector <std::string> errorList);
    virtual ~Student();
    std::string getEssay();
    void setEssay(std::string essay);
    std::string getId();
    void setId(std::string id);
    std::string getName();
    void setName(std::string n);
    std::vector <std::string> getErrorList();
    void setErrorList (std::vector <std::string> errorList);
    std::string getPrintableErrorList();
    virtual void writeToFile() = 0;
};

#endif // STUDENT_H
