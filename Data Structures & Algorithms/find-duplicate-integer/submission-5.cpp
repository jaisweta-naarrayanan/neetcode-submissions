class Solution {
public:
    int findDuplicate(vector<int>& nums) {
       int n = nums.size();
    //    vector<int> arr(n,0);
    //    for(int i:nums){
    //         if(arr[i]!=0)
    //             return i;
    //         arr[i]++;
    //    }
    //    return -1;
        int s = 0, f=0;
        while(true){
            s = nums[s];
            f = nums[nums[f]];
            if(s==f)
                break;
        }
        int s2 = 0;
        while(s!=s2){
            s = nums[s];
            s2 = nums[s2];
        }
        return s2;
    }
};
