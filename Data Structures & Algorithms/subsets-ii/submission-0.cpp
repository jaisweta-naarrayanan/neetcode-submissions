class Solution {
public:
    void backtrack(vector<int>& nums, int i, vector<int>& curr, vector<vector<int>>& ans){
        ans.push_back(curr);
        for(int j=i; j<nums.size(); j++){
            if(j>i && nums[j] == nums[j-1])
                continue;

            curr.push_back(nums[j]);
            backtrack(nums, j+1, curr, ans);
            curr.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        sort(nums.begin(), nums.end());
        backtrack(nums, 0, curr, ans);
        return ans;
    }
};
