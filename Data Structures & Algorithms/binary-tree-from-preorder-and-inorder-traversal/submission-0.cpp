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
    TreeNode* build(vector<int>& pre, int sp, int ep, vector<int>& in, int si, int ei, unordered_map<int,int> &mp){
        if(si>ei || sp>ep) return NULL;
        int idx = mp[pre[sp]];
        int dis = idx - si;
        TreeNode* node = new TreeNode(in[idx]);
        node->left = build(pre, sp+1, sp+dis, in, si, idx-1, mp);
        node->right = build(pre, sp+dis+1, ep, in, idx+1, ei, mp);
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        unordered_map<int,int> mp;
        for(int i=0; i<n; i++) mp[inorder[i]] = i; 
        return build(preorder, 0, n-1, inorder, 0, n-1, mp);

        //return preorder[0];
    }
};
