class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<int>> mp;
        vector<vector<string>> ans;
        for(int i=0; i<strs.size(); i++){
            string str = strs[i];
            sort(str.begin(),str.end());
            mp[str].push_back(i);
        }
        for(auto [k,v]:mp){
            vector<string> ls;
            for(int i:v){
                ls.push_back(strs[i]);
            }
            ans.push_back(ls);      
        }
        return ans;
    }
};
