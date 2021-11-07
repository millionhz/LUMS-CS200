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

class OrderedLinkedList
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

    void AddElementsFromList(const OrderedLinkedList &list)
    {
        for (int i = 0; i < list.length; i++)
        {
            insertAscendingOrder(list.getNode(i)->getData());
        }
    }

    void copyList(const OrderedLinkedList &list)
    {
        setDefaults();
        AddElementsFromList(list);
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

public:
    OrderedLinkedList()
    {
        setDefaults();
    }

    OrderedLinkedList(const OrderedLinkedList &list)
    {
        copyList(list);
    }

    void displayList() const
    {
        for (int i = 0; i < length; i++)
        {
            cout << getNode(i)->getData() << "->";
        }
        cout << "NULL" << endl;
    }

    void insertAscendingOrder(int data)
    {
        for (int i = 0; i <= length; i++)
        {
            if (i == length)
            {
                insertEnd(data);
                return;
            }
            else if (data < getNode(i)->getData())
            {
                insertAt(data, i);
                return;
            }
        }
    }

    ~OrderedLinkedList()
    {
        head = deleteList();
    }

    void operator=(const OrderedLinkedList &list)
    {
        if (this != &list)
        {
            head = deleteList();
            copyList(list);
        }
    }

    int operator[](const int &index)
    {
        if (index < length)
        {
            return getNode(index)->getData();
        }
        else
        {
            cout << "Index out of range" << endl;
            return 0;
        }
    }

    OrderedLinkedList operator+(const OrderedLinkedList &list)
    {
        OrderedLinkedList out_list;

        out_list.AddElementsFromList(list);
        out_list.AddElementsFromList(*this);
        return out_list;
    }

    void operator-(const int &index)
    {
        if (index < length)
        {
            removeAt(index);
        }
    }

    void operator+=(const OrderedLinkedList &list)
    {
        AddElementsFromList(list);
    }

    OrderedLinkedList operator--()
    {
        removeHead();
        return *this;
    }

    OrderedLinkedList operator--(int)
    {
        removeEnd();
        return *this;
    }

    friend istream &operator>>(istream &, OrderedLinkedList &);

    friend ostream &operator<<(ostream &, const OrderedLinkedList &);
};

ostream &operator<<(ostream &os, const OrderedLinkedList &list)
{
    list.displayList();

    return os;
}

istream &operator>>(istream &is, OrderedLinkedList &list)
{
    int data;
    cout << "Enter value you want to insert >> ";
    is >> data;

    list.insertAscendingOrder(data);

    return is;
}

int main()
{
    OrderedLinkedList list;

    cin >> list;
    cout << list;

    cin >> list;
    cout << list;

    cin >> list;
    cout << list;

    OrderedLinkedList list2 = list;

    OrderedLinkedList r = (--list) + list2;

    //(--list)--;
    cout << r;

    return 0;
}
