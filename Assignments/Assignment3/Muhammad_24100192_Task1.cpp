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
    string f_name = "Taimur", l_name = "Salman";
    bool acc_type = 1;

    //As you can see here, Mr Taimur Salman apni aukaat se barh kar current account request kar rahe hain, despite his balance
    BankAccount Taimur(f_name, l_name, 23100175, acc_type, 40000);

    cout << Taimur.getAccountType() << endl; //This should give you "basic", or 1 or 0, however you've defined "basic" to exist in your class

    cout << Taimur.getBalance() << endl; //Should give you 40000
    Taimur.withdraw(10000);
    cout << Taimur.getBalance() << endl; //Should give you 30000

    Taimur.withdraw(50000);  //Should this work?
    Taimur.withdraw(-10000); //Should this work?
    Taimur.deposit(-50000);  //Should this work?

    Taimur.deposit(1000000); //stonks ^_^

    cout << Taimur.getAccountType() << endl;
    Taimur.changeToCurrent(); //You can give a parameter to this function if you want, that's up to you
    Taimur.withdraw(1020000); //stonks ^_^

    cout << Taimur.getAccountType() << endl; //Taimur is now a baray log. Current account type gang

    string secretIdentity_firstName = "Straw", secretIdentity_lastName = "berry";
    Taimur.changeName(secretIdentity_firstName, secretIdentity_lastName);

    cout << "The name is Bond, James Bond, and you are?" << endl;
    cout << "Oh me? I'm " << Taimur.getLastName() << ", " << Taimur.getFirstName() << Taimur.getLastName() << endl;

    //Flash your money to James Bond
    cout << Taimur.getBalance() << endl;

    //Give your account number to the TV ad with goku in it asking for $5 from you to save the world from Frieza
    cout << Taimur.getAccountNumber() << endl;

    return 0;
}