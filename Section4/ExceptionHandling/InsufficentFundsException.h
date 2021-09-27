#ifndef INSUFFICENTFUNDSEXCEPTION_H
#define INSUFFICENTFUNDSEXCEPTION_H

class InsufficentFundsException: public std::exception
{
public:
    InsufficentFundsException() noexcept = default;
    ~InsufficentFundsException() = default;
    virtual const char* what() const noexcept {return "InsufficentFundsException";}
};

#endif // INSUFFICENTFUNDSEXCEPTION_H
