#include <iostream>
#include <string>
#include <stack>

using namespace std;

string inputString()
{
    string input_string;
    cout << "Enter string >> ";
    getline(cin, input_string);

    return input_string;
}

int main()
{
    stack<string> container;
    unsigned short int option;

    while (1)
    {
        cout << "Select an option:" << endl;
        cout << "   1. Push string" << endl;
        cout << "   2. Pop string" << endl;
        cout << "   3. End" << endl;
        cout << "Option >> ";
        cin >> option;

        cin.ignore(1000, '\n');

        if (option == 1)
        {
            string input_string = inputString();
            container.push(input_string);
        }
        else if (option == 2)
        {
            if (!container.empty())
            {
                string popped = container.top();
                container.pop();
                cout << "String >> " << popped << endl;
            }
            else
            {
                cout << "Stack is empty!" << endl;
            }
        }
        else if (option == 3)
        {
            return 0;
        }
    }

    return 1;
}