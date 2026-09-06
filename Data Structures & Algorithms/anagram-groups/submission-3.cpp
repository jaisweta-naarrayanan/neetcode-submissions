class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        vector<vector<string>> ans;
        for(int i=0; i<strs.size(); i++){
            string str = strs[i];
            sort(str.begin(),str.end());
            mp[str].push_back(strs[i]);
        }
        for(auto [k,v]:mp){
            ans.push_back(v);      
        }
        return ans;
    }
};
