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
    int preorder(TreeNode* node, int maxval){
        if(!node) return 0;
        int res = 0;
        if(node->val >= maxval) res+=1;
        maxval = max(maxval, node->val);
        res+= preorder(node->left, maxval);
        res+= preorder(node->right, maxval);
        return res;
    }
    int goodNodes(TreeNode* root) {
        // int cnt=1;
        // preorder;
        // vector<int> pre;
        return preorder(root, root->val);
    }
};
