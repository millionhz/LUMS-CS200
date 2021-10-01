#include <iostream>
#include <string>

#define CLS system("CLS");

using namespace std;

class BankAccount
{
public:
    BankAccount()
    {
        setDefault();
    }

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
        setDefault();
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

    bool changeToCurrent()
    {
        is_current = true;
        return ensureMinBalanceReq();
    }

    bool changeToBasic()
    {
        is_current = false;
        return true;
    }

    int getBalance()
    {
        return balance;
    }

    bool getIsCurrent()
    {
        return is_current;
    }

    string getName()
    {
        return firstname + " " + lastname;
    }

    int getAccountID()
    {
        return account_id;
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

    bool ensureMinBalanceReq()
    {
        if ((balance < 50000) && (is_current))
        {
            is_current = false;
            return false;
        }
        else
        {
            return true;
        }
    }

    void setDefault()
    {
        firstname = "";
        lastname = "";
        is_current = false;
        account_id = -1;
        balance = 0;
    }
};

void delBank(BankAccount *arr)
{
    delete[] arr;
}

void printMainScreen()
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
}

char getOption()
{
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
        else if (input == '0')
            return '0';
        else
        {
            cout << "Invalid Input!" << endl;
            string _s;
            getline(cin, _s);
            cin.clear();
        }
    }
}

int getCustomerIndex(BankAccount *customers, int N, int account_id)
{
    for (int i = 0; i < N; i++)
    {
        if (customers[i].getAccountID() == account_id)
        {
            return i;
        }
    }
    return -1;
}

int inputN()
{
    int N;
    do
    {
        cout << "Enter Max Number of Customers >> ";
        cin >> N;
    } while (N <= 0);

    return N;
}

int inputAccountID()
{
    int account_id;
    do
    {
        cout << "Enter Account ID >> ";
        cin >> account_id;
    } while (account_id < 0);

    return account_id;
}

int inputAmount()
{
    int amount;
    do
    {
        cout << "Enter Amount >> ";
        cin >> amount;
    } while (amount < 0);

    return amount;
}

string inputFirstName()
{
    string _s;
    getline(cin, _s);
    cin.clear();

    string firstname;
    cout << "Enter FirstName >> ";
    getline(cin, firstname);

    return firstname;
}

string inputLastName()
{
    string lastname;
    cout << "Enter LastName >> ";
    getline(cin, lastname);

    return lastname;
}

bool inputAccountType()
{
    int type;
    do
    {
        cout << "Enter Type To Change To (0: Basic | 1: Current) >> ";
        cin >> type;
    } while (type != 0 && type != 1);

    return (bool)type;
}

int getEmptyIndex(BankAccount *customers, int N)
{
    for (int i = 0; i < N; i++)
    {
        if (customers[i].getAccountID() == -1)
        {
            return i;
        }
    }

    return -1;
}

bool makeBankAccount(BankAccount *customers, int N)
{

    int i = getEmptyIndex(customers, N);

    if (i > -1)
    {
        string firstname = inputFirstName();
        string lastname = inputLastName();
        bool is_current = inputAccountType();
        int account_id = inputAccountID();
        int init_balance = inputAmount();
        customers[i] = BankAccount(firstname, lastname, is_current, account_id, init_balance);
        return true;
    }
    else
    {
        return false;
    }
}

int updateCurrentSize(BankAccount *customers, int N)
{
    int size = 0;
    for (int i = 0; i < N; i++)
    {
        if (customers[i].getAccountID() != -1)
        {
            size++;
        }
    }

    return size;
}

void accountDoesNotExist(int account_id)
{
    cout << "Bank Account with id: " << account_id << " does not exists" << endl;
}

