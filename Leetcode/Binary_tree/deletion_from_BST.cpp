#include <iostream>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
};

void insertNode(node **root, node *newNode)
{
    if (*root == NULL)
    {
        *root = newNode;
        return;
    }
    else if (newNode == NULL)
        return;
    else
    {
        node *temp = *root;
        if (temp->data > newNode->data)
        {
            insertNode(&(temp->left), newNode);
        }
        else
        {
            insertNode(&(temp->right), newNode);
        }
    }
}

void inorder_traversal(node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder_traversal(root->left);
    cout << root->data << " ";
    inorder_traversal(root->right);
}

void deleteNode(node **root, int key)
{
    if (*root == NULL)
        return;

    node *temp = NULL;
    node *target = *root;

    while (target->data != key)
    {
        temp = target;
        if (target->data > key)
            target = target->left;
        else
            target = target->right;

        if (target == NULL)
            return;
    }

    if (temp != NULL)
    {
        if (temp->left == target)
        {
            node *temp2;
            if (target->left == NULL && target->right == NULL)
                temp->left = NULL;
            else if (target->left == NULL)
            {
                temp->left = target->right;
            }
            else if (target->left == NULL)
            {
                temp->left = target->left;
            }
            else
            {
                temp->left = target->right;
                insertNode(&(temp->left), target->left);
            }
        }
        else
        {
            node *temp2;
            if (target->left == NULL && target->right == NULL)
                temp->right = NULL;
            else if (target->left == NULL)
            {
                temp->right = target->right;
            }
            else if (target->left == NULL)
            {
                temp->right = target->left;
            }
            else
            {
                temp->right = target->right;
                insertNode(&(temp->right), target->left);
            }
        }
    }
    else
    {

        *root = target->right;
        insertNode(root, target->left);
    }
}

int main(int argc, char **argv)
{
    int n, key;
    cin >> n;
    node *root = NULL;
    for (int i = 0; i < n; i++)
    {
        node *newNode = new node;

        cin >> newNode->data;
        newNode->left = NULL;
        newNode->right = NULL;

        insertNode(&root, newNode);
    }

    inorder_traversal(root);
    cout << "\n";
    cout << "data to delete: ";
    cin >> key;
    deleteNode(&root, key);

    inorder_traversal(root);
    cout << "\n";
    return 0;
}