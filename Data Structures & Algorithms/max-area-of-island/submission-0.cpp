class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i, int j, int n, int m, int& cnt){
        if(i<0 || i>=n || j<0 || j>=m || grid[i][j]!=1) return;
        grid[i][j]=0;
        cnt++;
        int dx[] = {-1, 0, 0, 1}; // up, lft, rght, down
        int dy[] = {0, -1, 1, 0}; 
        for(int k=0; k<4; k++){
            int ni = i+dx[k];
            int nj = j+dy[k];
            dfs(grid, ni, nj, n, m, cnt);
        }
        return;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        int ans=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1){
                    int cnt=0;
                    dfs(grid, i, j, n, m, cnt);
                    ans = max(ans, cnt);
                }
            }
        }
        return ans;
    }
};
