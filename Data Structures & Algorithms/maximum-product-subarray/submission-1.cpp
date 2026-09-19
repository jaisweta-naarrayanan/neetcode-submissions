class Solution {
public:
    // int getDP(vector<int>& maxp, vector<int>& minp, vector<int>& dp, vector<int>& nums, int i){
    //     if(i<0){
    //         return 1; 
    //     }
    //     if(maxp[i] != -1) return maxp[i];
    //     if(minp[i] != -1) return minp[i];
    //     int temp = getDP(maxp, minp, nums, i-1);
    //     maxp[i] = max(nums[i]*maxp[i-1], nums[i]*minp[i+1]);
    //     minp[i] = min(nums[i]*maxp[i+1], nums[i]*minp[i+1]);

    //     return dp[i] = max(maxp[i], minp[i]);
    // }
    int maxProduct(vector<int>& nums) {
        int n= nums.size();
        //vector<int> maxp(n, 1); minp(n, 1), dp(n,1);
        // return getDP(maxp, minp, nums, n-1);
        //dp[0] = nums[0]; minp= = nums[0]; maxp = nums[0];
        int mxp = 1, mnp = 1;
        int ans = nums[0];
        for(int i=0; i<n; i++){
            int temp = mxp*nums[i];
            mxp = max(nums[i], max(mxp * nums[i], mnp * nums[i]));
            mnp = min(nums[i], min(temp, mnp * nums[i]));
            ans = max(ans, mxp);
            //cout<<nums[i]<<" mxp:"<<mxp<<" mnp:"<<mnp<<" ans:"<<ans<<endl;
        }
        return ans;
    }
};
