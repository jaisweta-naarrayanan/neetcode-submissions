class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        if(n==2) return max(nums[0], nums[1]);

        //vector<int> dp(n+1, 0);
        // dp[1] = nums[0];
        int m2=0, m1=nums[0];
        for(int i=2; i<=n; i++){
            //dp[i] = max(nums[i-1] + dp[i-2], dp[i-1]);
            int temp = max(nums[i-1] + m2, m1);
            m2 = m1;
            m1 = temp;    
        }
        return m1;//dp[n];
    }
};
