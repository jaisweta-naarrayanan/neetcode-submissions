class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i=0, j=nums.size()-1, sum=0;
        vector<pair<int,int>> nump(nums.size());
        for(int i=0; i<nums.size(); i++)
            nump[i]={nums[i],i};
        sort(nump.begin(), nump.end());
        cout<<nump[i].first;
        while(i<j){
            sum = nump[i].first+nump[j].first;
            if(sum == target)
                return {min(nump[i].second,nump[j].second),             max(nump[i].second,nump[j].second)};
            else if(sum<target)
                i++;
            else j--;
        }
        return {-1,-1};
    }
};
