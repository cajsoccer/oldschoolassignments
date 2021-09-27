#include <iostream>
#include <string> 
#include <ctime>
#define _USE_MATH_DEFINES
#include <cmath>

int main()
{
    std::cout << "Shape Machine login" << std::endl;
    std::time_t t = std::time(0);
    std::tm *now = std::localtime(&t);
    int actDay = now->tm_mday;
    int actMonth = now->tm_mon + 1;
    int actYear = now->tm_year + 1900;
    bool loginSuccess = false;
    int attemptCount = 1;
    while (!loginSuccess)
    {
        if (attemptCount == 4)
        {
            std::cout << "Terminating program." << std::endl;
            exit(0);
        }
        int day, month, year = 0;
        std::cout << "What is today's day?:";
        std::cin >> day;
        if (day < 1 || day > 31 || day != actDay)
        {
            std::cout << "#ERROR Login attempt #[" << attemptCount << "]. Invalid input. Please try again." << std::endl;
            attemptCount++;
            continue;
        }
        std::cout << "What is today's month?:";
        std::cin >> month;
        if (month < 1 || month > 12 || month != actMonth)
        {
            std::cout << "#ERROR Login attempt #[" << attemptCount << "]. Invalid input. Please try again." << std::endl;
            attemptCount++;
            continue;
        }
        std::cout << "What is today's year?:";
        std::cin >> year;
        if (year != actYear)
        {
            std::cout << "#ERROR Login attempt #[" << attemptCount << "]. Invalid input. Please try again." << std::endl;
            attemptCount++;
            continue;
        }
        std::cout << "Correct date. Welcome!" << std::endl;
        loginSuccess = true;
    }
    std::string input = "";
    bool loopInput = true;
    while (loopInput)
    {
        std::cout << "---Welcome to the Shape Machine---\nAvailable Options:\nCircles\nRectangles\nTriangles\nExit" << std::endl;
        std::cin >> input;
        if (input == "Circles")
        {
            double r = 0;
            std::cout << "Circles selected. Please enter the radius:";
            std::cin >> r;
            while (r <= 0)
            {
                std::cout << "#ERROR Negative input. Please input the radius again:";
                std::cin >> r;
            }
            double area = M_PI*pow(r,2);
            double circumference = 2*M_PI*r;
            std::string areaS = std::to_string(area);
            int areaDig = areaS.length() - 1;
            std::string circumS = std::to_string(circumference);
            int circumDig = circumS.length() - 1;
            std::cout << "The area is: " << area << std::endl;
            std::cout << "The circumference is: " << circumference << std::endl;
            std::cout << "The number of digits in the area is: " << areaDig << std::endl;
            std::cout << "The number of digits in the circumference is: " << circumDig << std::endl;
        }
        else if (input == "Rectangles")
        {
            double x, y = 0;
            std::cout << "Rectangles selected. Please enter the 2 sides:";
            std::cin >> x >> y;
            while (x <= 0 || y <= 0)
            {
                std::cout << "#ERROR Negative input. Please input the 2 sides again:";
                std::cin >> x >> y;
            }
            double area = x * y;
            double perimeter = 2*(x + y);
            std::string areaS = std::to_string(area);
            int areaDig = areaS.length() - 1;
            std::string perimeterS = std::to_string(perimeter);
            int perimeterDig = perimeterS.length() - 1;
            std::cout << "The area is: " << area << std::endl;
            std::cout << "The perimeter is: " << perimeter << std::endl;
            std::cout << "The number of digits in the area is: " << areaDig << std::endl;
            std::cout << "The number of digits in the perimeter is: " << perimeterDig << std::endl;
        }
        else if (input == "Triangles")
        {
            double x, y, z = 0;
            std::cout << "Triangles selected. Please enter the 3 sides:";
            std::cin >> x >> y >> z;
            while (x <= 0 || y <= 0 || z <= 0)
            {
                std::cout << "#ERROR Negative input. Please input the 3 sides again:";
                std::cin >> x >> y >> z;
            }
            bool valid = x + y > z && x + z > y && y + z > x;
            if (!valid)
            {
                std::cout << "#ERROR Invalid triangle. Returning to the menu." << std::endl;
                continue;
            }
            std::string type = "";
            if ( x == y && y == z)
                type = "Equilateral";
            else if ((x == y && x != z) || (x == z && x != y))
                type = "Isosceles";
            else
                type = "Scalene";
            double s = (x + y + z)/2;
            double area = sqrt(s*(s-x)*(s-y)*(s-z));
            double perimeter = x + y + z;
            std::string areaS = std::to_string(area);
            int areaDig = areaS.length() - 1;
            std::string perimeterS = std::to_string(perimeter);
            int perimeterDig = perimeterS.length() - 1;
            std::cout << "The type of triangle is: " << type << std::endl;
            std::cout << "The area is: " << area << std::endl;
            std::cout << "The perimeter is: " << perimeter << std::endl;
            std::cout << "The number of digits in the area is: " << areaDig << std::endl;
            std::cout << "The number of digits in the perimeter is: " << perimeterDig << std::endl;
        }
        else if (input == "Exit")
        {
            std::cout << "Terminating the program. Have a nice day!" << std::endl;
            loopInput = false;
        }
        else
            std::cout << "ERROR Invalid option. Please try again." << std::endl;
    }
    return 0;
}