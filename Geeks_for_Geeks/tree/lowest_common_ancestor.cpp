#include <iostream>
#include <vector>
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

void dfs(node *root, vector<int> &path, int data)
{
    if (root == NULL)
        return;

    path.push_back(root->value);
    if (root->value == data)
        return;
    dfs(root->left, path, data);
    // path.pop_back();
    dfs(root->right, path, data);
}

int LCA(node *root, int data1, int data2)
{
    vector<int> path1, path2;
    path1.push_back(root->value);
    path2.push_back(root->value);
}

int main(int argc, char **argv)
{
    int n, data1, data2;
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
    cout << "Enter data of which ancestors has to be find: ";
    cin >> data1 >> data2;
    cout << "\n";
    return 0;
}