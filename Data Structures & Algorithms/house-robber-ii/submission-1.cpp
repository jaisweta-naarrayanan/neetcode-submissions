class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        if(n==2) return max(nums[0], nums[1]);
        return max(getdp(nums,0,n-2), getdp(nums,1,n-1));
    }

    int getdp(vector<int>& nums, int l, int r){

        int prev2=0, prev1=0;
        for(int i=l; i<=r; i++){
            int curr = max(prev1, nums[i] + prev2);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};
