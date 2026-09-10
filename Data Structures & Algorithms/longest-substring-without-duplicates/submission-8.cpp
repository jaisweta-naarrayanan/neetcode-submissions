class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp;
        int n = s.length();
        int maxlen = 0, st=0, e=0;
        for(int i=0; i<n; i++){
            if(mp.count(s[i])==0 || mp[s[i]] < st)
                e=i;
            else    st=mp[s[i]]+1;
            mp[s[i]] = i; //update latest pos for that char
            maxlen = max(maxlen, e-st+1);
        }
        return maxlen;
    }
};
