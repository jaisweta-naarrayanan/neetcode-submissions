class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        vector<vector<string>> res;
        for(int i=0; i<strs.size(); i++){
            string b = strs[i];
            sort(b.begin(),b.end());
            //if(mp.find(b)!=mp.end()){
            mp[b].push_back(strs[i]);
            //}
        }
        for(auto [k,v]:mp){
            res.push_back(v);
        }
        return res;
    }
};
