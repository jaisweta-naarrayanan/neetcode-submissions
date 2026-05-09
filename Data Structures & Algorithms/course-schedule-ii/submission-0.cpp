class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>> adj(n);
        vector<int> indegree(n,0);
        vector<int> ans;
        for(auto e:prerequisites){
            adj[e[1]].push_back(e[0]);
            indegree[e[0]]++;
        }
        queue<int> q;

        for(int i=0; i<n; i++){
            if(indegree[i]==0)
                q.push(i);
        }
        while(!q.empty()){
            int u = q.front();
            q.pop();
            ans.push_back(u);
            for(auto v:adj[u]){
                indegree[v]--;
                if(indegree[v]==0)
                    q.push(v);
            }
        }
        if(ans.size()<n) return {};
        return ans;
    }
};
