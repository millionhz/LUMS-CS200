#include <iostream>

using namespace std;

class BankAccount
{
public:
    BankAccount(string _firstname, string _lastname, bool _is_current, int _account_id, int _init_balance)
    {
        firstname = _firstname;
        lastname = _lastname;
        is_current = _is_current;
        account_id = _account_id;
        balance = _init_balance;
        ensureMinBalanceReq();
    }

    ~BankAccount()
    {
        firstname = "";
        lastname = "";
        is_current = false;
        account_id = -1;
        balance = 0;
    }

    void deposit(int _amount)
    {
        balance += abs(_amount);
    }
    void withdraw(int _amount)
    {
        if (_amount <= balance)
        {
            balance -= abs(_amount);
            ensureMinBalanceReq();
        }
    }

    void changeToCurrent()
    {
        is_current = true;
        ensureMinBalanceReq();
    }

    void changeToBasic()
    {
        is_current = false;
    }

    int getBalance()
    {
        return balance;
    }

    bool getIsCurrent()
    {
        return is_current;
    }

    string changeName(string _firstname, string _lastname)
    {
        firstname = _firstname;
        lastname = _lastname;
    }

private:
    string firstname;
    string lastname;
    bool is_current;
    int account_id;
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
    //TODO: USE CLASS

    // TODO: Bank assets
    return 0;
}
