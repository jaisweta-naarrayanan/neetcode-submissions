class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<pair<int,int>> st;
        vector<int> ans(n);
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && temperatures[i] >= st.top().first){
                st.pop();
            }
            ans[i] = (!st.empty())? st.top().second - i : 0;
            st.push({temperatures[i],i});
        }
        return ans;
    }
};


