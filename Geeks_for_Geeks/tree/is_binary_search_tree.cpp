#include <iostream>

using namespace std;

#define INT_MAX (10 * 10 * 10 * 10 * 10 * 10 * 10 * 10 * 10)
#define INT_MIN (-INT_MAX)

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

int findMax(node *root)
{
    // if (root == NULL)
    //     return INT_MIN;
    int left_max, right_max;
    left_max = INT_MIN;
    right_max = INT_MIN;
    if (root->left != NULL)
    {
        left_max = max(root->data, findMax(root->left));
    }
    if (root->right != NULL)
    {
        right_max = max(root->data, findMax(root->right));
    }
    return (max(max(root->data, left_max), right_max));
}

int findMin(node *root)
{
    int left_min, right_min;
    left_min = INT_MAX;
    right_min = INT_MAX;
    if (root->left != NULL)
    {
        left_min = min(root->data, findMin(root->left));
    }
    if (root->right != NULL)
    {
        right_min = min(root->data, findMin(root->right));
    }
    return (min(min(root->data, left_min), right_min));
}

bool isBST(node *root)
{
    if (root == NULL)
        return 1;
    else
    {
        int left_max, right_max;
        left_max = (root->left == NULL) ? INT_MIN : max((root->left)->data, findMax(root->left));
        right_max = (root->right == NULL) ? INT_MAX : min((root->right)->data, findMin(root->right));
        if (left_max < root->data && right_max > root->data)
        {
            if (isBST(root->left) && isBST(root->right))
                return 1;
            else
                return 0;
        }
        else
            return 0;
    }
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

    // preOrder_traversal(root);

    cout << isBST(root) << "\n";
    return 0;
}