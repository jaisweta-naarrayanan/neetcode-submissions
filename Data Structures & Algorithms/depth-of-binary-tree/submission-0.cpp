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
    int getDepth(TreeNode* node){
        if(!node) return 0;
        int ld = getDepth(node->left);
        int rd = getDepth(node->right);
        return 1 + max(ld, rd);
    }
    int maxDepth(TreeNode* root) {
        return getDepth(root);
    }
};
