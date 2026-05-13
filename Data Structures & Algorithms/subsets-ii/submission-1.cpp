class Solution {
public:
    void backtrack(vector<int>& nums, int i, vector<int>& curr, vector<vector<int>>& ans){
        // ans.push_back(curr);
        // for(int j=i; j<nums.size(); j++){
        //     if(j>i && nums[j] == nums[j-1])
        //         continue;

        //     curr.push_back(nums[j]);
        //     backtrack(nums, j+1, curr, ans);
        //     curr.pop_back();
        // }
        if(i==nums.size()){
            ans.push_back(curr);
            return;
        }
        curr.push_back(nums[i]);
        backtrack(nums, i+1, curr, ans);
        curr.pop_back();
        while(i+1 < nums.size() && nums[i]==nums[i+1])
            i++;
        backtrack(nums, i+1, curr, ans);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        sort(nums.begin(), nums.end());
        backtrack(nums, 0, curr, ans);
        return ans;
    }
};
