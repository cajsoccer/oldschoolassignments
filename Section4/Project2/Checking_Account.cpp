#include "Checking_Account.h"

Checking_Account::Checking_Account(std::string name, double balance, double fee)
    : Account {name, balance}, fee{fee} {
}

// Deposit:
//      Amount supplied to deposit will be incremented by (amount * int_rate/100) 
//      and then the updated amount will be deposited
//
bool Checking_Account::withdraw(double amount) 
{
    amount += fee; 
    return Account::withdraw(amount);
}

std::ostream &operator<<(std::ostream &os, const Checking_Account &account) {
    os << "[Checking_Account: " << account.name << ": " << account.balance << ", " << account.fee << "%]";
    return os;
}
