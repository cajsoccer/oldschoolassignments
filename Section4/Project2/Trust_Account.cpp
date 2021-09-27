#include "Trust_Account.h"

Trust_Account::Trust_Account(std::string name, double balance, double bonus)
    : Account {name, balance}, bonus{bonus}, with_allow{3} {
}

// Deposit:
//      Amount supplied to deposit will be incremented by (amount * int_rate/100) 
//      and then the updated amount will be deposited
//
bool Trust_Account::deposit(double amount) 
{
    if (amount > 5000)
        amount += bonus;
    return Account::deposit(amount);
}

bool Trust_Account::withdraw(double amount)
{
    if (amount < balance*0.2 && with_allow > 0)
    {
        with_allow--;
        return Account::withdraw(amount);
    }
    else
        return false;
}

std::ostream &operator<<(std::ostream &os, const Trust_Account &account) {
    os << "[Trust_Account: " << account.name << ": " << account.balance << ", " << account.bonus << " bonus] " << account.with_allow << " withdraw amounts remaining";
    return os;
}

