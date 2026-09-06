class Solution {
public:
    using PII = pair<int,int>;
    vector<int> topKFrequent(vector<int>& nums, int k) {

        // auto cmp = [] (const PII &p1, const PII &p2){
        //     return p1.second < p2.second;
        // };
        vector<int> ans;
        unordered_map<int,int> freq_mp;
        for(int i:nums){
            freq_mp[i]++;
        }
        priority_queue<PII, vector<PII>, less<PII>> maxheap; //decltype(cmp)> maxheap(cmp);

        for(auto [k,v]:freq_mp){
            maxheap.push({v,k});
        }
        while(k--){
            ans.push_back(maxheap.top().second);
            maxheap.pop();
        }
        return ans;
    }
};
