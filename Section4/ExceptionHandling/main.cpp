#include <iostream>
#include <memory>
#include "Account.h"
#include "Checking_Account.h"
#include "Savings_Account.h"
#include "Trust_Account.h"
#include "Account_Util.h"

using namespace std;

int main() 
{
    // test your code here
    try
    {
        Account *act1 = new Checking_Account("Bill", 50);
        std::cout << *act1 << std::endl;
        act1->deposit(50);
        std::cout << *act1 << std::endl;
        act1->withdraw(20);
        std::cout << *act1 << std::endl;
        act1->withdraw(80);
    }
    catch(IllegalBalanceException &e)
    {
        std::cerr << e.what() << std::endl;
    }
    catch(InsufficentFundsException &e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "Program completed successfully" << std::endl;
    return 0;
}