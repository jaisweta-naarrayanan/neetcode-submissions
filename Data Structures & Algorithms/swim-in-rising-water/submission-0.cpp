class Solution {
public:
    #define PII pair<int,int>
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        priority_queue<pair<int,PII>, vector<pair<int,PII>>, greater<pair<int,PII>>> pq;
        vector<vector<int>> vis(n, vector<int> (m,0));
        pq.push({grid[0][0],{0,0}});
        vis[0][0] = 1;
        int ans = 0;
        int dx[] = {-1,0,0,1};
        int dy[] = {0,-1,1,0};
        while(!pq.empty()){
            int h = pq.top().first;
            int ui = pq.top().second.first;
            int uj = pq.top().second.second;
            pq.pop();
            ans = max(ans, h);
            if(ui==n-1 && uj==m-1) return ans;
            for(int k=0; k<4; k++){
                int vi = ui+dx[k];
                int vj = uj+dy[k];
                if(vi>=0 && vi<n && vj>=0 && vj<m && vis[vi][vj]==0){
                    pq.push({grid[vi][vj],{vi,vj}});
                    vis[vi][vj] = 1;
                }
            }
        }
        return ans;
    }
};
