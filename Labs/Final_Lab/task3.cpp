#include <iostream>

using namespace std;

class Node
{
private:
    int data;
    Node *next_node;
    Node *prev_node;

public:
    Node()
    {
        data = 0;
        next_node = NULL;
        prev_node = NULL;
    }

    Node(int a)
    {
        data = a;
        next_node = NULL;
        prev_node = NULL;
    }

    Node *getNextPointer() const
    {
        return next_node;
    }

    void setNextPointer(Node *ptr)
    {
        next_node = ptr;
    }

    Node *getPreviousPointer() const
    {
        return prev_node;
    }

    void setPreviousPointer(Node *ptr)
    {
        prev_node = ptr;
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

class DoubleLinkedList
{
private:
    Node *head;

    int getLength() const
    {
        Node *ptr = head;
        int len = 0;

        while (ptr)
        {
            len++;
            ptr = ptr->getNextPointer();
        }

        return len;
    }

    Node *getNode(int index) const
    {
        if (index >= getLength() || index < 0)
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

    Node *getTail()
    {
        Node *ptr = head;
        while (ptr && ptr->getNextPointer())
        {
            ptr = ptr->getNextPointer();
        }
        return ptr;
    }

public:
    DoubleLinkedList()
    {
        head = NULL;
    }

    void insertAt(int data, int index)
    {
        if (index > getLength() || index < 0)
        {
            return;
        }

        Node *new_node = new Node;
        new_node->setData(data);

        Node *prev_node = getNode(index - 1);

        if (prev_node)
        {
            Node *current_node = prev_node->getNextPointer();

            new_node->setNextPointer(current_node);
            new_node->setPreviousPointer(prev_node);

            prev_node->setNextPointer(new_node);

            if (current_node)
            {
                current_node->setPreviousPointer(new_node);
            }
        }
        else
        {
            new_node->setNextPointer(head);

            if (head)
            {
                head->setPreviousPointer(new_node);
            }

            head = new_node;
        }

        return;
    }

    void deletAt(int index)
    {
        if (index < 0 || index >= getLength())
        {
            return;
        }

        Node *prev_node = getNode(index - 1);

        Node *node_to_delete; // node_to_delete acts as a temp variable

        if (prev_node)
        {
            Node *next_node = prev_node->getNextPointer()->getNextPointer();

            node_to_delete = prev_node->getNextPointer();

            prev_node->setNextPointer(next_node);

            if (next_node)
            {
                next_node->setPreviousPointer(prev_node);
            }
        }
        else
        {
            node_to_delete = head;

            head = head->getNextPointer();

            head->setPreviousPointer(NULL);
        }

        delete node_to_delete;
    }

    void printFromHead()
    {
        Node *ptr = head;
        while (ptr)
        {
            cout << ptr->getData() << "->";
            ptr = ptr->getNextPointer();
        }
        cout << "NULL" << endl;
    }

    void printFromTail()
    {
        Node *ptr = getTail();

        while (ptr)
        {
            cout << ptr->getData() << "->";
            ptr = ptr->getPreviousPointer();
        }
        cout << "NULL" << endl;
    }

    ~DoubleLinkedList()
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

    DoubleLinkedList list;

    list.insertAt(45, 0);
    list.insertAt(231, 0);
    list.insertAt(31, 1);
    list.insertAt(313, 1);
    list.insertAt(0, 4);

    list.printFromHead(); // 231->313->31->45->0->NULL
    list.printFromTail();

    cout << "Del at start" << endl;
    list.deletAt(0);
    list.printFromHead();
    list.printFromTail();

    cout << "Del at middle" << endl;
    list.deletAt(2);
    list.printFromHead();
    list.printFromTail();

    cout << "Del at end" << endl;
    list.deletAt(2);
    list.printFromHead();
    list.printFromTail();

    cout << "Ended" << endl;

    return 0;
}