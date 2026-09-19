class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size(), m = amount;
        vector<vector<int>> dp(n+1, vector<int> (m+1, INT_MAX-1));
        for(int j=0; j<=m; j++) dp[0][j] = INT_MAX-1;
        for(int i=0; i<=n; i++) dp[i][0] = 0;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                // not take
                dp[i][j] = dp[i-1][j];
                if(coins[i-1] <= j && dp[i][j-coins[i-1]] != INT_MAX-1)
                    dp[i][j] = min(dp[i][j], 1+dp[i][j-coins[i-1]]);
            }
        }
        return (dp[n][m] == INT_MAX-1)? -1: dp[n][m];
    }
};
