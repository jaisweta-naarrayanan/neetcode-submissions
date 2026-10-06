class Solution {
public:
    void dfs(unordered_map<int, vector<int>>& adj, int u, vector<int>& vis){
        if(vis[u]) return;
        vis[u]=1;
        for(int v:adj[u]){
            dfs(adj,v,vis);
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int> vis(n,0);
        int cnt=0;
        for(int i=0; i<n; i++){
            if(!vis[i]){
                cnt++;
                dfs(adj, i, vis);
            }
        }
        return cnt;
    }
};
