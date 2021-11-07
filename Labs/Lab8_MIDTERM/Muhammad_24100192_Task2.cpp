#include <iostream>

using namespace std;

int sum(int* arr, int start, int end)
{
    if(start == end)
    {
        return arr[end];
    }

    return arr[start] + sum(arr, start+1, end);
}

int main()
{
    int size;
    int *arr;

    cout << "Enter size of the array >> ";
    cin >> size;

    arr = new int[size];

    for (int i = 0; i < size; i++)
    {
        cout << "Enter "<< i+1 << " element >> ";
        cin >> arr[i];
    }

    cout << sum(arr, 0, size-1) << endl;

    delete arr;
    return 0;
}