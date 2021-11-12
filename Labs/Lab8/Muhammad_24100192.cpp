#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *parent;
    Node *left;
    Node *right;
};

Node *TreeSearch(Node *root, int search_key)
{
    if (!root)
    {
        return nullptr;
    }
    else if (root->data == search_key)
    {
        return root;
    }
    else if (root->data < search_key)
    {
        return TreeSearch(root->right, search_key);
    }
    else
    {
        return TreeSearch(root->left, search_key);
    }
}

Node *newTreeNode(int data)
{
    Node *node = new Node;
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;

    return node;
}

Node *insertTreeNode(Node *node, int data)
{
    static Node *p;
    Node *retNode;

    if (node == NULL)
    {
        retNode = newTreeNode(data);
        retNode->parent = p;
        return retNode;
    }
    if (data <= node->data)
    {
        p = node;
        node->left = insertTreeNode(node->left, data);
    }
    else
    {
        p = node;
        node->right = insertTreeNode(node->right, data);
    }
    return node;
}

Node *makeTree(int *arr, int size, int head_node_data)
{
    Node *head = new Node;
    head->data = head_node_data;

    for (int i = 0; i < size; i++)
    {
        insertTreeNode(head, arr[i]);
    }

    return head;
}

int main()
{
    int arr[] = {6, 12, 17, 21, 25, 37, 30, 43, 75, 62, 56, 69, 88, 81, 94, 85};
    Node *root = makeTree(arr, sizeof(arr) / sizeof(int), 50);

    int val_to_search[] = {0, 6, 12, 17, 21, 25, 37, 30, 43, 75, 62, 56, 69, 88, 81, 94, 85, 100};
    int size = sizeof(val_to_search) / sizeof(int);
    for (int i = 0; i < size; i++)
    {
        Node *result = TreeSearch(root, val_to_search[i]);

        if (result)
        {
            cout << result->data << " at Node " << result << endl;
        }
        else
        {
            cout << "NULL" << endl;
        }
    }

    return 0;
}
