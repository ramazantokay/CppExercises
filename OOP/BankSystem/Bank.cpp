#include "Bank.h"

Bank::Bank()
{
    this->_bank_name = "not_defined";
    this->_user_count = 0;
    this->_users = nullptr;
}

Bank::Bank(std::string bank_name, Account *const users, int user_count)
{
    this->_bank_name = bank_name;
    this->_user_count = user_count;

    this->_users = new Account[user_count];
    for (int i = 0; i < user_count; i++)
    {
        this->_users[i] = users[i];
    }
}

Bank::~Bank()
{
    this->_bank_name = "not_defined";
    this->_user_count = 0;
    delete[] this->_users;
}


Bank::Bank(const Bank& rhs)
{
    int size = rhs._user_count;
    this->_bank_name = rhs._bank_name;
    this->_user_count = rhs._user_count;

    this->_users = new Account[size];

    for (int i = 0; i < size; i++)
    {
        this->_users[i]= rhs._users[i];
    }
    
}

Bank& Bank::operator+=(const Bank& rhs)
{
    int thisize = this->_user_count, rhsize = rhs._user_count;
    Account *temp;

    for (int i = 0; i < rhsize; i++)
    {
        bool flag = false;
        for (int j = 0; j < thisize; j++)
        {
            if ( (rhs._users[i] == this->_users[j]) )
            {
                this->_users[j] += rhs._users[i];
                flag = true;
                break;
            }
        }
   
        if (!flag)
        {
            temp = new Account[thisize + 1];
            for (int i = 0; i < thisize; i++)
            {
                temp[i] = this->_users[i];
            }
            temp[thisize++]=rhs._users[i];
            delete[] this->_users;
            this->_users = temp;
            this->_user_count++;
        }
    }
    return *this;
}


Bank& Bank::operator+=(const Account& new_acc)
{
    bool flag = false; 
    int curr_size = this->_user_count, flag2=0;
    Account *temp;
    for (int i = 0; i < curr_size; i++)
    {
        if (this->_users[i] == new_acc)
        {
           flag=true;
           flag2=i;
           break;
        }
        
    }
    if (flag)
    {
        this->_users[flag2] += new_acc;
    }

    else
    {

        temp = new Account[curr_size + 1];
        for (int i = 0; i < curr_size; i++)
        {
            temp[i] = this->_users[i];
        }
        temp[curr_size] = new_acc;
        
        delete[] this->_users;
        this->_users = temp;
        this->_user_count++;
    }

    return *this;
}

Account& Bank::operator[](int account_id)
{
    bool flag=false;
    int count = this->_user_count, flag2=0;
 
    for (int i = 0; i < count; i++)
    {
        if (this->_users[i]==account_id)
        {
            flag = true;
            flag2=i;
            break;
        }
    }
    return flag ? this->_users[flag2] : this->_users[0];
}

std::ostream& operator<<(std::ostream& os, const Bank& bank)
{
    int total_acc = bank._user_count, flag=bank._user_count;
    double total_balance = 0.0;
    int temparr[12];
    

    for (int j = 0; j < total_acc; j++)
    {
        for (int i = 0; i < 12; i++)
        {
            struct tm start = {0};
            start.tm_mday = 0;
            start.tm_mon = i;
            start.tm_year = 119;

            struct tm end = {0};
            end.tm_mday = 31;
            end.tm_mon = i;
            end.tm_year = 119;

            time_t start_date = mktime(&start);
            time_t end_date = mktime(&end);

            temparr[i]=  bank._users[j].balance(start_date,end_date);
        }

        for (int i = 0; i < 11; i++)
        {
            if ((temparr[i]<0) && (temparr[i+1])<0)
            {
                flag--;
                break;
            }
        }
    }
    for (int i = 0; i < total_acc; i++)
    {
            total_balance = bank._users[i].balance() + total_balance;
    }
    os<<bank._bank_name<<'\t'<<flag<<'\t'<<total_balance<<std::endl;
}