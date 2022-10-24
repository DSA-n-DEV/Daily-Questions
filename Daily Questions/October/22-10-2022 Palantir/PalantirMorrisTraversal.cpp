#include <bits/stdc++.h> 
using namespace std;

class TreeNode{
    public:
        int val;
        TreeNode* left;
        TreeNode* right;
};

TreeNode* newN(int val){
    TreeNode* temp = new TreeNode();
    temp->val = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

vector<int> morris(TreeNode* root) {
        vector<int> nodes;
        while (root) {
            if (root -> left) {
                TreeNode* pre = root -> left;
                while (pre -> right && pre -> right != root) {
                    pre = pre -> right;
                }
                if (!pre -> right) {
                    pre -> right = root;
                    root = root -> left;
                } else {
                    pre -> right = NULL;
                    nodes.push_back(root -> val);
                    root = root -> right;
                }
            } else {
                nodes.push_back(root -> val);
                root = root -> right;
            }
        }
        return nodes;
    }


int main(){
    TreeNode* root = NULL; 
  
    root = newN(8); 
    root->left = newN(4); 
    root->right = newN(10); 
  
    root->left->left = newN(2); 
    root->left->right = newN(6); 
  
    root->right->left = newN(9); 
    root->right->right = newN(11); 
  
    root->left->left->left = newN(1); 
    root->left->left->right = newN(3); 
  
    root->left->right->left = newN(5); 
    root->left->right->right = newN(7);
    vector<int> ans = morris(root);
    for(int i = 0;i < ans.size();i++) cout << ans[i] << " ";
}