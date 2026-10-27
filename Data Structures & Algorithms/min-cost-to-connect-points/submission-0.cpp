class Solution {
public:
    #define PII pair<int,int>
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<int> vis(n,0);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minh;
        minh.push({0,0}); // w, u's index
        int cost = 0;
        while(!minh.empty()){
            int w = minh.top().first;
            int u = minh.top().second;
            minh.pop();
            
            if(vis[u]) continue;
            vis[u]=1;
            cost += w;
            for(int v=0; v<n; v++){
                if(vis[v]) continue;
                int x1 = points[u][0], y1 = points[u][1];
                int x2 = points[v][0], y2 = points[v][1];
                int d = abs(x1-x2) + abs(y1-y2);
                minh.push({d, v});
            }
        }
        return cost;
    }
};
