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
        data = 0;
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
        for (int i = 0; i < length; i++)
        {
            cout << getNode(i)->getData() << "->";
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

int main()
{
    LinkedList<int> list;
    list.insertHead(45);
    list.insertAt(231, 0);
    list.insertAt(31, 1);
    list.insertAt(313, 1);
    list.insertTail(0);

    list.displayList();

    list.removeTail();
    list.removeHead();
    list.displayList();

    LinkedList<int> list2 = list;
    list2.displayList();

    return 0;
}