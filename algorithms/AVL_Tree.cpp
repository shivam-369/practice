#include <iostream>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
};

node *insert_node_in_BST(node *root, node *ele)
{
    if (root->data > ele->data)
    {
        if (root->left == NULL)
            root->left = ele;
        else
        {
            insert_node_in_BST(root->left, ele);
        }
    }
}

void pre_order_traversal(node *root)
{
    cout << "inside preorder traversal\n";
    if (root == NULL)
        return;

    cout << root->data << " ";

    if (root->left != NULL)
        pre_order_traversal(root->left);

    if (root->right != NULL)
        pre_order_traversal(root->right);
}

int main(int argc, char **argv)
{
    int n, temp;
    cin >> n;
    node *root;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        node *ele = new node;
        ele->data = temp;
        ele->left = NULL;
        ele->right = NULL;
        insert_node_in_BST(root, ele);
    }

    cout << "calling preorder traversal \n";
    pre_order_traversal(root);
    cout << "ending preorder traversal\n";
    return 0;
}