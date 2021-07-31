#include <iostream>
#include <stack>
using namespace std;

struct node
{
    int value;
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

void in_order_traversal(node *root)
{
    if (root == NULL)
        return;

    in_order_traversal(root->left);
    cout << root->value << " ";
    in_order_traversal(root->right);
}

void inorder_iterative(node *root)
{
    node *current = root;
    stack<node *> s1;
    s1.push(root);
    current = root->left;
    while (!s1.empty() || current != NULL)
    {
        while (current != NULL)
        {
            s1.push(current);
            current = current->left;
        }
        current = s1.top();
        s1.pop();
        cout << current->value << " ";
        current = current->right;
    }
}

int main(int argc, char **argv)
{
    int n, data;
    cin >> n;

    node *root = NULL;
    for (int i = 0; i < n; i++)
    {
        cin >> data;
        node *newNode = new node;
        newNode->value = data;
        newNode->left = NULL;
        newNode->right = NULL;
        insertNode(&root, newNode);
    }
    in_order_traversal(root);
    cout << "\n";
    inorder_iterative(root);
    cout << "\n";
    return 0;
}