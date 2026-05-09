class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,pair<int,int>> intervals;
        vector<pair<int,int>> unmerged, merged;
        for(int i=0; i<s.size(); i++){
            if(intervals.count(s[i])){
                intervals[s[i]].second = i;
            }
            else{
                intervals[s[i]].first = i;
                intervals[s[i]].second = i;
            }
        }
        // for(auto it=intervals.begin(); it != intervals.end(); it++)
        //     cout<<it->first<<" "<<it->second.first<<" to "<<it->second.second<<"\n";

        for(auto it=intervals.begin(); it != intervals.end(); it++)
            unmerged.push_back(it->second);

        sort(unmerged.begin(), unmerged.end());

        // for(auto it=unmerged.begin(); it != unmerged.end(); it++)
        //     cout<<it->first<<" to "<<it->second<<"\n";
    
        for(auto i:unmerged){
            if(merged.empty()){
                merged.push_back(i);
                continue;
            }
            // cout<<"new st: "<< i.first << "old end: "<< merged.back().second<<"\n";
            if(i.first < merged.back().second ){
                merged.back().second = max(merged.back().second, i.second);
            }
            else merged.push_back(i);
        }
        vector<int> ans;
        for(auto i:merged){
            ans.push_back(i.second - i.first + 1);
        }
        return ans;
    }
};
