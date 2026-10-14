class Solution {
public:
    #define PII pair<int,int>
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<PII>> adj;
        for(vector<int> v:times){
            adj[v[0]].push_back({v[1], v[2]});
        }
        vector<int> dis(n+1,INT_MAX);
        priority_queue<PII, vector<PII>, greater<PII>> pq;
        pq.push({0,k});
        dis[k] = 0;
        while(!pq.empty()){
            auto [w,u] = pq.top();
            pq.pop();
            if(dis[u]<w) continue;
            // dis[u] = w;
            for(auto [v, wv]: adj[u]){
                if(dis[v] > dis[u] + wv){
                    dis[v] = dis[u] + wv;
                    pq.push({dis[v], v});
                }
            }
        }
        int mx = -1;
        for(int i=1; i<=n; i++){
            if(dis[i]==INT_MAX) return -1;
            mx = max(mx, dis[i]);
        }
        return mx;
    }
};
