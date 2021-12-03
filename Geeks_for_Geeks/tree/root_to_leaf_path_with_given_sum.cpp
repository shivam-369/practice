#include <iostream>
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

bool hasPathSum(node *root, int sum)
{
    if (root == NULL)
        return 0;

    if (root->value > sum)
        return 0;
    else if (root->value == sum)
    {
        if (root->left != NULL || root->right != NULL)
            return 0;
        return 1;
    }
    else
        return (hasPathSum(root->left, sum - root->value) || hasPathSum(root->right, sum - root->value));
}

int main(int argc, char **argv)
{
    int n;
    cin >> n;
    node *root = NULL;

    for (int i = 0; i < n; i++)
    {
        node *newNode = new node;
        cin >> newNode->value;
        newNode->left = NULL;
        newNode->right = NULL;
        insertNode(&root, newNode);
    }

    return 0;
}