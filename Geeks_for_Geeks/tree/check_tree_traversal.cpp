#include <iostream>
#include <vector>
using namespace std;

vector<int> generate_post_order(vector<int> preorder, vector<int> inorder)
{
    unsigned int length = preorder.size();
    vector<int> postorder(length);
}

int main(int argc, char **argv)
{
    int n;
    cin >> n;
    vector<int> preorder(n);
    vector<int> inorder(n);
    vector<int> postorder(n);

    for (int i = 0; i < n; i++)
    {
        cin >> preorder[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> inorder[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> postorder[i];
    }

    return 0;
}