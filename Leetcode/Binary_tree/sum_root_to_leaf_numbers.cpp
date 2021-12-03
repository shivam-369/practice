#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

vector<int> values;

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

void dfs(node *root, int curr)
{
    if (root == NULL)
        return;

    curr *= 10;
    curr += (root->data);

    if (root->left == NULL && root->right == NULL)
        values.push_back(curr);

    dfs(root->left, curr);
    dfs(root->right, curr);
}

int sumNumbers(node *root)
{
    int ans = 0;

    dfs(root, 0);
    for (int i = 0; i < values.size(); i++)
    {
        ans += values[i];
    }

    return ans;
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
    return 0;
}