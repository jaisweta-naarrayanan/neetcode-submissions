class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<int>> mp;
        vector<vector<string>> res;
        for(int i=0; i<strs.size(); i++){
            string b = strs[i];
            sort(b.begin(),b.end());
            //if(mp.find(b)!=mp.end()){
            mp[b].push_back(i);
            //}
        }
        for(auto [k,v]:mp){
            vector<string> grp;
            for(auto i:v){
                grp.push_back(strs[i]);
            }
            res.push_back(grp);
        }
        return res;
    }
};
