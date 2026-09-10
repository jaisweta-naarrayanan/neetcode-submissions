class Solution {
public:
    int characterReplacement(string s, int k) {
        // unordered_map<char, pair<int,int>> mp;
        unordered_map<char, int> freq;
        int n=s.size(), maxlen=0, maxf=0;
        int st=0, e=0, len=0;
        for(int e = 0; e < n; e++) {
            freq[s[e]]++;
            maxf = max(maxf, freq[s[e]]);
            while((e - st + 1) - maxf > k) {
                freq[s[st]]--;
                st++;
            }
            maxlen = max(maxlen, (e - st + 1));
        }
        
        return maxlen;
    }
};
