#ifndef UNDERGRADUATESTUDENT_H
#define UNDERGRADUATESTUDENT_H
#include <Student.h>

class UndergraduateStudent: public Student
{
private: 
    std::string major;
public:
    UndergraduateStudent(std::string name, std::string id, std::string essay, std::vector <std::string> errorList, std::string major);
    ~UndergraduateStudent();
    std::string getMajor();
    void setMajor(std::string major);
    virtual void writeToFile() override;
    
};

#endif // UNDERGRADUATESTUDENT_H
