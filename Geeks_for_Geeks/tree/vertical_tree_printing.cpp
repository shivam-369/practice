#include <iostream>
#include <math.h>
#include <algorithm>
#include <numeric>
#include <vector>
#include <map>
#include <set>

using namespace std;

#define ll long long
#define INT_MAX (10 * 10 * 10 * 10 * 10 * 10 * 10 * 10 * 10)
#define INT_MIN (-INT_MAX)

map<int, vector<int>> vertical_index;

struct node
{
    int value;
    node *left;
    node *right;
};

void BFS(vector<node *> &roots)
{
    if (roots.size() == 0)
        return;

    // vector<node *> nodes;
    for (int i = 0; i < roots.size(); i++)
    {
        cout << roots[i]->value << " ";

        if (roots[i]->left != NULL)
            roots.push_back(roots[i]->left);

        if (roots[i]->right != NULL)
            roots.push_back(roots[i]->right);
    }
}

void modified_BFS(vector<pair<node *, int>> &roots)
{
    if (roots.size() == 0)
        return;

    pair<node *, int> current;
    for (int ptr = 0; ptr < roots.size(); ptr++)
    {
        current = roots[ptr];
        vertical_index[current.second].push_back((current.first)->value);

        if ((current.first)->left != NULL)
            roots.push_back(make_pair((current.first)->left, current.second - 1));

        if ((current.first)->right != NULL)
            roots.push_back(make_pair((current.first)->right, current.second + 1));
    }
}

void pre_order_traversal(node *root)
{
    if (root == NULL)
        return;

    std::cout << root->value << " ";

    if (root->left != NULL)
        pre_order_traversal(root->left);

    if (root->right != NULL)
        pre_order_traversal(root->right);
}

void in_order_traversal(node *root)
{
    if (root == NULL)
        return;

    if (root->left != NULL)
        in_order_traversal(root->left);

    std::cout << root->value << " ";

    if (root->right != NULL)
        in_order_traversal(root->right);
}

void post_order_traversal(node *root)
{
    if (root == NULL)
        return;

    if (root->left != NULL)
        post_order_traversal(root->left);

    if (root->right != NULL)
        post_order_traversal(root->right);

    std::cout << root->value << " ";
}

void modified_preorder_traversal(node *root, int index)
{
    if (root == NULL)
        return;

    vertical_index[index].push_back(root->value);

    if (root->left != NULL)
        modified_preorder_traversal(root->left, index - 1);

    if (root->right != NULL)
        modified_preorder_traversal(root->right, index + 1);
}

void modified_inorder_traversal(node *root, int index)
{
    if (root == NULL)
        return;

    if (root->left != NULL)
        modified_inorder_traversal(root->left, index - 1);

    vertical_index[index].push_back(root->value);

    if (root->right != NULL)
        modified_inorder_traversal(root->right, index + 1);
}

void modified_postorder_traversal(node *root, int index)
{
    if (root == NULL)
        return;

    if (root->left != NULL)
        modified_postorder_traversal(root->left, index - 1);

    if (root->right != NULL)
        modified_postorder_traversal(root->right, index + 1);

    vertical_index[index].push_back(root->value);
}

void print_tree_vertically()
{
    for (auto ptr1 = vertical_index.begin(); ptr1 != vertical_index.end(); ptr1++)
    {
        for (auto ptr2 = (ptr1->second).begin(); ptr2 != (ptr1->second).end(); ptr2++)
        {
            cout << *ptr2 << " ";
        }
        cout << "\n";
    }
}

int main(int argc, char **argv)
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);
    int n, value;
    string side;
    cout << "enter number of nodes\n";
    cin >> n;
    node *parent = NULL;
    node *trvptr = NULL;
    node root;
    for (int i = 0; i < n; i++)
    {
        cout << "enter value to enter: ";
        cin >> value;
        cout << "\n";
        if (i == 0)
        {
            parent = NULL;
        }
        else
        {
            parent = &root;
            trvptr = parent;
        }
        while (trvptr != NULL)
        {
            cout << "enter which side to insert. For left type l and for right type r: ";
            cin >> side;
            cout << "\n";
            parent = trvptr;
            if (side == "l")
            {
                trvptr = trvptr->left;
            }
            else
            {
                trvptr = trvptr->right;
            }
        }
        if (parent == NULL)
        {
            parent = new node;
            parent->value = value;
            parent->left = NULL;
            parent->right = NULL;
            root = (*parent);
        }
        else
        {
            if (side == "l")
            {
                parent->left = new node;
                (parent->left)->value = value;
                (parent->left)->left = NULL;
                (parent->left)->right = NULL;
            }
            else
            {
                parent->right = new node;
                (parent->right)->value = value;
                (parent->right)->left = NULL;
                (parent->right)->right = NULL;
            }
        }
    }

    pre_order_traversal(&root);
    cout << "\n";

    in_order_traversal(&root);
    cout << "\n";

    post_order_traversal(&root);
    cout << "\n";

    vector<node *> roots(1, &root);
    BFS(roots);
    cout << "\n";

    modified_preorder_traversal(&root, 0);
    print_tree_vertically();
    vertical_index.clear();
    cout << "\n";

    modified_inorder_traversal(&root, 0);
    print_tree_vertically();
    cout << "\n";
    vertical_index.clear();

    modified_postorder_traversal(&root, 0);
    print_tree_vertically();
    vertical_index.clear();
    cout << "\n";

    vector<pair<node *, int>> nodes(1, make_pair(&root, 0));
    modified_BFS(nodes);
    // modified_BFS(vector<pair<node *, int>>(1, pair<node *, int>(&root, 0)));
    print_tree_vertically();
    cout << "\n";
    return 0;
}