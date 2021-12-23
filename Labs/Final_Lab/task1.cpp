#include <iostream>

using namespace std;

class MySet
{
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

    void makeSet(int *_arr, int _len)
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

    void copySet(const MySet &other_set)
    {
        makeSet(other_set.set, other_set.length);
    }

    int *deleteSet()
    {
        delete[] set;
        return NULL;
    }

    MySet Union(const MySet &other_set)
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

        return MySet(arr, index_arr);
    }

    MySet Intersection(const MySet &other_set)
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

        return MySet(arr, index_arr);
    }

    MySet Difference(const MySet &other_set)
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
        return MySet(arr, index_arr);
    }

public:
    MySet()
    {
        set = NULL;
        length = 0;
    }

    MySet(int *_arr, int _len)
    {
        makeSet(_arr, _len);
    }

    MySet(const MySet &other_set)
    {
        copySet(other_set);
    }

    ~MySet()
    {
        deleteSet();
    }

    void operator=(const MySet &other_set)
    {
        if (this != &other_set)
        {
            set = deleteSet();
            copySet(other_set);
        }
    }

    MySet operator+(const MySet &other_set)
    {
        return Union(other_set);
    }

    MySet operator*(const MySet &other_set)
    {
        return Intersection(other_set);
    }

    MySet operator-(const MySet &other_set)
    {
        return Difference(other_set);
    }

    friend ostream &operator<<(ostream &, const MySet &);
};

ostream &operator<<(ostream &os, const MySet &set)
{
    os << "{";
    for (int i = 0; i < set.length; i++)
    {
        os << set.set[i] << ", ";
    }
    os << "\b\b}";

    return os;
}

int main()
{
    int arr1[] = {1, 1, 1, 2, 3, 42, 6, 432};
    int size1 = sizeof(arr1) / sizeof(int);

    MySet s1(arr1, size1);

    int arr2[] = {1, 42, 99};
    int size2 = sizeof(arr2) / sizeof(int);

    MySet s2(arr2, size2);

    cout << "Union: " << s1 + s2 << endl;
    cout << "Intersection: " << s1 * s2 << endl;
    cout << "Difference: " << s1 - s2 << endl;

    return 0;
}