#include <iostream>

using namespace std;

int sum(int *arr, int size, int i = 0)
{
    if (i == size)
    {
        return 0;
    }

    return arr[i] + sum(arr, size, i + 1);
}

int main()
{
    while (1)
    {
        int size;
        cout << "Enter size of the array >> ";
        cin >> size;

        if (size == -1)
        {
            return 0;
        }

        int *arr = new int[size];

        for (int i = 0; i < size; i++)
        {
            cout << "Enter element " << i << " >> ";
            cin >> arr[i];
        }

        cout << "Sum of the array is: " << sum(arr, size) << endl;

        delete[] arr;
    }
}
