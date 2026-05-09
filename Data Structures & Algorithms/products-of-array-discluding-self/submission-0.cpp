class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n), premul(n,1), sufmul(n,1);
        for(int i=0; i<n; i++){
            if(i==0){
                premul[i] = nums[i];
                continue;
            }
            premul[i]=premul[i-1]*nums[i];
        }
        for(int i=n-1; i>=0; i--){
            if(i==n-1){
                sufmul[i] = nums[i];
                continue;
            }
            sufmul[i]=sufmul[i+1]*nums[i];
        }
        ans[0]=sufmul[1];
        ans[n-1]=premul[n-2];
        for(int i=1; i<n-1; i++){
            ans[i] = premul[i-1]*sufmul[i+1];
        }
        return ans;
    }
};
