#include <iostream>

using namespace std;

class Set
{
public:
    Set()
    {
        set = NULL;
        length = 0;
    }

    Set(int *_arr, int _len)
    {
        // faster but needs more memory
        set = new int[_len];
        length = 0;

        for (int i = 0; i < _len; i++)
        {
            bool already_present = false;

            for (int s = 0; s < length; s++)
            {
                if (*(_arr + i) == *(set + s))
                {
                    already_present = true;
                    break;
                }
            }

            if (!already_present)
            {
                *(set + length) = *(_arr + i);
                length++;
            }
        }
    }

    ~Set()
    {
        delete[] set;
        set = NULL;
    }

    // Set Union(Set s1)
    // {
    //     return Set();
    // }

    void printSet()
    {
        cout << "{";
        for (int i = 0; i < length; i++)
        {
            cout << *(set + i) << ", ";
        }
        cout << "\b\b}" << endl;
    }

private:
    int *set;
    int length;
};

int main()
{
    int arr[] = {1, 2, 1, 3, 5, 1, -1};
    Set s1 = Set(arr, sizeof(arr) / sizeof(int));

    s1.printSet();

    return 0;
}