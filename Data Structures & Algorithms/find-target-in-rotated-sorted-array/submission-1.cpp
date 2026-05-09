class Solution {
public:
    int binarySearch(vector<int> &nums, int l, int r, int t){
        
        while(l<=r){
            int m = l + (r-l)/2;
            if(nums[m] == t)
                return m;
            else if(nums[m] < t)
                l = m+1;
            else r = m-1;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        // find pivot;
        int n = nums.size();
        if(n==1) return (nums[0] == target)? 0:-1;
        int l=0, r=n-1;
        while(l<r){
            int m = l + (r-l)/2;
            if(nums[m] < nums[r]) // sorted
                r = m;
            else
                l = m+1;
        }
        cout<<l<<"...";
        // l is the smallest ele starting
        int ans = -1;
        if((l>0 && target > nums[l-1]) || target < nums[l]) return -1;
        if(l>0 && target >= nums[0] && target<= nums[l-1])
            ans = binarySearch(nums, 0, l-1, target);
        else if(target >= nums[l] && target<= nums[n-1])
            ans = binarySearch(nums, l, n-1, target);
        return ans;
    }
};
