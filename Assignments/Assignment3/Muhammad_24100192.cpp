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
        UpdateAccountType();
    }

    void Deposit(int _amount)
    {
        balance += abs(_amount);
    }

    void Withdraw(int _amount)
    {
        balance -= abs(_amount);
        UpdateAccountType();
    }

    void ChangeToCurrent()
    {
        if (balance >= 5000 && !is_current)
        {
            is_current = true;
        }
    }

private:
    string first_name;
    string second_name;
    int account_number;
    bool is_current;
    int balance;

    void UpdateAccountType()
    {
        if ((balance < 50000) && (is_current))
        {
            is_current = false;
        }
    }
};

int main()
{
    BankAccount a1("Muhammad", "Hamza", 0, 1, 50000);

    return 0;
}