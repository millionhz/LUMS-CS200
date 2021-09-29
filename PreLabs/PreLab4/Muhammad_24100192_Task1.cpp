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

        optimizeMemory();
    }

    ~Set()
    {
        delete[] set;
        set = NULL;
    }

    Set Union(Set &other_set)
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

    Set Intersection(Set &other_set)
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
                    break;
                }
            }
        }

        return Set(arr, index_arr);
    }

    Set Difference(Set &other_set)
    {
        int arr[this->length + other_set.length];
        int index_arr = 0;

        for (int i = 0; i < this->length; i++)
        {
            bool element_present_in_both = false;
            for (int j = 0; j < other_set.length; j++)
            {
                if (this->set[i] == other_set.set[j])
                {
                    element_present_in_both = true;
                    break;
                }
            }

            if (!element_present_in_both)
            {
                arr[index_arr] = this->set[i];
                index_arr++;
            }
        }
        return Set(arr, index_arr);
    }

    bool Compare(Set &other_set)
    {

        for (int i = 0; i < this->length; i++)
        {
            bool same_element_present = false;

            for (int j = 0; j < other_set.length; j++)
            {
                if (this->set[i] == other_set.set[j])
                {
                    same_element_present = true;
                    break;
                }
            }

            if (!same_element_present)
            {
                return false;
            }
        }

        return true;
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

    void optimizeMemory()
    {

        int *new_set = new int[length];

        for (int i = 0; i < length; i++)
        {
            new_set[i] = set[i];
        }

        delete[] set;
        set = new_set;
    }
};

int main()
{
    return 0;
}