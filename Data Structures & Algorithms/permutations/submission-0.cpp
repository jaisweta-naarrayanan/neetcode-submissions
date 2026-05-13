class Solution {
public:
    void swap(vector<int> &nums, int i, int j){
        int t = nums[i];
        nums[i] = nums[j];
        nums[j] = t;
        return;
    }
    void backtrack(vector<int>& nums, int i, vector<vector<int>>& ans){
        if(i==nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int j=i; j<nums.size(); j++){
            swap(nums, i, j);
            backtrack(nums, i+1, ans);
            swap(nums, i, j);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        backtrack(nums, 0, ans);
        return ans;
    }
};
