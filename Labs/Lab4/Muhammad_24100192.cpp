#include <iostream>
#include <string>

#define CLS system("CLS");

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

    void changeName(string _firstname, string _lastname)
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

char mainScreen()
{
    cout << "Enter A to create a new bank account" << endl;
    cout << "Enter B to delete an existing bank account" << endl;
    cout << "Enter C to perform a deposit transaction" << endl;
    cout << "Enter D to perform a withdrawal transaction" << endl;
    cout << "Enter E to change account type of a customer" << endl;
    cout << "Enter F to check balance of a customer" << endl;
    cout << "Enter G to check account type of a customer" << endl;
    cout << "Enter H to check the total balance of the bank" << endl;
    cout << "Enter I to change name of a customer" << endl;
    cout << "Enter 0 to exit" << endl;

    char input;

    while (1)
    {
        cout << "Option >> ";
        cin >> input;

        if (input == 'A' || input == 'a')
            return 'a';
        else if (input == 'B' || input == 'b')
            return 'b';
        else if (input == 'C' || input == 'c')
            return 'c';
        else if (input == 'D' || input == 'd')
            return 'd';
        else if (input == 'E' || input == 'e')
            return 'e';
        else if (input == 'F' || input == 'f')
            return 'f';
        else if (input == 'G' || input == 'g')
            return 'g';
        else if (input == 'H' || input == 'h')
            return 'h';
        else if (input == 'I' || input == 'i')
            return 'i';
        else if (input == 0)
            return 0;
        else
        {
            cout << "Invalid Input!" << endl;
            string _s;
            getline(cin, _s);
            cin.clear();
        }
    }
}

int main()
{
    unsigned int N = 0;

    while (N <= 0)
    {
        cout << "Enter Max Number of Customers >> ";
        cin >> N;
    }
    // CLS;

    mainScreen();

    //TODO: USE CLASS

    // TODO: Bank assets
    return 0;
}
