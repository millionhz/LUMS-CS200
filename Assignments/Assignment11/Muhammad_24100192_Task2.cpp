#include <iostream>
#include <list>

using namespace std;

int getVal(const char *prompt)
{
    int val;
    cout << "Input " << prompt << " >> ";
    cin >> val;

    return val;
}

ostream &operator<<(ostream &os, list<int> l)
{
    for (int x : l)
    {
        os << x << "->";
    }
    os << "NULL";

    return os;
}

int main()
{
    list<int> l;

    int option;

    while (1)
    {
        cout << "Select an option: " << endl;
        cout << "   1. Print size of list" << endl;
        cout << "   2. Print list" << endl;
        cout << "   3. Sort list in ascensing order" << endl;
        cout << "   4. Insert at the front of the list" << endl;
        cout << "   5. Insert at the end of the list" << endl;
        cout << "   6. Remove from the the front of the list" << endl;
        cout << "   7. Remove from the the end of the list" << endl;
        cout << "   -1. Exit" << endl;

        cout << "Option >> ";
        cin >> option;

        if (option == 1)
        {
            cout << "Size of list >> " << l.size() << endl;
        }
        else if (option == 2)
        {
            cout << l << endl;
        }
        else if (option == 3)
        {
            l.sort();
        }
        else if (option == 4)
        {
            int element = getVal("element");

            l.push_front(element);
        }
        else if (option == 5)
        {
            int element = getVal("element");

            l.push_back(element);
        }
        else if (option == 6)
        {
            l.pop_front();
        }
        else if (option == 7)
        {
            l.pop_back();
        }
        else if (option == -1)
        {
            return 0;
        }
        else
        {
            return 0;
        }
    }
}