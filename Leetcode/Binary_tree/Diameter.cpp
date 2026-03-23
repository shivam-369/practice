#include <iostream>
using namespace std;

 struct TreeNode {
    int val;
    TreeNode*  left;
    TreeNode*  right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode*  left, TreeNode*  right) : val(x), left(left), right(right) {}
};

int height(TreeNode* root){
    if(root == NULL)
        return 0;
    return max(height(root->left), height(root->right)) + 1;
}

int diameterOfBinaryTree(TreeNode* root) {
    if(root == NULL)
        return 0;
    if(root->left == NULL && root->right == NULL)
        return 0;
    int leftDiameter = diameterOfBinaryTree(root->left);
    int rightDiameter = diameterOfBinaryTree(root->right);
    
    return max(max(leftDiameter, rightDiameter), height(root->left) + height(root->right));

}


int main(){


    return 0;
}