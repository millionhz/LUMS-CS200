#include <iostream>
#include <queue>

using namespace std;

template <typename T>
class MyQueue
{
private:
    queue<T> my_queue;

public:
    MyQueue() {}

    void enqueue(T obj)
    {
        my_queue.push(obj);
    }

    T dequeue()
    {
        T data = my_queue.front();
        my_queue.pop();
        return data;
    }
};

template <typename T>
int main_typed()
{
    MyQueue<T> my_queue;
    while (1)
    {
        unsigned short int option;

        cout << "Select operation: " << endl;
        cout << "   1. queue" << endl;
        cout << "   2. dequeue" << endl;
        cout << "   3. exit" << endl;
        cout << "Option >> ";
        cin >> option;

        if (option == 1)
        {
            T data;
            cout << "Enter data >> ";
            cin >> data;

            my_queue.enqueue(data);
        }
        else if (option == 2)
        {
            T data = my_queue.dequeue();
            cout << "Dequeued data: " << data << endl;
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