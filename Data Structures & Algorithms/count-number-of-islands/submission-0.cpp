class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i, int j, int n, int m){
        if(i<0 || i>=n || j<0 || j>=m || grid[i][j] != '1') return;
        grid[i][j] = '2';
        int dx[] = {-1, 0, 0, 1};
        int dy[] = {0, -1, 1, 0};
        for(int k=0; k<4; k++){
            int ni = i+dx[k];
            int nj = j+dy[k];
            dfs(grid, ni, nj, n, m);
        }
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size(), m=grid[0].size();
        int cnt = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == '1'){
                    cnt++; 
                    dfs(grid, i, j, n, m);
                }
            }
        }
        return cnt;
    }
};
