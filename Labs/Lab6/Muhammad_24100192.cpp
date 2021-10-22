#include <iostream>

using namespace std;

// NOTE:
// insertAtHead == insertHead
// insertAtTail == insertEnd
// delete == deleteInstances

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

    void operator=(const Node &_) = delete;
};

class LinkedList
{
private:
    Node *head;
    int length;
    bool isCircular;

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

    void connectTailToHead()
    {
        Node *last_node = getNode(length - 1);

        last_node->setNextPointer(head);
    }

public:
    LinkedList()
    {
        head = NULL;
        length = 0;
        isCircular = false;
    }

    LinkedList(int data)
    {
        insertHead(data);
        isCircular = false;
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
        else
        {
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

        Node *node_to_delete = getNode(index);

        Node *next_node = node_to_delete->getNextPointer();

        Node *prev_node = getNode(index - 1);

        if (prev_node)
        {
            prev_node->setNextPointer(next_node);
        }
        else
        {
            head = next_node;
        }

        delete node_to_delete;

        length--;

        return true;
    }

    bool insertHead(int data)
    {
        bool out = insertAt(data, 0);

        if (isCircular)
        {
            connectTailToHead();
        }

        return out;
    }

    bool insertEnd(int data)
    {
        bool out = insertAt(data, length);

        if (isCircular)
        {
            connectTailToHead();
        }

        return out;
    }

    bool removeHead()
    {
        return removeAt(0);
    }

    bool removeEnd()
    {
        return removeAt(length - 1);
    }

    void deleteInstances(int x)
    {
        for (int i = 0; i < length; i++)
        {
            if (getNode(i)->getData() == x)
            {
                removeAt(i);
            }
        }
    }

    int sum()
    {
        int sum = 0;
        for (int i = 0; i < length; i++)
        {
            sum += getNode(i)->getData();
        }
        return sum;
    }

    float average()
    {
        return sum() / (float)length;
    }

    bool makeCircular()
    {
        if (!isCircular)
        {
            connectTailToHead();
            isCircular = true;
            return true;
        }
        else
        {
            return false;
        }
    }

    void displayList() const
    {
        for (int i = 0; i < length; i++)
        {
            cout << getNode(i)->getData() << "->";
        }
        cout << getNode(0)->getData() << endl;
    }

    void operator=(const LinkedList &_) = delete;

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
    unsigned int input = 0;

#if 0
    while (input != -1)
    {
        // TODO: Print Menu
        cin >> input;

        // TODO: If else hell
    }
#endif
    return 0;
}