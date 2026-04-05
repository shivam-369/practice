#include <iostream>
#include <vector>
#include <stack>
using namespace std;



 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void insert(TreeNode *node, TreeNode** root){
    char position;
    if(*root == NULL){
        *root = node;
    }
    else{
        TreeNode* curr = *root;
        while(true){
            cout << "L or R? \n";
            cin >> position;
            if(position == 'L'){
                if(curr->left == NULL){
                    curr->left = node;
                    return;
                }
                curr = curr->left;
            }else{
                if(curr->right == NULL){
                    curr->right = node;
                    return;
                }
                curr = curr->right;
            }
        }
    }

}


void inorderRecursive(TreeNode* root){
    if(root ==  NULL)
        return;
    inorderRecursive(root->left);
    cout << root->val << " ";
    inorderRecursive(root->right);

}

 vector<int> inorderTraversal(TreeNode* root) {

    cout << "root null check " << (root == NULL) << "\n";
    vector <int> inorder;
    stack <TreeNode*> traversal;
    if(root == NULL)
        return inorder;
    TreeNode* curr = root;
    
    while(curr != NULL){

        while(curr->left != NULL){
            // cout << "curr value " << curr->val << "\n";
            traversal.push(curr);
            curr = curr->left;
        }
        inorder.push_back(curr->val);
        if(curr->right != NULL){
            cout << "setting curr to right " << curr->right->val << "\n";
            curr = curr->right;
        }else{
            if(traversal.empty() && curr->left == NULL && curr->right == NULL){
                curr = NULL;
           }
            while(!traversal.empty()){
                curr = traversal.top();
                inorder.push_back(curr->val);
                traversal.pop();
                if(curr->right != NULL){
                    curr = curr->right;
                    break;
                }
                curr = NULL;
            }
           
        }
    }

    return inorder;
    
}

int main(){

    int n, number;
    cin >> n;
    
    TreeNode* root = NULL;

    for(int i = 0; i < n; i++){
        cin >> number;
        TreeNode* node = new TreeNode(number);
        insert(node, &root); 
    }
    inorderRecursive(root);

    cout << "\n";
    vector <int> traversal = inorderTraversal(root);

    cout << "traversal size " << traversal.size() << "\n";
    for(int i = 0; i < traversal.size(); i++){
        cout << traversal[i] << " ";
    }
    cout << "\n";

    return 0;
}