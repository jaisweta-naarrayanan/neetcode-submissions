class Solution {
public:
    void backtrack(vector<int>& nums, int target, int i, vector<int>& curr, vector<vector<int>>& ans){
        if(target == 0){
            ans.push_back(curr); 
            return;
        }
        //if (target < 0) return;

        for(int j=i; j<nums.size(); j++){
            if(target-nums[j] < 0)
                break;
            if(j>i && nums[j]==nums[j-1])
                continue;    
            curr.push_back(nums[j]);    
            backtrack(nums, target-nums[j], j+1, curr, ans);
            curr.pop_back();    
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        sort(candidates.begin(), candidates.end());
        vector<int> curr;
        backtrack(candidates, target, 0, curr, ans);
        return ans; //vector<vector<int>> (ans.begin(), ans.end());
    }
};
