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

    void setDefaults()
    {
        head = NULL;
        length = 0;
    }

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

public:
    LinkedList()
    {
        setDefaults();
    }

    LinkedList(const LinkedList &other_list)
    {
        setDefaults();

        for (int i = 0; i < other_list.length; i++)
        {
            insertAt(other_list.getNode(i)->getData(), i);
        }
    }

    bool insertAt(int data, int index)
    {
        if (index > length || index < 0)
        {
            return false;
        }

        Node *new_node = new Node;
        new_node->setData(data);

        Node *prev_node = getNode(index - 1);

        if (prev_node)
        {
            Node *current_node = prev_node->getNextPointer();

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

        Node *prev_node = getNode(index - 1);

        Node *node_to_delete; // mode_to_delete acts as a temp variable

        if (prev_node)
        {
            Node *next_node = prev_node->getNextPointer()->getNextPointer();

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

    bool
    insertHead(int data)
    {
        return insertAt(data, 0);
    }

    bool insertEnd(int data)
    {
        return insertAt(data, length);
    }

    bool removeHead()
    {
        return removeAt(0);
    }

    bool removeEnd()
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
        Node *current_node = head;
        while (current_node)
        {
            Node *temp = current_node->getNextPointer();
            delete current_node;
            current_node = temp;
        }
    }
};

int main()
{
    LinkedList list;
    list.insertHead(45);
    list.insertAt(231, 0);
    list.insertAt(31, 1);
    list.insertAt(313, 1);
    list.insertEnd(0);

    list.displayList();

    list.removeEnd();
    list.removeHead();
    list.displayList();

    LinkedList list2 = list;
    list2.displayList();

    return 0;
}