class Solution {
public:
    void getsubset(vector<int>& nums, int i, int target, vector<int>& curr, vector<vector<int>>& ans){
        if(target == 0){
            ans.push_back(curr);
            return;
        }
        if(i<0 || target<0)
            return;
        
        curr.push_back(nums[i]);
        getsubset(nums, i, target-nums[i], curr, ans);
        curr.pop_back();
        getsubset(nums, i-1, target, curr, ans);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        vector<vector<int>> ans;
        vector<int> curr;
        getsubset(nums, nums.size()-1, target, curr, ans);
        return ans;
    }
};
