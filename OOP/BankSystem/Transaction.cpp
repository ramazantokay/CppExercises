#include "Transaction.h"

Transaction::Transaction()
{
    _amount = -1;
    _date = -1;
}

Transaction::Transaction(double amount, time_t date)
{
    _amount = amount;
    _date = date;
}

Transaction::Transaction(const Transaction &rhs)
{
    _amount = rhs._amount;
    _date = rhs._date;
}

bool Transaction::operator<(const Transaction &rhs) const
{
    if (_date < rhs._date)
        return true;
    else
        return false;
}

bool Transaction::operator>(const Transaction &rhs) const
{
    if (_date > rhs._date)
        return true;
    else
        return false;
}

bool Transaction::operator<(const time_t date) const
{
    if (_date < date)
        return true;
    else
        return false;
}

bool Transaction::operator>(const time_t date) const
{
    if (_date > date)
        return true;
    else
        return false;
}

double Transaction::operator+(const Transaction &rhs)
{
    return _amount + rhs._amount;
}

double Transaction::operator+(const double add)
{
    return _amount + add;
}

Transaction &Transaction::operator=(const Transaction &rhs)
{
    if (this != &rhs)
    {
        _date = rhs._date;
        _amount = rhs._amount;
    }
    return *this;
}

std::ostream &operator<<(std::ostream &os, const Transaction &transaction)
{
    struct tm *newtm = localtime(&transaction._date);
    os << transaction._amount <<'\t'<<"-"<<'\t'<< ((newtm->tm_hour) ) << ":" << (newtm->tm_min) << ":" << (newtm->tm_sec) << "-" << (newtm->tm_mday) << "/" << (newtm->tm_mon) + 1 << "/" << (newtm->tm_year) + 1900 << std::endl;
    return os;
}