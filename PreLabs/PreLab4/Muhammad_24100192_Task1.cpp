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
                if (_arr[i] == set[s])
                {
                    already_present = true;
                    break;
                }
            }

            if (!already_present)
            {
                set[length] = _arr[i];
                length++;
            }
        }
    }

    ~Set()
    {
        delete[] set;
        set = NULL;
    }

    Set Union(Set other_set)
    {
        int arr[this->length + other_set.length];
        int index_arr = 0;

        for (int i = 0; i < this->length; i++)
        {
            arr[index_arr] = this->set[i];
            index_arr++;
        }

        for (int i = 0; i < other_set.length; i++)
        {
            arr[index_arr] = other_set.set[i];
            index_arr++;
        }

        return Set(arr, index_arr);
    }

    Set Intersection(Set other_set)
    {
        int arr[this->length + other_set.length];
        int index_arr = 0;

        for (int i = 0; i < this->length; i++)
        {
            for (int j = 0; j < other_set.length; j++)
            {
                if (this->set[i] == other_set.set[j])
                {
                    arr[index_arr] = other_set.set[j];
                    index_arr++;
                }
            }
        }

        return Set(arr, index_arr);
    }

    void printSet()
    {
        cout << "{";
        for (int i = 0; i < length; i++)
        {
            cout << set[i] << ", ";
        }
        cout << "\b\b}" << endl;
    }

private:
    int *set;
    int length;
};

int main()
{
    int arr1[] = {1, 2, 1, 3, 5, 1, -1};
    Set s1 = Set(arr1, sizeof(arr1) / sizeof(int));
    s1.printSet();

    int arr2[] = {-1, 2, 1, -3, 55, 5, 1, -1, 7, 11, 11, 14};
    Set s2 = Set(arr2, sizeof(arr2) / sizeof(int));
    s2.printSet();

    Set resultant = s1.Union(s2);
    resultant.printSet();

    resultant = s1.Intersection(s2);
    resultant.printSet();

    return 0;
}