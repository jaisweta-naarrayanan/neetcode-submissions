class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int n = triplets.size();
        vector<int> vis(n, 1);
        for(int i=0; i<n; i++){
            if(triplets[i][0] == target[0] 
            && triplets[i][1] == target[1]
            && triplets[i][2] == target[2]){
                return true;
            }
            else if(triplets[i][0] > target[0] 
            || triplets[i][1] > target[1]
            || triplets[i][2] > target[2])
            vis[i] = 0;
        }
        int maxa = -1, maxb = -1, maxc = -1;
        for(int i=0;i<n; i++){
            if(vis[i] == 1){
                maxa=max(maxa, triplets[i][0]);
                maxb=max(maxb, triplets[i][1]);
                maxc=max(maxc, triplets[i][2]);

                if(maxa== target[0] 
            && maxb == target[1]
            && maxc == target[2])
                return true;
            }
        }
        return false;
    }
};
