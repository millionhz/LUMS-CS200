#include <iostream>

using namespace std;

template <typename A, typename B>
int find(A *arr, B element, const int &size)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == element)
        {
            return i;
        }
    }

    return -1;
}

int main()
{
    const int size = 5;
    int a1[] = {1, 2, 3, 4, 5};
    char a2[] = {'a', 'b', 'c', 'd', 'e'};

    cout << "int-double pair >> " << find(a1, 4.0, size) << endl;
    cout << "char-int pair >> " << find(a2, 99, size) << endl;

    return 0;
}