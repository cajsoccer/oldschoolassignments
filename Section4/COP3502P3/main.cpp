#include <iostream>
#include <math.h>

void printConversionTable();
int mainMenuOptionSelector();
double convertCurrency(const double &amount, const int &currType, const bool &isConvertToUSD);
bool deposit(const double &amount, const int &currType, double &balance);
bool withdraw(const double &amount, const int &currType, double &balance);
std::string logTransaction(const double &amount, const int &currType, const bool &isDeposit);
void printCurrTypes();

int main()
{
    double balance = 0;
    std::cout << "Welcome to Currency Exchange 2.0" << std::endl << std::endl;
    printConversionTable();
    int choice = 0;
    while (choice != 4)
    {
        double amount = 0;
        int currType = 0;
        choice = mainMenuOptionSelector();
        if (choice == 1)
            std::cout << "Your current account balance in USD is: " << balance << std::endl << std::endl;
        else if (choice == 2)
        {
            printCurrTypes();
            std::cin >> currType;
            while (currType < 1 || currType > 11)
            {
                std::cout << "Invalid input. Try again." << std::endl;
                printCurrTypes();
                std::cin >> currType;
            }
            std::cout << "Enter an amount to deposit:" << std::endl;
            std::cin >> amount;
            if (deposit(amount, currType, balance))
                std::cout << logTransaction(amount, currType, true) << std::endl;
            else
                std::cout << "Deposit failed." << std::endl;
        }
        else if (choice == 3)
        {
            printCurrTypes();
            std::cin >> currType;
            while (currType < 1 || currType > 11)
            {
                std::cout << "Invalid input. Try again." << std::endl;
                printCurrTypes();
                std::cin >> currType;
            }
            std::cout << "Enter an amount to withdraw:" << std::endl;
            std::cin >> amount;
            if (withdraw(amount, currType, balance))
                std::cout << logTransaction(amount, currType, false) << std::endl;
            else
                std::cout << "Withdraw failed." << std::endl;
        }
        else if (choice == 4)
        {
            double finalBal = balance;
            withdraw(finalBal, 1, balance);
            std::cout << logTransaction(finalBal, 1, false) << std::endl;
            std::cout << "Goodbye." << std::endl;
        }
    }
    return 0;
}

void printConversionTable()
{
    std::cout << "Current rates are as follows:" << std::endl << std::endl;
    std::cout << "1 - U.S. Dollar - 1.00" << std::endl;
    std::cout << "2 - Euro - 0.89" << std::endl;
    std::cout << "3 - Pound Sterling - 0.78" << std::endl;
    std::cout << "4 - Hindustani Rupee - 66.53" << std::endl;
    std::cout << "5 - Australian Dollar - 1.31" << std::endl;
    std::cout << "6 - Canadian Dollar - 1.31" << std::endl;
    std::cout << "7 - Singapore Dollar - 1.37" << std::endl;
    std::cout << "8 - Swiss Franc - 0.97" << std::endl;
    std::cout << "9 - Malayan Ringgit - 4.12" << std::endl;
    std::cout << "10 - Yen - 101.64" << std::endl;
    std::cout << "11 - Yuan - 6.67" << std::endl << std::endl;
}

int mainMenuOptionSelector()
{
    int selection = 0;
    std::cout << "Please select an option from the list below:" << std::endl;
    std::cout << "1. Check the balance of your account" << std::endl;
    std::cout << "2. Make a deposit" << std::endl;
    std::cout << "3. Withdraw an amount in a specific currency" << std::endl;
    std::cout << "4. End your session (and withdraw all remaining currency in U.S. Dollars)" << std::endl;
    std::cin >> selection;
    std::cout << std::endl;
    while (selection < 1 || selection > 4)
    {
        std::cout << "Invalid selection. Try again:";
        std::cin >> selection;
    }
    return selection;
}

double convertCurrency(const double &amount, const int &currType, const bool &isConvertToUSD)
{
    double scale = 0;
    double val = 0;
    if (currType == 1)
        scale = 1;
    else if (currType == 2)
        scale = 0.89;
    else if (currType == 3)
        scale = 0.78;
    else if (currType == 4)
        scale = 66.53;
    else if (currType == 5)
        scale = 1.31;
    else if (currType == 6)
        scale = 1.31;
    else if (currType == 7)
        scale = 1.37;
    else if (currType == 8)
        scale = 0.97;
    else if (currType == 9)
        scale = 4.12;
    else if (currType == 10)
        scale = 101.64;
    else if (currType == 11)
        scale = 6.67;
    if (isConvertToUSD)
        val = amount / scale;
    else 
        val = amount * scale;
    return val;
}

bool deposit(const double &amount, const int &currType, double &balance)
{
    if (amount <= 0 || currType == 0)
        return false;
    else
    {
        double dollarAmount = convertCurrency(amount, currType, true);
        balance += dollarAmount;
        return true;
    }
}

bool withdraw(const double &amount, const int &currType, double &balance)
{
    double dollarAmount = convertCurrency(amount, currType, true);
    if (currType != 1)
        dollarAmount += dollarAmount * 0.005;
    if (amount <= 0 || currType == 0 || dollarAmount > balance)
        return false;
    else
    {
        balance -= dollarAmount;
        return true;
    }
}

std::string logTransaction(const double &amount, const int &currType, const bool &isDeposit)
{
    std::string stringType = "";
    if (currType == 1)
        stringType = "US Dollars";
    else if (currType == 2)
        stringType = "Euros";
    else if (currType == 3)
        stringType = "Pounds Sterling";
    else if (currType == 4)
        stringType = "Hindustani Rupees";
    else if (currType == 5)
        stringType = "Australian Dollars";
    else if (currType == 6)
        stringType = "Australian Dollars";
    else if (currType == 7)
        stringType = "Singaporian Dollar";
    else if (currType == 8)
        stringType = "Swiss Francs";
    else if (currType == 9)
        stringType = "Malayan Ringgit";
    else if (currType == 10)
        stringType = "Yen";
    else if (currType == 11)
        stringType = "Yuan";
    if (isDeposit)
        return "You sucessfully deposited " + std::to_string(amount) + " " + stringType + ".";
    else
        return "You sucessfully withdrew " + std::to_string(amount) + " " + stringType + ".";
}

void printCurrTypes()
{
    std::cout << "Please select the currency type:" << std::endl;
    std::cout << "1. US Dollars" << std::endl;
    std::cout << "2. Euros" << std::endl;
    std::cout << "3. Pounds Sterling" << std::endl;
    std::cout << "4. Hindustani Rupees" << std::endl;
    std::cout << "5. Australian Dollars" << std::endl;
    std::cout << "6. Canadian Dollars" << std::endl;
    std::cout << "7. Singaporian Dollars" << std::endl;
    std::cout << "8. Swiss Francs" << std::endl;
    std::cout << "9. Malaysian Ringgits" << std::endl;
    std::cout << "10. Japanese Yen" << std::endl;
    std::cout << "11. Chinese Yuan" << std::endl;
}