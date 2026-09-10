class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), maxpf = 0;
        int b = prices[0];
        for(int i=1; i<n; i++){
            if(prices[i]>b){
                maxpf = max(maxpf, prices[i]-b);
            }
            else b = prices[i];    
        }
        return maxpf;
    }
};
