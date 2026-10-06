class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        int m = edges.size();
        if(n-1!=m) return false;

        // cycle detection - how?? bipartitte???
        unordered_map<int, vector<int>> adj;
        vector<int> vis(n,0), col(n,0);
        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        queue<int> q;
        q.push(0);
        col[0] = 1;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            
            for(int v:adj[u]){
                if(col[v]==col[u]) return false;
                if(col[v]==0){
                    col[v] = 3-col[u];
                    q.push(v);
                }
            }
        }
        for(int i:col) if(i==0) return false;
        return true;
    }
};
