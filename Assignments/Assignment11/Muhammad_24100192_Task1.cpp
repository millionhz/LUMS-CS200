#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

ostream &operator<<(ostream &os, vector<int> v)
{
    os << "{";
    for (int x : v)
    {
        os << x << ", ";
    }
    os << "\b\b}";

    return os;
}

int getVal(const char *prompt)
{
    int val;
    cout << "Input " << prompt << " >> ";
    cin >> val;

    return val;
}

int main()
{
    vector<int> v;

    int option;

    while (1)
    {
        cout << "Select an option: " << endl;
        cout << "   1. Insert at the end of the vector" << endl;
        cout << "   2. Insert at the front of the vector" << endl;
        cout << "   3. Insert at a particular index" << endl;
        cout << "   4. Print contents of the vector" << endl;
        cout << "   5. Find an element in the vector" << endl;
        cout << "   6. Sort a part of the vector in ascending order" << endl;
        cout << "   7. Print size of the vector" << endl;
        cout << "   8. Reverse a part of the vector" << endl;
        cout << "   -1. Exit" << endl;

        cout << "Option >> ";
        cin >> option;

        if (option == 1)
        {
            int element = getVal("element");

            v.push_back(element);
        }
        else if (option == 2)
        {
            int element = getVal("element");

            v.insert(v.begin(), element);
        }
        else if (option == 3)
        {
            int element = getVal("element");
            size_t index = getVal("index");

            if (index <= v.size() && index > 0)
            {
                v.insert(v.begin() + index, element);
            }
        }
        else if (option == 4)
        {
            cout << "Vector >> " << v << endl;
        }
        else if (option == 5)
        {
            int element = getVal("element");

            vector<int>::iterator it = find(v.begin(), v.end(), element);

            if (it < v.end())
            {
                cout << "Element present at >> " << distance(v.begin(), it) << endl;
            }
            else
            {
                cout << "Element not present in the vector" << endl;
            }
        }
        else if (option == 6)
        {
            size_t starting_index = getVal("starting index");
            size_t ending_index = getVal("ending index") + 1;

            if (ending_index <= v.size())
            {
                sort(v.begin() + starting_index, v.begin() + ending_index);
            }
            else
            {
                cout << "Index out of bound" << endl;
            }
        }
        else if (option == 7)
        {
            cout << "Size of vector >> " << v.size() << endl;
        }
        else if (option == 8)
        {
            size_t starting_index = getVal("starting index");
            size_t ending_index = getVal("ending index") + 1;

            if (ending_index <= v.size())
            {
                reverse(v.begin() + starting_index, v.begin() + ending_index);
            }
            else
            {
                cout << "Index out of bound" << endl;
            }
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