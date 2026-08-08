class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root==NULL) return 0;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);  
        int depth = 1;

        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            if(temp==NULL){
                depth++;
                if(!q.empty())
                    q.push(NULL);
            }
            else{
                if(temp->left==NULL && temp->right==NULL) return depth;
                if(temp->left!=NULL) q.push(temp->left);
                if(temp->right!=NULL) q.push(temp->right);
            }
       
        }
        return depth;
    }
};
