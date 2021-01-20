#include "Account.h"

void helper_swap(Transaction *xp, Transaction *yp)
{
    Transaction temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void helper_bubblesort(Transaction arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                helper_swap(&arr[j], &arr[j + 1]);
}

Account::Account()
{
    this->_id = 0;
    this->_activity = nullptr;
    this->_monthly_activity_frequency = nullptr;
}

Account::Account(int id, Transaction **const activity, int *monthly_activity_frequency)
{
    this->_id = id;
    this->_activity = new Transaction *[12];
    this->_monthly_activity_frequency = new int[12];

    for (int i = 0; i < 12; i++)
    {
        this->_activity[i] = nullptr;
        this->_monthly_activity_frequency[i] = 0;
    }

    //copy monthly array

    for (int i = 0; i < 12; i++)
    {
        this->_monthly_activity_frequency[i] = monthly_activity_frequency[i];
    }

    for (int i = 0; i < 12; i++)
    {
        int temp = 0;
        temp = this->_monthly_activity_frequency[i];

        if (temp == 0)
        {
            this->_activity[i] = nullptr;
        }
        else
        {
            this->_activity[i] = new Transaction[temp];
            for (int j = 0; j < temp; j++)
            {
                this->_activity[i][j] = activity[i][j];
            }
        }
    }

    //sorting
    for (int i = 0; i < 12; i++)
    {
        if (this->_activity[i] != nullptr)
        {
            int temp = 0;
            temp = _monthly_activity_frequency[i];

            helper_bubblesort(_activity[i], temp);
        }
    }
}

Account::~Account()
{

    this->_id = -1;
    if (this->_activity != nullptr)
        for (int i = 0; i < 12; i++)
            delete[] this->_activity[i];

    delete[] this->_activity;
    delete[] this->_monthly_activity_frequency;
}

Account::Account(const Account &rhs)
{
    this->_id = rhs._id;
    this->_activity = new Transaction *[12];
    this->_monthly_activity_frequency = new int[12];

    for (int i = 0; i < 12; i++)
    {
        this->_monthly_activity_frequency[i] = rhs._monthly_activity_frequency[i];
    }

    for (int i = 0; i < 12; i++)
    {
        int temp = 0;
        temp = _monthly_activity_frequency[i];

        if (temp == 0)
        {
            this->_activity[i] = nullptr;
        }
        else
        {
            this->_activity[i] = new Transaction[temp];
            for (int j = 0; j < temp; j++)
            {
                this->_activity[i][j] = rhs._activity[i][j];
            }
        }
    }

    for (int i = 0; i < 12; i++)
    {
        if (this->_activity[i] != nullptr)
        {
            int temp = 0;
            temp = _monthly_activity_frequency[i];
            helper_bubblesort(_activity[i], temp);
        }
    }
}

Account::Account(const Account &rhs, time_t start_date, time_t end_date)
{
    this->_id = rhs._id;
    this->_activity = new Transaction *[12];
    this->_monthly_activity_frequency = new int[12];

    for (int i = 0; i < 12; i++)
    {
        this->_activity[i] = nullptr;
        this->_monthly_activity_frequency[i] = 0;
    }

    int start_month = 0, end_month = 0, temp_arr = 0;
    tm *temp;
    temp = localtime(&start_date);
    start_month = temp->tm_mon;
    temp = localtime(&end_date);
    end_month = temp->tm_mon;

    //TODO: fill monthly_activity array but how?

    for (int i = start_month; i <= end_month; i++)
    {
        int count = 0;
        temp_arr = rhs._monthly_activity_frequency[i];
        for (int j = 0; j < temp_arr; j++)
        {
            if (rhs._activity[i][j] > start_date && rhs._activity[i][j] < end_date)
            {
                count++;
            }
        }
        this->_monthly_activity_frequency[i] = count;
    }

    for (int i = start_month; i <= end_month; i++)
    {
        int rhs_temp = 0, tr_temp = 0, flag = 0;
        rhs_temp = rhs._monthly_activity_frequency[i];
        tr_temp = this->_monthly_activity_frequency[i];

        if (tr_temp >= 0)
        {
            /* code */

            this->_activity[i] = new Transaction[tr_temp];

            for (int j = 0; j < rhs_temp; j++)
            {
                if (rhs._activity[i][j] > start_date && rhs._activity[i][j] < end_date)
                {

                    this->_activity[i][flag] = rhs._activity[i][j];
                    flag++;
                }
            }
        }
        else
        {
            this->_activity[i] = nullptr;
        }
    }
}

Account::Account(Account &&rhs)
{


    this->_id = rhs._id;

    this->_activity = rhs._activity;

    this->_monthly_activity_frequency = rhs._monthly_activity_frequency;

    rhs._id = -1;
    rhs._activity = nullptr;

    rhs._monthly_activity_frequency = nullptr;
}

Account &Account::operator=(Account &&rhs)
{
    if (this != &rhs)
    {
        if (this->_activity != nullptr)
            for (int i = 0; i < 12; i++)
                delete[] this->_activity[i];

        delete[] this->_activity;
        delete[] this->_monthly_activity_frequency;

        this->_id = rhs._id;
        this->_activity = rhs._activity;
        this->_monthly_activity_frequency = rhs._monthly_activity_frequency;

        rhs._id = -1;
        rhs._activity = nullptr;

        rhs._monthly_activity_frequency = nullptr;
    }

    return *this;
}

Account &Account::operator=(const Account &rhs)
{
    //deeep copy

    if (this != &rhs)
    {
       if (this->_activity!=nullptr)
       {
        for (int i = 0; i < 12; i++)
        {
            delete[] this->_activity[i];
            /* code */
        }
        delete[] this->_activity;
        delete[] this->_monthly_activity_frequency;
           /* code */
       }
        

        this->_id = rhs._id;
        this->_activity = new Transaction *[12];
        this->_monthly_activity_frequency = new int[12];

        for (int i = 0; i < 12; i++)
        {
            this->_activity[i] = nullptr;
            this->_monthly_activity_frequency[i] = rhs._monthly_activity_frequency[i];
        }

        for (int i = 0; i < 12; i++)
        {
            int temp = 0;
            temp = this->_monthly_activity_frequency[i];

            if (temp == 0)
            {
                this->_activity[i] = nullptr;
            }
            else
            {
                this->_activity[i] = new Transaction[temp];

                for (int j = 0; j < temp; j++)
                {
                    this->_activity[i][j] = rhs._activity[i][j];
                }
            }
        }
    }
    return *this;
}

bool Account::operator==(const Account &rhs) const
{
    // std::cout<<"id: "<<rhs._id<<std::endl;

    return (this->_id == rhs._id) ? true : false;
}

bool Account::operator==(int id) const
{
    // std::cout<<"id: "<<id<<std::endl;
   return (this->_id == id) ? true : false;
}

Account &Account::operator+=(const Account &rhs)
{

    for (int t = 0; t < 12; t++)
    {
        Transaction *temp;
        int rhsize = 0, thisize = 0, newsize = 0;
        rhsize = rhs._monthly_activity_frequency[t];
        thisize = this->_monthly_activity_frequency[t];
        // std::cout<<" this month: "<<thisize<<" rhs month: "<<rhsize<< std::endl;
        newsize = rhsize + thisize;
        // std::cout<<"new sizez: "<<newsize<<std::endl;
        if ((thisize > 0 && rhsize > 0) || (thisize <= 0 && rhsize > 0))
        {
            temp = new Transaction[newsize];
            for (int i = 0, j = 0, k = 0; i < newsize, j < thisize, k < (rhsize); i++)
            {
                if (this->_activity[t] != nullptr)
                {
                    if (i >= thisize)
                        temp[i] = rhs._activity[t][k++];
                    else
                        temp[i] = this->_activity[t][j++];
                }
                else
                    temp[i] = rhs._activity[t][k++];
            }

            if (this->_activity[t] != nullptr)
            {
                delete[] this->_activity[t];
                this->_activity[t] = temp;
                this->_monthly_activity_frequency[t] = newsize;
            }
            else
            {
                this->_activity[t] = temp;
                this->_monthly_activity_frequency[t] = newsize;
            }
        }
    }

    for (int i = 0; i < 12; i++)
    {
        if (this->_activity[i] != nullptr)
        {
            int temp = 0;
            temp = _monthly_activity_frequency[i];

            helper_bubblesort(_activity[i], temp);
        }
    }

    return *this;
}

double Account::balance()
{
    double total = 0.0;
    for (int i = 0; i < 12; i++)
    {
        if (this->_activity[i] != nullptr)
        {
            int temp = 0;
            temp = this->_monthly_activity_frequency[i];

            for (int j = 0; j < temp; j++)
            {
                total = (this->_activity[i][j]) + total;
            }
        }
    }
    return total;
}

double Account::balance(time_t end_date)
{
    double total = 0.0;
    for (int i = 0; i < 12; i++)
    {
        if (this->_activity[i] != nullptr)
        {
            int temp = 0;
            temp = this->_monthly_activity_frequency[i];

            for (int j = 0; j < temp; j++)
            {
                if (this->_activity[i][j] < end_date)
                {
                    total = (this->_activity[i][j]) + total;
                }
            }
        }
    }
    return total;
}

double Account::balance(time_t start_date, time_t end_date)
{
    double total = 0.0;
    for (int i = 0; i < 12; i++)
    {
        if (this->_activity[i] != nullptr)
        {
            int temp = 0;
            temp = this->_monthly_activity_frequency[i];

            for (int j = 0; j < temp; j++)
            {
                if (this->_activity[i][j] > start_date && this->_activity[i][j] < end_date)
                {
                    total = (this->_activity[i][j]) + total;
                }
            }
        }
    }
    return total;
}

std::ostream &operator<<(std::ostream &os, const Account &account)
{

    if (account._activity == nullptr || account._monthly_activity_frequency == nullptr)
    {
        os << -1<<std::endl;
    }
    else
    {

        os << account._id << std::endl;

        for (int i = 0; i < 12; i++)
        {
            if (account._activity[i] != nullptr)
            {
                int temp = 0;
                temp = account._monthly_activity_frequency[i];

                if (temp != 0)
                {

                    for (int j = 0; j < temp; j++)
                    {
                        os << account._activity[i][j];
                    }
                    /* code */
                }
                /* code */
            }
        }

        return os;
        /* code */
    }
}
