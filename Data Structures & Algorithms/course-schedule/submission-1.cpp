class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // topological sort.
        int n = numCourses;
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(n), vis(n), ans;
        for(vector<int> v:prerequisites){
            adj[v[1]].push_back(v[0]);
            indegree[v[0]]++;
        }
        queue<int> q;
        for(int i=0; i<n; i++) if(indegree[i]==0) q.push(i);
        while(!q.empty()){
            int u = q.front();
            q.pop();
            vis[u]=1;
            ans.push_back(u);
            for(int v:adj[u]){
                if(!vis[v]){
                    indegree[v]--;
                    if(indegree[v]==0) q.push(v);
                }
            }
        }
        for(int i:ans) cout<<i<<", ";
        return ans.size()==n;
    }
};
