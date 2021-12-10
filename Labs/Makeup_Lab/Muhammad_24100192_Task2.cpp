#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string inputString()
{
    string input_string;
    cout << "Enter string >> ";
    getline(cin, input_string);

    return input_string;
}

ostream &operator<<(ostream &os, const vector<string> &container)
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
    vector<string> container;
    unsigned short int option;

    while (1)
    {
        cout << "Select an option:" << endl;
        cout << "   1. Insert string" << endl;
        cout << "   2. End" << endl;
        cout << "Option >> ";
        cin >> option;

        cin.ignore(1000, '\n');

        if (option == 1)
        {
            string input_string = inputString();
            container.push_back(input_string);
        }
        else if (option == 2)
        {
            cout << "Original Order >> " << container << endl;

            sort(container.begin(), container.end());
            cout << "Sorted Order >> " << container << endl;

            return 0;
        }
    }

    return 1;
}