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
    {
        *root = newNode;
        // cout << "root inserted\n";
    }
    else
    {
        node *temp = *root;
        // cout << "inserting a new node\n";
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

void pre_order_traversal(node *root)
{
    if (root == NULL)
        return;
    else
    {
        cout << root->data << " ";
        pre_order_traversal(root->left);
        pre_order_traversal(root->right);
    }
}

void inorder_traversal(node *root)
{
    if (root == NULL)
        return;
    inorder_traversal(root->left);
    cout << root->data << " ";
    inorder_traversal(root->right);
}

void swap(node **a, node **b)
{
    node *temp = *a;
    *a = *b;
    *b = temp;
}

void invertTree(node **root)
{
    if (*root == NULL)
        return;
    else
    {
        invertTree(&((*root)->left));
        invertTree(&((*root)->right));

        swap(&((*root)->left), &((*root)->right));
    }
}

int main(int argc, char **argv)
{
    int n;
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

    // pre_order_traversal(root);

    inorder_traversal(root);
    invertTree(&root);
    cout << "\n";

    inorder_traversal(root);
    // pre_order_traversal(root);
    return 0;
}