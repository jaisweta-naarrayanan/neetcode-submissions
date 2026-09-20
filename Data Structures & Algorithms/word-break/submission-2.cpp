class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        vector<bool> dp(n+1, false);
        dp[0] = true;
        unordered_set<string> dict;
        for(auto w:wordDict) dict.insert(w);

        for(int i=1; i<=n; i++){ // end
            for(int j=0; j<=i; j++){ //st
                string ss= s.substr(j, i-j);
                // cout<<ss<<" ";
                if(dp[j] && dict.count(ss) != 0){ // when we find a new word ending at i, starting from any j, for it to be valid, we have to be sure that there's a word ending at j too => so check dp[j]!!
                    dp[i] = true;
                    // cout<<dp[i]<<endl;;
                    break;
                }   
            }
        }
        return dp[n];
    }
};
