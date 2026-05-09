class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> cars;
        int n = speed.size();
        for(int i=0; i<n; i++){
            cars.push_back({position[i],speed[i]});
        }
        sort(cars.begin(), cars.end());
        stack<double> st;
        for(int i = n-1; i>=0; i--){
            int dis = target - cars[i].first;
            double time = (dis*1.0)/cars[i].second;
            cout<<time<<"..";
            // no car ahead or not gonna collide w/ any car ahead then add to list
            if(st.empty() || time > st.top()){ 
                st.push(time);
            }
        }
        return st.size();
    }
};
