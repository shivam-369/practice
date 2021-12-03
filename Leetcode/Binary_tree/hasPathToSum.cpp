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

bool hasPathToSum(node *root, int targetSum)
{
    if (root == NULL)
        return 0;
    else if (root->data == targetSum)
    {
        if (root->left == NULL && root->right == NULL)
            return 1;
    }
    return (hasPathToSum(root->left, targetSum - root->data) || hasPathToSum(root->right, targetSum - root->data));
}

int main(int argc, char **argv)
{
    int n, targetSum;
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

    cin >> targetSum;

    cout << hasPathToSum(root, targetSum) << "\n";

    return 0;
}