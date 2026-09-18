class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        if(n==2) return max(nums[0], nums[1]);
        //if(n==3) return max(nums[1], nums[0]+nums[2]);
        int rob1=0, rob2=nums[0];
        for(int i=2; i<=n-1; i++){ // 0th house to n-2th house
            int temp = max(nums[i-1] + rob1, rob2);
            rob1 = rob2;
            rob2 = temp;
        }
        int ans = rob2; 
        rob1=0, rob2=nums[1];
        for(int i=3; i<=n; i++){
            int temp = max(nums[i-1] + rob1, rob2);
            cout<<temp<<" ";
            rob1 = rob2;
            rob2 = temp;
        }
        return max(ans,rob2);
    }
};
