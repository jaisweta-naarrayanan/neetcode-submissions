class Solution {
public:
    int findDuplicate(vector<int>& nums) {
       int n = nums.size();
       vector<int> arr(n,0);
       for(int i:nums){
            if(arr[i]!=0)
                return i;
            arr[i]++;
       }
       return -1;
    }
};
