#include <iostream>
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

vector<vector<int>> pathToSum(node *root, int targetSum, vector<int> path)
{
    vector<vector<int>> paths;
    if (root == NULL)
    {
        path.clear();
        paths.push_back(path);
        return paths;
    }

    path.push_back(root->data);
    if (root->data == targetSum)
    {
        if (root->left == NULL && root->right == NULL)
        {
            paths.push_back(path);
            return paths;
        }
    }

    vector<vector<int>> path2 = pathToSum(root->left, targetSum - root->data, path);

    for (auto p : path2)
    {
        if (p.size() > 0)
        {
            paths.push_back(p);
        }
    }
    path2 = pathToSum(root->right, targetSum - root->data, path);

    for (auto p : path2)
    {
        if (p.size() > 0)
        {
            paths.push_back(p);
        }
    }
    return paths;
}

vector<vector<int>> pathSum(node *root, int targetSum)
{
    vector<int> path;
    vector<vector<int>> paths = pathToSum(root, targetSum, path);

    for (auto ptr = paths.begin(); ptr != paths.end(); ptr++)
    {
        if ((*ptr).size() <= 0)
        {
            paths.erase(ptr);
            ptr--;
        }
    }

    return paths;
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

    return 0;
}