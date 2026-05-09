class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp;
        int i=0;
        int ans=0;
        for(int j=0; j<s.size(); j++){
            if(mp.find(s[j]) == mp.end()){
                mp[s[j]] = j;
                ans = max(ans, j-i+1);
            }
            else{
                i = max(mp[s[j]] + 1,i);
                ans = max(ans, j-i+1);
                mp[s[j]] = j;
            }
        }
        return ans;
    }
};
