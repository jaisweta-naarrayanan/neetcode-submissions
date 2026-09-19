class Solution {
public:
    // int getcnt(vectpr<int>& dp, string& s, int i, int n){
    //     if(i==n) return 0;
    //     if(dp[i] != )
    // }
    int numDecodings(string s) {
        int n = s.length();
        int ans = 0;
        vector<int> dp(n+1, 0);
        dp[n] = 1;
        for(int i=n-1; i>=0; i--){
            if(s[i] == '0') dp[i] = 0;
            else dp[i] = dp[i+1];
            if( i+1 < n && (s[i] == '1' || s[i]=='2' && s[i+1] <= '6')) 
                dp[i] += dp[i+2]; 
        }
        //for(itn i)
        //ans = getcnt(dp, s, 0, n);
        return dp[0];
    }
};
