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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans = "";
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            if(curr){
                ans += (to_string(curr->val));
                ans.push_back(',');
                //if(curr->left) 
                    q.push(curr->left);
                //if(curr->right) 
                    q.push(curr->right);
            }
            else ans += ("x,"); 
        }
        cout<<ans;
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        string s;
        vector<string> arr;
        while(getline(ss, s, ','))
            arr.push_back(s);

        if(arr[0] == "x") return NULL;
        queue<TreeNode*> q;
        TreeNode* root= new TreeNode(stoi(arr[0]));
        //cout<<" root: "<<root->val<<" ";
        q.push(root);
        for(int i=1; i+1 <arr.size(); ){
            TreeNode* curr = q.front();
            q.pop();
            if(arr[i] != "x"){
                TreeNode* node = new TreeNode(stoi(arr[i]));
                curr->left = node;
                q.push(node);
            }
            if(arr[i+1] != "x"){
                TreeNode* node = new TreeNode(stoi(arr[i+1]));
                curr->right = node;
                q.push(node);
            }
            i+=2;
        }
        return root;
    }
};
