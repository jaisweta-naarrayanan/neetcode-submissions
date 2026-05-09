class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map <int,int> mp;
        for(int i:nums){
            mp[i]++;
        }
        vector<int> ans;
        vector<pair<int,int>> freq;
        for(auto [key,val]:mp){
            freq.push_back({val,key});
        }
        sort(freq.begin(), freq.end(), [](pair<int,int> &a, pair<int,int> &b) {
            return a.first>b.first;
        });
        int i=0;
        while(k--){
            ans.push_back(freq[i++].second);
        }
        return ans;
    }
};
