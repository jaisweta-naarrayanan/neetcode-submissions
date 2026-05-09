class Solution {
public:
    bool canJump(vector<int>& nums) {
        int farthest = 0;
        int n = nums.size();
        //if(nums[0] == 0) return (n==1)? true:false;
        for(int i=0; i<n; i++){
            if(farthest >= n-1)
                return true;
            if(i>farthest) return false;     
            farthest = max(farthest, i+nums[i]);    
        }
        return false;
    }
};
