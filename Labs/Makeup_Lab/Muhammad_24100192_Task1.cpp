#include <iostream>
#include <string>
#include <list>

using namespace std;

string inputString()
{
    string input_string;
    cout << "Enter string >> ";
    getline(cin, input_string);

    return input_string;
}

ostream &operator<<(ostream &os, const list<string> &container)
{
    for (const string &s : container)
    {
        os << s << ", ";
    }
    os << "\b\b ";

    return os;
}

int main()
{
    list<string> container;
    unsigned short int option;

    while (1)
    {
        cout << "Select an option:" << endl;
        cout << "   1. Insert at the front of the list" << endl;
        cout << "   2. Insert at the back of the list" << endl;
        cout << "   3. End" << endl;
        cout << "Option >> ";
        cin >> option;

        cin.ignore(1000, '\n');

        if (option == 1)
        {
            string input_string = inputString();
            container.push_front(input_string);
        }
        else if (option == 2)
        {
            string input_string = inputString();
            container.push_back(input_string);
        }
        else if (option == 3)
        {
            cout << "Original Order >> " << container << endl;

            container.sort();
            cout << "Sorted Order >> " << container << endl;

            return 0;
        }
    }

    return 1;
}