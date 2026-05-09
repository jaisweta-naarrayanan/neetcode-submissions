class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size(), ans = nums[0];
        if(n==1 || nums[0] < nums.back()) return nums[0];

        int l=0, r=n-1;
        while(l<r){
            int m = l + (r-l)/2;
            if(nums[m] < nums[r]){ // sorted
                // ans = nums[m];
                r = m;
            }
            else{ // go to unsorted
                l = m+1;
            }        
        }
        return nums[l];
    }
};
