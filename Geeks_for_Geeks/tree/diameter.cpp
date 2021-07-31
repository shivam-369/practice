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

int height(node *root)
{
    if (root == NULL)
        return 0;
    else
    {
        int left_height, right_height;
        left_height = height(root->left);
        right_height = height(root->right);
        return (max(left_height, right_height) + 1);
    }
}

int diameter(node *root)
{
    if (root == NULL)
        return 0;
    int left_height = height(root->left);
    int right_height = height(root->right);

    int left_diameter = diameter(root->left);
    int right_diameter = diameter(root->right);

    return (max(left_height + right_height + 1, max(left_diameter, right_diameter)));
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

    // cout << height(root) << "\n";
    cout << diameter(root) << "\n";
    return 0;
}