class Solution {
public:

    int find(int i, vector<int>& root){
        if(i == root[i]) return i;
        return root[i] = find(root[i], root);
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> root(n);
        iota(root.begin(), root.end(),0);
        for(auto e:edges){
            int u=e[0]-1, v=e[1]-1;
            int ru = find(u,root), rv =find(v,root);
            if(ru == rv)
                return {u+1,v+1}; 
            else{
                root[rv] = ru;
            }
        }
        return {};
    }
};
