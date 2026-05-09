class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>s;
        int ans=0;
        for(int i:nums) 
            s.insert(i);
        for(int i:s){
            int curr=i;
            int cnt=1;
            while(s.count(curr+1)!=0){
                cnt++;
                curr++;  
            }
            ans = max(ans,cnt);
        }
        return ans;
    }
};
