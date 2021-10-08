#include <iostream>

using namespace std;

class Node
{
private:
    int data;
    Node *next_node;

public:
    Node()
    {
        data = 0;
    }

    Node(int a)
    {
        data = a;
        next_node = NULL;
    }

    Node *getNextPointer() const
    {
        return next_node;
    }

    void setNextPointer(Node *ptr)
    {
        next_node = ptr;
    }

    void setData(int a)
    {
        data = a;
    }

    int getData() const
    {
        return data;
    }
};

class LinkedList
{
private:
    Node *head;
    int length;

public:
    Node *getNode(int index) const
    {
        if (index >= length || index < 0)
        {
            return NULL;
        }
        Node *ptr = head;
        for (int i = 0; i < index; i++)
        {
            ptr = ptr->getNextPointer();
        }
        return ptr;
    }
    LinkedList()
    {
        head = NULL;
        length = 0;
    }

    bool insertAt(int data, int index)
    {
        if (index > length || index < 0)
        {
            return false;
        }

        Node *new_node = new Node;
        new_node->setData(data);

        Node *current_node = getNode(index);
        new_node->setNextPointer(current_node);

        Node *prev_node = getNode(index - 1);
        if (prev_node)
        {
            prev_node->setNextPointer(new_node);
        }

        if (head == NULL || index == 0)
        {
            head = new_node;
        }

        length++;
        return true;
    }

    bool insertHead(int data)
    {
        return insertAt(data, 0);
    }

    void displayList() const
    {
        for (int i = 0; i < length; i++)
        {
            cout << getNode(i)->getData() << "->";
        }
        cout << "NULL" << endl;
    }
};

int main()
{
    LinkedList list;
    list.insertHead(45);
    list.insertAt(231, 0);
    list.insertAt(31, 1);
    list.insertAt(313, 1);

    list.displayList();
    return 0;
}