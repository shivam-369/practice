#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector <int> preOrder(TreeNode* root){
        vector <int> traversal;
        if(root != NULL){
            traversal.push_back(root->val);
            vector<int> leftTraversal = preOrder(root->left);
            vector<int> rightTraversal = preOrder(root->right);
            for(int i = 0; i < leftTraversal.size(); i++){
                traversal.push_back(leftTraversal[i]);
            }
            for(int i = 0; i < rightTraversal.size(); i++){
                traversal.push_back(rightTraversal[i]);
            }
        }
        return traversal;
    }

    TreeNode* constructTree(int num, TreeNode* root){
        if(root == NULL){
            return new TreeNode(num);
        }else if(num < root->val){
            root->left = constructTree(num, root->left);
        }else{
            root->right = constructTree(num, root->right);
        } 
        return root;
    }

    vector<TreeNode*> generateTrees(int n) {

        set<vector<int>> BSTs;
        vector <TreeNode *> answer;
        vector <int> sequence(n);
        int currSize, newSize;
        for(int i = 1; i <= n; i++){
            sequence[i - 1] = (i);
        }

        TreeNode* root = NULL;

        do{
            root = NULL;
            for(int i = 0; i < sequence.size(); i++){
                root = constructTree(sequence[i], root);
            }
            currSize = BSTs.size();
            BSTs.insert(preOrder(root));
            newSize = BSTs.size();
            if(newSize != currSize){
                answer.push_back(root);
            }
        }while(next_permutation(sequence.begin(), sequence.end()));

        return answer;
    }


int main(){
    int n;
    cin >> n;

    vector <TreeNode* > BSTs = generateTrees(n);
    vector <int> traversal;
    for(int i = 0; i < BSTs.size(); i++){
        traversal = preOrder(BSTs[i]);
        cout << "size: " << traversal.size() << "\n";
        for(int j = 0; j < traversal.size(); j++){
            cout << traversal[j] << " ";
        }
        cout << "\n";
    }

    return 0;
}