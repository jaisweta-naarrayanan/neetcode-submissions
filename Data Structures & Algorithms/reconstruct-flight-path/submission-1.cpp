class Solution {
public:
    void dfs(string u, unordered_map<string, vector<string>> &adj, 
    vector<string> &path){ 
        while(!adj[u].empty()){ 
            string v = adj[u].back(); // getting lexi small
            adj[u].pop_back(); // cuz we can pop it in vec (no need for visited flag)
            dfs(v, adj, path);
        }
        path.push_back(u); // post order -> so reverse it
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        /* euclidean path finding -> 
            known : path defo exists -> skip euclidean path/circuit check
            return lexi small; start is given - "JFK" else to find start look for out-in = 1 node;
        */
        int e = tickets.size();
        unordered_map<string, vector<string>> adj;

        for(auto &t:tickets){
            adj[t[0]].push_back(t[1]);
        }
        for(auto &[k,v]:adj){
            // sort(v.begin(), v.end());
            sort(v.begin(), v.end(), [](const auto &s1, const auto &s2){
                return s1>s2;
            });
        }
        string u = "JFK";
        vector<string> path;
        dfs(u, adj, path);
        reverse(path.begin(), path.end());
        return path;
    }
};
