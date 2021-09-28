#include <iostream>
using namespace std;

class BankAccount
{
public:
    BankAccount(string _firstname, string _secondname, int _account_number, bool _is_current, int _balance)
    {
        first_name = _firstname;
        second_name = _secondname;
        account_number = _account_number;
        balance = _balance;
        is_current = _is_current;
        ensureMinBalanceReq();
    }

    void deposit(int _amount)
    {
        balance += abs(_amount);
    }

    void withdraw(int _amount)
    {
        balance -= abs(_amount);
        ensureMinBalanceReq();
    }

    void changeToCurrent()
    {
        is_current = true;
        ensureMinBalanceReq();
    }

    void changeName(string _firstname, string _second_name)
    {
        first_name = _firstname;
        second_name = _second_name;
    }

    string getFirstName()
    {
        return first_name;
    }

    string getLastName()
    {
        return second_name;
    }

    int getBalance()
    {
        return balance;
    }

    int getAccountNumber()
    {
        return account_number;
    }

    string getAccountType()
    {
        return is_current ? "Current" : "Basic";
    }

private:
    string first_name;
    string second_name;
    int account_number;
    bool is_current;
    int balance;

    void ensureMinBalanceReq()
    {
        if ((balance < 50000) && (is_current))
        {
            is_current = false;
        }
    }
};

int main()
{
    return 0;
}