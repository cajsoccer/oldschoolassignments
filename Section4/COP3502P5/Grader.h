#ifndef GRADER_H
#define GRADER_H
#include <Student.h>
#include <HighSchoolStudent.h>
#include <UndergraduateStudent.h>
#include <GraduateStudent.h>
#include <Dictionary.h>

class Grader
{
private:
    bool available;
    Student* student;
    Dictionary dict;
public:
    Grader(Dictionary dict);
    ~Grader();
    bool gradeStudent(std::string fileName);
    bool isAvailable();
    Student* getStudent();
    void reset();
};

#endif // GRADER_H
