/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void inorder_Traversal(TreeNode* root,vector<int> &arr){
        if(root==NULL){
            return ;
        }
        inorder_Traversal(root->left,arr);
        arr.push_back(root->val);
        inorder_Traversal(root->right,arr);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> v;
        inorder_Traversal(root,v);
        return v[k-1];
    }
};