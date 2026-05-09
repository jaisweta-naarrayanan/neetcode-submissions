class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int cmin = prices[0]; //cmax = 0;
        int prof = 0;
        for(int i=1; i<prices.size(); i++){
            prof = max(prices[i] - cmin, prof);
            cmin = min(cmin,prices[i]);
        }
        return prof;
    }
};
