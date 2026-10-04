class Solution {
public:
    void bfs(vector<vector<int>>& h, queue<pair<int,int>>& q, vector<vector<int>>& v){
        int n = h.size(), m=h[0].size();
        int dx[] = {-1,0,0,1};
        int dy[] = {0,-1,1,0};
        while(!q.empty()){
            auto [i,j] = q.front();
            v[i][j] = 1;
            q.pop();
            for(int k=0; k<4; k++){
                int ni = i+dx[k];
                int nj = j+dy[k];
                if(ni<0 || ni>=n || nj<0 || nj>=m || h[ni][nj]<h[i][j] || v[ni][nj]) continue;
                //v[ni][nj] = 1;
                q.push({ni,nj});
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) {
        int n=h.size(), m=h[0].size();
        vector<vector<int>> ans;
        vector<vector<int>> vp(n, vector<int>(m,0)), va(n, vector<int>(m,0));
        queue<pair<int,int>> qp, qa;
        for(int j=0; j<m; j++){
            qp.push({0,j});
            qa.push({n-1,j});
        }
        for(int i=0; i<n; i++){
            qp.push({i,0});
            qa.push({i,m-1});
        } 
        bfs(h,qp,vp);
        bfs(h,qa,va);

        // for(int j=0; j<m; j++){
        //     va[n-1][j] = 1;
        //     qa.push({n-1,j});
        // }
        // for(int i=0; i<n-1; i++){
        //     va[i][m-1] = 1;
        //     qa.push({i,m-1});
        // } 
        // bfs(h,qa,va);

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(vp[i][j] && va[i][j])
                    ans.push_back({i,j});
            }
        }
        return ans;
    }
};
