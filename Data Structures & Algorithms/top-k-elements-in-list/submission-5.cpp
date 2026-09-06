class Solution {
public:
    using PII = pair<int,int>;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int,int> freq_mp;
        for(int i:nums){
            freq_mp[i]++;
        }
        priority_queue<PII, vector<PII>, greater<PII>> minheap; 
        for(auto [key,val]:freq_mp){
            minheap.push({val,key});
            if(minheap.size()>k){
                minheap.pop(); // as we pop beyond k ele, we need minheap with min element at the root, as we can always pop it off, and have only max elements inside the heap.
            }
                
        }
        while(!minheap.empty()){
            ans.push_back(minheap.top().second);
            minheap.pop();
        }
        return ans;
    }
};
