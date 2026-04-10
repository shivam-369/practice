#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
     int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector <int> traversal;

void inorderTraversal(TreeNode* root){
    if(root == NULL)
        return;
    inorderTraversal(root->left);
    traversal.push_back(root->val);
    inorderTraversal(root->right);
}

bool isValidBST(TreeNode* root) {

    inorderTraversal(root);

    for(int i = 1; i < traversal.size(); i++){
        if(traversal[i] <= traversal[i - 1])
            return false;
    }
    return true;
}

int main(){



    return 0;
}