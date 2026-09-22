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
    int getdepth(TreeNode* node, bool &isBal){
        if(!isBal) return 0;
        if(!node) return 0;
        int ld = getdepth(node->left, isBal);
        int rd = getdepth(node->right, isBal);
        if(abs(ld-rd) > 1) isBal = false;
        return 1 + max(ld,rd); 
    }
    bool isBalanced(TreeNode* root) {
        if(!root)
            return true;
        bool isBal = true;
        getdepth(root, isBal);
        return isBal;
    }
};
