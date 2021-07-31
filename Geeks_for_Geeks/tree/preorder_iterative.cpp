#include <iostream>
#include <stack>
#include <vector>
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

void preorder_iterative(node *root)
{
    stack<node *> s1;
    stack<int> s2;
    node *temp;
    s1.push(root);
    while (!s1.empty())
    {
        temp = s1.top();
        s1.pop();
        if (temp->right != NULL)
            s1.push(temp->right);

        if (temp->left != NULL)
            s1.push(temp->left);

        cout << temp->data << " ";
    }
}

/*void inorder_iterative(node *root)
{
    stack<node *> left;
    stack<node *> middle;
    stack<node *> right;
}*/

int main(int argc, char **argv)
{
    int n, data;
    cin >> n;
    node *root = NULL;
    for (int i = 0; i < n; i++)
    {
        cin >> data;
        node *newNode = new node;
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
        insertNode(&root, newNode);
    }

    preOrder_traversal(root);
    cout << "\n";
    preorder_iterative(root);
    cout << "\n";
    return 0;
}