#include <iostream>

using namespace std;

template <typename T>
class MyStack
{
private:
    static const int limit = 100;
    T arr[limit];
    int size;

public:
    MyStack()
    {
        size = 0;
    }

    void push(T obj)
    {
        if (size >= limit)
        {
            cout << "Stack Overflow" << endl;
            return;
        }

        arr[size] = obj;
        size++;
    }

    T pop()
    {
        if (size <= 0)
        {
            cout << "Stack Underflow. Returning -1" << endl;
            return -1;
        }

        size--;
        return arr[size];
    }
};

template <typename T>
int main_typed()
{
    MyStack<T> my_stack;

    while (1)
    {
        unsigned short int option;

        cout << "Select operation: " << endl;
        cout << "   1. push" << endl;
        cout << "   2. pop" << endl;
        cout << "   3. exit" << endl;
        cout << "Option >> ";
        cin >> option;

        if (option == 1)
        {
            T data;
            cout << "Enter data >> ";
            cin >> data;

            my_stack.push(data);
        }
        else if (option == 2)
        {
            T data = my_stack.pop();
            cout << "Popped data: " << data << endl;
        }
        else
        {
            return 0;
        }
    }
}

int main()
{
    unsigned short int type;
    cout << "Select Type: " << endl;
    cout << "   1. int" << endl;
    cout << "   2. double" << endl;
    cout << "   3. char" << endl;
    cout << "Option >> ";
    cin >> type;

    if (type == 1)
    {
        return main_typed<int>();
    }
    else if (type == 2)
    {
        return main_typed<double>();
    }
    else if (type == 3)
    {
        return main_typed<char>();
    }
    else
    {
        return 0;
    }

    return 0;
}