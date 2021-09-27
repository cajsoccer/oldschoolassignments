#ifndef HIGHSCHOOLSTUDENT_H
#define HIGHSCHOOLSTUDENT_H
#include <Student.h>

class HighSchoolStudent: public Student
{
private:
    std::string nameOfSchool;
public:
    HighSchoolStudent(std::string name, std::string id, std::string essay, std::vector <std::string> errorList, std::string nameOfSchool);
    ~HighSchoolStudent();
    std::string getSchoolName();
    void setSchoolName(std::string schoolName);
    virtual void writeToFile() override;
};

#endif // HIGHSCHOOLSTUDENT_H
