class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> premul(n), sufmul(n), ans(n);
        premul[0]=nums[0]; sufmul[n-1]=nums[n-1];
        for(int i=1; i<n; i++)
            premul[i] = premul[i-1] * nums[i];

        for(int i=n-2; i>=0; i--)
            sufmul[i] = sufmul[i+1] * nums[i];
    
        ans[0]=sufmul[1];
        ans[n-1] = premul[n-2];
        for(int i=1; i<n-1; i++){
            ans[i] = premul[i-1]*sufmul[i+1]; 
        }
        return ans;
    }
};
