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
    int getmaxpath(TreeNode* node, int& ans){
        if(!node) return 0;
        int lsum = max(0, getmaxpath(node->left, ans));
        int rsum = max(0, getmaxpath(node->right, ans));
        ans = max(ans, node->val + lsum + rsum);
        return node->val + max(lsum,rsum);
    }
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        getmaxpath(root, ans);
        return ans;
    }
};
