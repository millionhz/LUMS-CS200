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

    void connectTailAndHead()
    {
        Node *last_node = getNode(length - 1);
        if (!last_node)
        {
            last_node->setNextPointer(head);
        }
    }

    void disconnectTailAndHead()
    {
        Node *last_node = getNode(length - 1);
        if (!last_node)
        {
            last_node->setNextPointer(NULL);
        }
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
            connectTailAndHead();
        }

        return out;
    }

    bool insertEnd(int data)
    {
        bool out = insertAt(data, length);

        if (isCircular)
        {
            connectTailAndHead();
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
        disconnectTailAndHead();

        for (int i = 0; i < length; i++)
        {
            if (getNode(i)->getData() == x)
            {
                removeAt(i);
            }
        }
    }

    Node pop()
    {
        Node head_clone;
        head_clone.setData(head->getData());
        head_clone.setNextPointer(head->getNextPointer());

        removeHead();

        return head_clone;
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
            connectTailAndHead();
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

        if (getNode(0))
        {
            cout << getNode(0)->getData() << endl;
        }
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
            cout << current_node << endl;
        }
    }
};

void printMenu()
{
    cout << "-1. Exit" << endl;
    cout << "0. Sum" << endl;
    cout << "1. Average" << endl;
    cout << "2. InsertAtHead" << endl;
    cout << "3. InsertAtTail" << endl;
    cout << "4. Delete Instances" << endl;
    cout << "5. Pop" << endl;
    cout << "6. MakeCircular" << endl;
    cout << "7. Print List" << endl;
}

int main()
{
    LinkedList my_list;

    int input = 0;

    while (input != -1)
    {
        printMenu();

        do
        {
            cout << "Enter input >> ";
            cin >> input;
        } while (input < -1 || input > 7);

        switch (input)
        {
        case -1:
        {
            break;
        }
        case 0:
        { // Sum
            cout << "Sum of the list is " << my_list.sum() << endl;
            break;
        }

        case 1:
        { // Average
            cout << "Average of the list is " << my_list.average() << endl;
            break;
        }

        case 2:
        { // Insert At Head
            int data = 0;

            cout << "Enter data to insert at head >> ";
            cin >> data;

            my_list.insertHead(data);
            break;
        }

        case 3:
        { // Insert At Tail
            int data = 0;

            cout << "Enter data to insert at tail >> ";
            cin >> data;

            my_list.insertEnd(data);
            break;
        }

        case 4:
        { // Delete instances
            int data;

            cout << "Enter value to remove from the list >> ";
            cin >> data;

            my_list.deleteInstances(data);
            break;
        }

        case 5:
        { // Pop
            Node popped = my_list.pop();

            cout << "Node with data: " << popped.getData() << " and next node pointer: " << popped.getNextPointer() << " was deleted" << endl;
            break;
        }

        case 6:
        { // Circular
            bool success = my_list.makeCircular();

            success ? cout << "List has been made circular" << endl : cout << "List was already circular" << endl;
            break;
        }

        case 7:
        { // Display
            my_list.displayList();
            break;
        }

        default:
        {
            break;
        }
        }
    }
    return 0;
}