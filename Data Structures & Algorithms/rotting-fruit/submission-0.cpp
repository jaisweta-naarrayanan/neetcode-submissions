class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        queue<pair<int,int>> q;
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                if(grid[i][j] == 2) q.push({i,j});
        int t=0;
        int dx[] = {-1, 0, 0, 1};
        int dy[] = {0, -1, 1, 0};
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                for(int k=0; k<4; k++){
                    int ni = i + dx[k];
                    int nj = j + dy[k];
                    if(ni<0 || ni>=n || nj<0 || nj>=m || grid[ni][nj]!=1) continue;
                    grid[ni][nj] = 2;
                    q.push({ni,nj});   
                }
            }
            if(!q.empty()) t++; // imp check
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++)
                if(grid[i][j] == 1)
                    return -1;
        }
        return t;
    }
};
