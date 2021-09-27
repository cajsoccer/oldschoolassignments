#include <iostream>
#include "Mystring.h"

int main()
{
    Mystring s1("bitch");
    Mystring s2("boy");
    Mystring s3 = s2 * 5;
    Mystring s4 = s1;
    s4 *= 6;
    s3.display();
    s4.display();
    return 0;
}