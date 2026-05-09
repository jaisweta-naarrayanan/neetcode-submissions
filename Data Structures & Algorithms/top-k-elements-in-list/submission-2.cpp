class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map <int,int> mp;
        vector<int> ans;

        for(int n:nums){
            mp[n]++;
        }
        { /*
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
            */ 
        }
        // Bucket Sort
        vector<vector<int>> buckets(nums.size()+1);
        for(auto [k,v]:mp){
            buckets[v].push_back(k);
        }
        for(int i=buckets.size()-1; i>=0 && ans.size()<k; i--){
            for(int j=0; j<buckets[i].size(); j++){
                ans.push_back(buckets[i][j]);
                if(ans.size()==k) return ans;
            }
        }
        return ans;
    }
};
