class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int maxlen = 0;
        unordered_set<int> s(nums.begin(), nums.end());
        for(int i:nums){
            if(s.find(i-1) == s.end()){ // then i is the smallest in that sequence
                int len = 1;
                while(s.find(i+len) != s.end() ){
                    len++;
                    //i++;
                }
                maxlen = max(maxlen, len);
            }
        }
        return maxlen;
    }
};
