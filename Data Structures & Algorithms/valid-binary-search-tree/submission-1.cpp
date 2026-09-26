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
    //bool isValid = true;
    bool isValid(TreeNode* node, int s, int e){
        if(!node) return true;
        if((node->val < s) || (node->val > e)){
            return false;
        }
        return isValid(node->left, s, node->val -1) && isValid(node->right, node->val +1, e);
    }
    bool isValidBST(TreeNode* root) {
        return isValid(root, INT_MIN, INT_MAX);
    }
};