int main()
{
    int N = inputN();
    int current_size = 0;

    BankAccount *customers = new BankAccount[N];

    // CLS;
    /*******************/
    while (1)
    {
        printMainScreen();
        char option = getOption();
        if (option == 'a')
        {
            if (makeBankAccount(customers, N))
            {
                current_size = updateCurrentSize(customers, N);
                cout << "Account for " << customers[current_size - 1].getName() << " was created under ID:" << customers[current_size - 1].getAccountID() << endl;
            }
            else
            {
                cout << "Max account limit reached" << endl;
            }
        }
        else if (option == 'b')
        {
            int account_id = inputAccountID();
            int i = getCustomerIndex(customers, N, account_id);

            if (i != -1)
            {
                if (customers[i].getBalance() <= 0)
                {
                    customers[i].~BankAccount();
                    customers[i] = BankAccount();
                    current_size = updateCurrentSize(customers, N);

                    cout << "Account with id:" << account_id << " deleted" << endl;
                }
                else
                {
                    cout << "Balance is > 0" << endl;
                }
            }
            else
            {
                accountDoesNotExist(account_id);
            }
        }
        else if (option == 'c')
        {
            int account_id = inputAccountID();

            int amount = inputAmount();

            int i = getCustomerIndex(customers, N, account_id);

            if (i != -1)
            {
                customers[i].deposit(amount);
                cout << "Transaction Successful for Account ID: " << account_id << ", Account Title: " << customers[i].getName() << ", New Balance: " << customers[i].getBalance() << endl;
            }
            else
            {
                accountDoesNotExist(account_id);
            }
        }
        else if (option == 'd')
        {
            int account_id = inputAccountID();

            int amount = inputAmount();

            int i = getCustomerIndex(customers, N, account_id);

            if (i != -1)
            {
                if (customers[i].getBalance() >= amount)
                {
                    customers[i].withdraw(amount);
                    cout << "Transaction Successful for Account ID: " << account_id << ", Account Title: " << customers[i].getName() << ", New Balance: " << customers[i].getBalance() << endl;
                }
                else
                {
                    cout << "Account Balance Low" << endl;
                }
            }
            else
            {
                accountDoesNotExist(account_id);
            }
        }
        else if (option == 'e')
        {

            int account_id = inputAccountID();

            bool type = inputAccountType();

            int i = getCustomerIndex(customers, N, account_id);
            if (i != -1)
            {
                if (type)
                {
                    if (customers[i].changeToCurrent())
                    {
                        cout << "Account type of ID: " << customers[i].getAccountID() << " under Title: " << customers[i].getName() << " changed to Current" << endl;
                    }
                    else
                    {
                        cout << "Balance < 50000" << endl;
                    }
                }
                else
                {
                    customers[i].changeToBasic();
                    cout << "Account type of ID: " << customers[i].getAccountID() << " under Title: " << customers[i].getName() << " changed to Basic" << endl;
                }
            }
            else
            {
                accountDoesNotExist(account_id);
            }
        }
        else if (option == 'f')
        {
            int account_id = inputAccountID();

            int i = getCustomerIndex(customers, N, account_id);

            if (i != -1)
            {
                cout << "Balance: " << customers[i].getBalance() << endl;
            }
            else
            {
                accountDoesNotExist(account_id);
            }
        }
        else if (option == 'g')
        {
            int account_id = inputAccountID();

            int i = getCustomerIndex(customers, N, account_id);

            if (i != -1)
            {
                bool is_current = customers[i].getIsCurrent();

                if (is_current)
                {
                    cout << "Current" << endl;
                }
                else
                {
                    cout << "Basic" << endl;
                }
            }
            else
            {
                accountDoesNotExist(account_id);
            }
        }
        else if (option == 'h')
        {
            int total = 0;
            for (int i = 0; i < N; i++)
            {
                total += customers[i].getBalance();
            }

            cout << "Total Balance: " << total << endl;
        }
        else if (option == 'i')
        {
            int account_id = inputAccountID();

            string firstname = inputFirstName();

            string lastname = inputLastName();

            int i = getCustomerIndex(customers, N, account_id);

            if (i != -1)
            {
                string oldname = customers[i].getName();
                customers[i].changeName(firstname, lastname);

                cout << "Name for ID: " << customers[i].getAccountID() << " changed from " << oldname << " to " << customers[i].getName() << endl;
            }
            else
            {
                accountDoesNotExist(account_id);
            }
        }
        else if (option == '0')
        {
            delBank(customers);
            return 0;
        }
        else
        {
            cout << "ELSE TRIGGERED!";
            return 0;
        }
    }
}
