class Solution {
public:
    void getsubsets(vector<int>& nums, int i,vector<int>& curr, vector<vector<int>>& ans){
        if(i<0){
            ans.push_back(curr);
            return;
        }
        curr.push_back(nums[i]);
        getsubsets(nums,i-1, curr, ans);
        curr.pop_back();
        getsubsets(nums,i-1, curr, ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        int n = nums.size();
        getsubsets(nums, n-1, curr, ans);
        return ans;
    }
};
