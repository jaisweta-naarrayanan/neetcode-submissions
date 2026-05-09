class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> lmax(n,-1), rmax(n,-1);
        int ans = 0;
        lmax[0] = heights[0];
        rmax[n-1] = heights[n-1];
        for(int i=1; i<n; i++){
            lmax[i] = max(lmax[i-1],heights[i]);
        }
        for(int i=n-2; i>=0; i--){
            rmax[i] = max(rmax[i+1],heights[i]);
        }
        cout<<"lmax : "<<endl;
        for(int i:lmax) cout<<i<<"..";
        cout<<endl;
        for(int i:rmax) cout<<i<<"..";
        cout<<endl;
        int i=0, j=n-1;
        while(i<j){
            ans = max(ans, (j-i) * min(lmax[i],rmax[j]) ) ;  
            if(lmax[i] == rmax[j]){
                i++; j--;
            }
            else if(lmax[i] > rmax[j])
                j--;
            else i++;
        }
        return ans;
    }
};
