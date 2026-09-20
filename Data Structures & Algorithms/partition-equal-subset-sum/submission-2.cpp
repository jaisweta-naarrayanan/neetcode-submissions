class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i:nums) sum+=i;
        if(sum%2) return false;
        sum /= 2;
        // vector<vector<bool>> dp(n+1, vector<bool>(sum+1, false));
        // dp[0][0] = true;
        // for(int i=1; i<=n; i++){
        //     for(int j=0; j<=sum; j++){
        //         if(j==0) {dp[i][j] = true; continue;}
        //         dp[i][j] = dp[i-1][j];
        //         if(nums[i-1] <= j){
        //             dp[i][j] = dp[i][j] || dp[i-1][j-nums[i-1]];
        //         }
        //     }
        // }
        // return dp[n][sum];

        vector<int> dp(sum+1, false);
        dp[0] = true;
        for(int i = 0; i<n; i++){
            for(int j=sum; j>=nums[i]; j--){
                //if(nums[i] <= j)
                    dp[j] = dp[j] || dp[j-nums[i]];
            }
        }
        return dp[sum];
    }
};
