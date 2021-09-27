#include <iostream>
#include <cstring>
#include "Mystring.h"

 // No-args constructor
Mystring::Mystring() 
    : str{nullptr} {
    str = new char[1];
    *str = '\0';
}

// Overloaded constructor
Mystring::Mystring(const char *s) 
    : str {nullptr} {
        if (s==nullptr) {
            str = new char[1];
            *str = '\0';
        } else {
            str = new char[strlen(s)+1];
            strcpy(str, s);
        }
}

// Copy constructor
Mystring::Mystring(const Mystring &source) 
    : str{nullptr} {
        str = new char[strlen(source.str)+ 1];
        strcpy(str, source.str);
 //       std::cout << "Copy constructor used" << std::endl;

}

// Move constructor
Mystring::Mystring( Mystring &&source) 
    :str(source.str) {
        source.str = nullptr;
//        std::cout << "Move constructor used" << std::endl;
}

 // Destructor
Mystring::~Mystring() {
    delete [] str;
}

 // Copy assignment
Mystring &Mystring::operator=(const Mystring &rhs) {
//    std::cout << "Using copy assignment" << std::endl;

    if (this == &rhs) 
        return *this;
    delete [] str;
    str = new char[strlen(rhs.str) + 1];
    strcpy(str, rhs.str);
    return *this;
}

// Move assignment
Mystring &Mystring::operator=( Mystring &&rhs) {
 //   std::cout << "Using move assignment" << std::endl;
    if (this == &rhs) 
        return *this;
    delete [] str;
    str = rhs.str;
    rhs.str = nullptr;
    return *this;
}


// Display method
void Mystring::display() const {
    std::cout << str << " : " << get_length() << std::endl;
}

 // getters
 int Mystring::get_length() const { return strlen(str); }
 const char *Mystring::get_str() const { return str; }

// overloaded insertion operator
std::ostream &operator<<(std::ostream &os, const Mystring &rhs) {
    os << rhs.str;
    return os;
}

// overloaded extraction operator
std::istream &operator>>(std::istream &in, Mystring &rhs) {
    char *buff = new char[1000];
    in >> buff;
    rhs = Mystring{buff};
    delete [] buff;
    return in;
}

/*char* operator-() const
{
    int len = strlen(str) + 1;
    char* array = new char[len];
    for (int i = 0; i < len; i++)
    {
        array[i] = 
    }
}*/

bool Mystring::operator==(const Mystring &comp) const
{
    if (strcmp(str,comp.str) == 0)
        return true;
    else
        return false;
}

bool Mystring::operator!=(const Mystring &comp) const
{
    if (strcmp(str,comp.str) != 0)
        return true;
    else
        return false;
}

bool Mystring::operator<(const Mystring &comp) const
{
    if (strcmp(str, comp.str) < 0)
        return true;
    else   
        return false;
}

bool Mystring::operator>(const Mystring &comp) const
{
    if (strcmp(str, comp.str) > 0)
        return true;
    else   
        return false;
}

Mystring Mystring::operator+(const Mystring &comp) const
{
    char *buff = new char[strlen(str) + strlen(comp.str) + 1];
    strcpy(buff, str);
    strcat(buff, comp.str);
    Mystring newStr{buff};
    delete [] buff;
    return newStr;
}

void Mystring::operator+=(const Mystring &comp)
{
    char *buff = new char[strlen(str) + strlen(comp.str) + 1];
    strcpy(buff, str);
    strcat(buff, comp.str);
    delete [] str;
    str = buff;
}

Mystring Mystring::operator*(int n) const
{
    char *buff = new char[(strlen(str)*n)+1];
    strcpy(buff, str);
    for (int i = 1; i < n; i++)
    {
        strcat(buff, str);
    }
    Mystring newStr{buff};
    delete [] buff;
    return newStr;
}

void Mystring::operator*=(int n)
{
    char *buff = new char[strlen(str)*n + 1];
    strcpy(buff, str);
    for (int i = 1; i < n; i++)
    {
        strcat(buff,str);
    }
    delete [] str;
    str = buff;
}