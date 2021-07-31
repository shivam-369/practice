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

void postorder_iterative(node *root)
{
    node *temp;
    stack<node *> s1;
    stack<int> s2;
    s1.push(root);
    while (!s1.empty())
    {
        temp = s1.top();
        s1.pop();
        s2.push(temp->value);
        if (temp->left != NULL)
            s1.push(temp->left);
        if (temp->right != NULL)
            s1.push(temp->right);
    }

    while (!s2.empty())
    {
        cout << s2.top() << " ";
        s2.pop();
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

    post_order_traversal(root);
    cout << "\n";
    postorder_iterative(root);
    cout << "\n";
    return 0;
}