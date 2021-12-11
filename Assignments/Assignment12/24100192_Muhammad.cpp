#include <iostream>

using namespace std;

template <typename T>
class Node
{
private:
    T data;
    Node<T> *next_node;

public:
    Node()
    {
        data = T();
    }

    Node(T a)
    {
        data = a;
        next_node = NULL;
    }

    Node<T> *getNextPointer() const
    {
        return next_node;
    }

    void setNextPointer(Node<T> *ptr)
    {
        next_node = ptr;
    }

    void setData(T a)
    {
        data = a;
    }

    T getData() const
    {
        return data;
    }
};

template <typename T>
class LinkedList
{
private:
    Node<T> *head;
    int length;

    void setDefaults()
    {
        head = NULL;
        length = 0;
    }

    Node<T> *getNode(int index) const
    {
        if (index >= length || index < 0)
        {
            return NULL;
        }

        Node<T> *ptr = head;
        for (int i = 0; i < index; i++)
        {
            ptr = ptr->getNextPointer();
        }
        return ptr;
    }

public:
    LinkedList()
    {
        setDefaults();
    }

    LinkedList(const LinkedList &other_list)
    {
        setDefaults();

        Node<T> *current_node = other_list.head;

        for (int i = 0; i < other_list.length; i++)
        {
            insertAt(current_node->getData(), i);

            current_node = current_node->getNextPointer();
        }
    }

    bool insertAt(T data, int index)
    {
        if (index > length || index < 0)
        {
            return false;
        }

        Node<T> *new_node = new Node<T>;
        new_node->setData(data);

        Node<T> *prev_node = getNode(index - 1);

        if (prev_node)
        {
            Node<T> *current_node = prev_node->getNextPointer();

            prev_node->setNextPointer(new_node);

            new_node->setNextPointer(current_node);
        }
        else
        {
            new_node->setNextPointer(head);
            head = new_node;
        }

        length++;

        return true;
    }

    bool removeAt(int index)
    {
        if (index < 0 || index >= length)
        {
            return false;
        }

        Node<T> *prev_node = getNode(index - 1);

        Node<T> *node_to_delete; // mode_to_delete acts as a temp variable

        if (prev_node)
        {
            Node<T> *next_node = prev_node->getNextPointer()->getNextPointer();
            // more readable this way

            node_to_delete = prev_node->getNextPointer();

            prev_node->setNextPointer(next_node);
        }
        else
        {
            node_to_delete = head;

            head = head->getNextPointer();
        }

        delete node_to_delete;

        length--;

        return true;
    }

    bool insertHead(T data)
    {
        return insertAt(data, 0);
    }

    bool insertTail(T data)
    {
        return insertAt(data, length);
    }

    bool removeHead()
    {
        return removeAt(0);
    }

    bool removeTail()
    {
        return removeAt(length - 1);
    }

    void displayList() const
    {
        Node<T> *current_node = head;

        // for loops are safer (bounded)
        for (int i = 0; i < length; i++)
        {
            cout << current_node->getData() << "->";
            current_node = current_node->getNextPointer();
        }
        cout << "NULL" << endl;
    }

    ~LinkedList()
    {
        Node<T> *next_pointer;

        while (head)
        {
            next_pointer = head->getNextPointer();
            delete head;
            head = next_pointer;
        }
    }
};

template <typename T>
T getData(const char *prompt)
{
    T data;
    cout << "Enter " << prompt << " >> ";
    cin >> data;

    return data;
}

void _printSuccessMessage(const char *s, bool success)
{
    if (success)
    {
        cout << s << " was successfull!" << endl;
    }
    else
    {
        cout << s << " failed!" << endl;
    }
}

void printInsertionMessage(bool success)
{
    _printSuccessMessage("Insertion", success);
}

void printRemovalMessage(bool success)
{
    _printSuccessMessage("Removal", success);
}

template <typename T>
void program()
{
    LinkedList<T> my_list;

    int option;

    while (1)
    {
        cout << "   1. Insert data at head" << endl;
        cout << "   2. Insert data at tail" << endl;
        cout << "   3. Insert data at a particular index" << endl;
        cout << "   4. Remove head node" << endl;
        cout << "   5. Remove tail node" << endl;
        cout << "   6. Remove node at a particular index" << endl;
        cout << "   7. Display Linked List" << endl;
        cout << "   0. Go back" << endl;
        cout << "Select an option >> ";
        cin >> option;

        if (option == 1)
        {
            bool success = my_list.insertHead(getData<T>("data"));

            printInsertionMessage(success);
        }
        else if (option == 2)
        {
            bool success = my_list.insertTail(getData<T>("data"));

            printInsertionMessage(success);
        }
        else if (option == 3)
        {
            bool success = my_list.insertAt(getData<T>("data"), getData<int>("index"));

            printInsertionMessage(success);
        }
        else if (option == 4)
        {
            bool success = my_list.removeHead();

            printRemovalMessage(success);
        }
        else if (option == 5)
        {
            bool success = my_list.removeTail();

            printRemovalMessage(success);
        }
        else if (option == 6)
        {
            bool success = my_list.removeAt(getData<int>("index"));

            printRemovalMessage(success);
        }
        else if (option == 7)
        {
            my_list.displayList();
        }
        else if (option == 0)
        {
            return;
        }
    }
}

int main()
{
    int option;

    while (1)
    {
        cout << "   1. Character Linked List" << endl;
        cout << "   2. Integer Linked List" << endl;
        cout << "   3. Double Linked List" << endl;
        cout << "   4. String Linked List" << endl;
        cout << "   0. Exit" << endl;
        cout << "Select a Linked List >> ";
        cin >> option;

        if (option == 1)
        {
            program<char>();
        }
        else if (option == 2)
        {
            program<int>();
        }
        else if (option == 3)
        {
            program<double>();
        }
        else if (option == 4)
        {
            cout << "NOTE >> Blank Spaces are not allowed!" << endl;
            program<string>();
        }
        else if (option == 0)
        {
            return 0;
        }
    }

    return 1;
}