class Solution {
public:
    void twoSum(vector<int> &nums, int k, int i, int j, int tar, vector<vector<int>> &ans){
        while(i<j){
            // if(i>0 && nums[i-1] == nums[i]){
            //     i++;
            //     continue;
            // }
            int sum = nums[i] + nums[j];
            if(sum == tar){
                ans.push_back({nums[k], nums[i], nums[j]});
               
                while(i<j && nums[i+1] == nums[i]) i++;
                while(i<j && nums[j-1] == nums[j]) j--;
                i++; j--;
            }
            else if(sum < tar){
                i++;
            }
            else j--;
        }
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        for(int i=0; i<n-2; i++){
            if(i>0 && nums[i-1] == nums[i])
                continue;
            if(nums[i]>0){
                break;
            }
            else{
                twoSum(nums,i,i+1,n-1,0-nums[i],ans);
            }  
        }
        return ans;
    }
};
