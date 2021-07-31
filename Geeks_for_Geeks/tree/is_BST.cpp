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
    string side;
    if (*root == NULL)
        *root = newNode;
    else
    {
        node *temp = *root;
        cout << "where to insert node L or R? ";
        cin >> side;
        while (side != "")
        {
            if (side == "L")
            {
                if (temp->left == NULL)
                {
                    temp->left = newNode;
                    side = "";
                }
                else
                {
                    temp = temp->left;
                    cout << "where to insert node L or R? ";
                    cin >> side;
                }
            }
            else
            {
                if (temp->right == NULL)
                {
                    temp->right = newNode;
                    side = "";
                }
                else
                {
                    temp = temp->right;
                    cout << "where to insert node L or R? ";
                    cin >> side;
                }
            }
        }
    }
}

void preOrder_traversal(node *root)
{
    if (root == NULL)
        return;
    else
    {
        cout << root->data << " ";
        preOrder_traversal(root->left);
        preOrder_traversal(root->right);
    }
}

bool isBST(node *root, int min_limit, int max_limit)
{
    if (root == NULL)
        return 1;
    else if (root->data > min_limit && root->data < max_limit)
    {
        bool left, right;
        left = isBST(root->left, min_limit, root->data);
        right = isBST(root->right, root->data, max_limit);
        return (left && right);
    }
    else
        return 0;
}

int main(int argc, char **argv)
{
    int n, data;
    cin >> n;

    node *root = NULL;

    for (int i = 0; i < n; i++)
    {
        node *newNode = new node;
        cin >> data;
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
        insertNode(&root, newNode);
    }

    cout << isBST(root, INT32_MIN, INT32_MAX) << "\n";
    return 0;
}