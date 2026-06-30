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
    int maxSum = 0;

    struct Info {
        bool isBST;
        int sum;
        int minVal;
        int maxVal;
    };

    Info dfs(TreeNode* root) {
        if (!root)
            return {true, 0, INT_MAX, INT_MIN};

        auto L = dfs(root->left);
        auto R = dfs(root->right);

        if (L.isBST && R.isBST &&
            root->val > L.maxVal &&
            root->val < R.minVal) {

            int currSum = L.sum + R.sum + root->val;

            maxSum = max(maxSum, currSum);

            return {
                true,
                currSum,
                min(root->val, L.minVal),
                max(root->val, R.maxVal)
            };
        }

        return {false, 0, 0, 0};
    }

    int maxSumBST(TreeNode* root) {
        dfs(root);
        return maxSum;
    }
};
