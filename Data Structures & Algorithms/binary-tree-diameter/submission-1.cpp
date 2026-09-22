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
    int getdepth(TreeNode* node, int &maxdia){
        if(node == NULL) return 0;
        int ld = getdepth(node->left, maxdia);
        int rd = getdepth(node->right, maxdia);
        maxdia = max(maxdia, ld+rd);
        return 1 + max(ld, rd); //getdepth(root->left);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0; 
        int maxdia = 0;
        int d = getdepth(root, maxdia);
        // int rd = getdepth(root->right);
        return maxdia;//ld + rd;
    }
};
