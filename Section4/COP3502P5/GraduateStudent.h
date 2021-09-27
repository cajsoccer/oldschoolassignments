#ifndef GRADUATESTUDENT_H
#define GRADUATESTUDENT_H
#include <Student.h>

class GraduateStudent: public Student
{
private: 
    std::string major;
    std::string advisor;
public:
    GraduateStudent(std::string name, std::string id, std::string essay, std::vector <std::string> errorList, std::string major, std::string advisor);
    ~GraduateStudent();
    std::string getMajor();
    void setMajor(std::string major);
    std::string getAdvisor();
    void setAdvisor(std::string advisor);
    virtual void writeToFile() override;
};

#endif // GRADUATESTUDENT_H
