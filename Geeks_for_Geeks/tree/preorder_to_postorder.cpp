#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
};

void preorder_traversal(node *root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";
    preorder_traversal(root->left);
    preorder_traversal(root->right);
}

void inorder_traversal(node *root)
{
    if (root == NULL)
        return;

    inorder_traversal(root->left);
    cout << root->data << " ";
    inorder_traversal(root->right);
}

void postorder_traversal(node *root)
{
    if (root == NULL)
        return;

    postorder_traversal(root->left);
    postorder_traversal(root->right);
    cout << root->data << " ";
}

node *pre_to_post(vector<int> preorder)
{
    if (preorder.size() <= 0)
        return NULL;

    vector<int> inorder = preorder;

    sort(inorder.begin(), inorder.end());

    node *root = new node;
    root->data = preorder[0];
    root->left = NULL;
    root->right = NULL;

    int index = 0;

    for (int i = 0; i < inorder.size(); i++)
    {
        if (inorder[i] == preorder[0])
        {
            index = i;
            break;
        }
    }

    vector<int> temp_preorder;

    if (index != 0)
    {
        for (int i = 1; i <= index; i++)
        {
            temp_preorder.push_back(preorder[i]);
        }
        root->left = pre_to_post(temp_preorder);
    }

    temp_preorder.resize(0);

    for (int i = index + 1; i < preorder.size(); i++)
    {
        temp_preorder.push_back(preorder[i]);
    }

    root->right = pre_to_post(temp_preorder);

    return root;
}

int main(int argc, char **argv)
{
    int n;
    cin >> n;

    vector<int> preorder(n);

    for (int i = 0; i < n; i++)
    {
        cin >> preorder[i];
    }

    node *root = pre_to_post(preorder);

    preorder_traversal(root);
    cout << "\n";
    inorder_traversal(root);
    cout << "\n";
    postorder_traversal(root);
    cout << "\n";

    return 0;
}