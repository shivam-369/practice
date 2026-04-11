#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };





TreeNode* build(vector<int>& preorder, vector<int>& inorder, int preRootIndex, int start, int end) {

    cout << preRootIndex << " " << start << " " << end << "\n";
    if(start >= end)
        return NULL;

    
    auto ptr = find(inorder.begin() + start, inorder.begin() + end, preorder[preRootIndex]);

    int leftCount = (ptr - inorder.begin() - start);
    cout << "left count " << leftCount << "\n";
    TreeNode * root = new TreeNode(preorder[preRootIndex]);
    root->left = build(preorder, inorder, preRootIndex + 1, start, start + leftCount);
    root->right = build(preorder, inorder, preRootIndex + leftCount + 1, start + leftCount + 1, end);

    return root;

}

// 3 9 20 15 7 - pre
// 9 3 15 20 7 - in

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

    if(preorder.size() == 0)
        return NULL;
    
    if(preorder.size() == 1){
        return new TreeNode(preorder[0]);
    }
    
    auto ptr = find(inorder.begin(), inorder.end(), preorder[0]);

    int leftCount = (ptr - inorder.begin());
    
    TreeNode * root = new TreeNode(preorder[0]);
    root->left = build(preorder, inorder, 1, 0, leftCount);
    root->right = build(preorder, inorder, leftCount + 1, leftCount + 1, preorder.size());

    return root;
    
}


void inorderTraversal(TreeNode* root){
   
    if(root == NULL)
        return;
    
    // cout << "inorder traversal " << root->val << "\n";   
    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}


int main(){

    int n;
    cin >> n;
    vector <int> preorder(n);
    vector <int> inorder(n);

    for(int i = 0; i < n; i++){
        cin >> preorder[i];
    }

    for(int i = 0; i < n; i++){
        cin >> inorder[i];
    }

    TreeNode* root = buildTree(preorder, inorder);

    inorderTraversal(root);
    // cout << (find(inorder.begin(), inorder.end(), preorder[0]) - inorder.begin()) << "\n";

    // cout << (find(inorder.begin() + 1, inorder.end(), preorder[0]) - (inorder.begin() + 1)) << "\n";
    cout << "\n";
    return 0;
}