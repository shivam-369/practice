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

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

    cout << "sizes " << inorder.size() << " " << postorder.size() << "\n";
    if(inorder.size() == 0){
        return NULL;
    }
    if(inorder.size() == 1)
        return new TreeNode(inorder[0]);
        
    
    TreeNode* root = new TreeNode(postorder[postorder.size() - 1]);
    auto itr = find(inorder.begin(), inorder.end(), postorder[postorder.size() - 1]);
    
    if(itr == inorder.begin()){
        root->left == NULL;
    }else{
        cout << "calling for left\n";
        vector <int> inorderTemp(inorder.begin(), itr);
        vector <int> postorderTemp(postorder.begin(), postorder.begin() + inorderTemp.size());
        root->left = buildTree(inorderTemp, postorderTemp);
    }
    if(itr == inorder.end() - 1){
        root->right = NULL;
    }else{
        cout << "calling for right\n";
        vector <int> inorderTemp(itr + 1, inorder.end());
        cout << "right begin position " << *(postorder.end() - 1 - inorderTemp.size()) << " " << *(postorder.end() - 2) << "\n";
        vector <int> postorderTemp(postorder.end() - 1 - inorderTemp.size(), postorder.end() - 1);
        root->right = buildTree(inorderTemp, postorderTemp);
    }
    return root;
}

void inorderTraversal(TreeNode* root){

    if(root == NULL)
        return;
    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}

int main()
{
    int n;
    cin >> n;
    vector <int> inorder(n), postorder(n);

    for(int i = 0; i < n; i++){
        cin >> inorder[i];
    }

    for(int i = 0; i < n; i++){
        cin >> postorder[i];
    }

    TreeNode* root = buildTree(inorder, postorder);
    inorderTraversal(root);

    return 0;
}