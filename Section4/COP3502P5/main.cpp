#include <iostream>
#include <Student.h>
#include <HighSchoolStudent.h>
#include <GraduateStudent.h>
#include <UndergraduateStudent.h>
#include <Dictionary.h>
#include <Grader.h>

int main()
{
    std::string dictName = "";
    std::cout << "Please specify the file name (without extension) of the dictionary: ";
    std::cin >> dictName;
    dictName = dictName + ".txt";
    Dictionary dict;
    bool dictLoaded = dict.loadDictionaryFromFile(dictName);
    while (!dictLoaded)
    {
        std::cout << "Failed to load dictionary please try again.\nPlease specify the file name (without extension) of the dictionary: " << std::endl;
        std::cin >> dictName;
        dictName = dictName + ".txt";
        dictLoaded = dict.loadDictionaryFromFile(dictName);
    }
    std::cout << "Dictionary sucessfully loaded." << std::endl;
    Grader grader(dict);
    std::string idInput = "";
    while (idInput != "exit")
    {
        std::cout << "Enter the id of the student to grade: "; 
        std::cin >> idInput;
        std::string idInputTxt = idInput + ".txt";
        bool canGrade = grader.gradeStudent(idInputTxt);
        if (!canGrade && idInput != "exit")
        {
            std::cout << "Grading student " + idInput + " failed. Please try another one." << std::endl;
            continue;
        }
        if (canGrade)
        {
        grader.getStudent()->getPrintableErrorList();
        grader.getStudent()->writeToFile();
        std::cout << "Student " + idInput + " has been graded successfully graded." << std::endl;
        }
    }
    return 0;
}