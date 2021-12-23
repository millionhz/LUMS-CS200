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

    Node *_reverse(Node **head, Node *ptr)
    {
        if (!ptr)
        {
            return NULL;
        }
        else if (!ptr->getNextPointer())
        {
            (*head)->setNextPointer(NULL);
            *head = ptr;
            return ptr;
        }

        Node *new_ptr = _reverse(head, ptr->getNextPointer());

        new_ptr->setNextPointer(ptr);
        return ptr;
    }

    void copyList(const LinkedList &other_list)
    {
        setDefaults();

        Node *current_node = other_list.head;

        for (int i = 0; i < other_list.getLength(); i++)
        {
            insertAt(current_node->getData(), i);

            current_node = current_node->getNextPointer();
        }
    }

    Node *deleteList()
    {
        Node *current_node = head;
        while (current_node)
        {
            Node *temp = current_node->getNextPointer();
            delete current_node;
            current_node = temp;
        }

        return NULL;
    }

    void setDefaults()
    {
        head = NULL;
    }

    bool removeHead()
    {
        return DeleteAt(0);
    }

    bool removeEnd()
    {
        return DeleteAt(getLength() - 1);
    }

public:
    LinkedList()
    {
        setDefaults();
    }

    LinkedList(const LinkedList &other_list)
    {
        copyList(other_list);
    }

    bool insertAt(int data, int index)
    {
        if (index > getLength() || index < 0)
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

        return true;
    }

    bool DeleteAt(int index)
    {
        if (index < 0 || index >= getLength())
        {
            return false;
        }

        Node *prev_node = getNode(index - 1);

        Node *node_to_delete; // node_to_delete acts as a temp variable

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

        return true;
    }

    void reverse()
    {
        _reverse(&head, head);
    }

    ~LinkedList()
    {
        deleteList();
    }

    void operator=(const LinkedList &other_list)
    {
        if (this != &other_list)
        {
            head = deleteList();
            copyList(other_list);
        }
    }

    void operator--()
    {
        removeHead();
    }

    void operator--(int)
    {
        removeEnd();
    }

    LinkedList operator++()
    {
        reverse();

        return *this;
    }

    LinkedList operator++(int)
    {
        LinkedList old_list = *this;

        reverse();

        return old_list;
    }

    friend ostream &operator<<(ostream &, const LinkedList &);
};

ostream &operator<<(ostream &os, const LinkedList &list)
{
    Node *ptr = list.head;
    while (ptr)
    {
        os << ptr->getData() << "->";
        ptr = ptr->getNextPointer();
    }
    os << "NULL";

    return os;
}

int main()
{
    cout << "Running" << endl;
    LinkedList list;

    LinkedList l;

    list.insertAt(45, 0);
    list.insertAt(231, 0);
    list.insertAt(31, 1);
    list.insertAt(313, 1);
    list.insertAt(0, 4);

    l = list;

    cout << list << endl;
    list--;
    cout << list << endl;
    --list;
    cout << list << endl;

    cout << endl;

    l++;
    cout << l << endl;

    ++l;
    cout << l << endl;

    cout << "ending" << endl;
    return 0;
}