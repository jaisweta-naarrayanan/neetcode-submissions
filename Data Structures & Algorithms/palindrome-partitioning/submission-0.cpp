class Solution {
public:
    bool isPalin(string s){
        int j = s.size()-1;
        int i=0;
        while(i<j){
            if(s[i]!=s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    void backtract(string s, int i, vector<string> &curr, vector<vector<string>> &ans){
        if(i == s.size()){
            ans.push_back(curr);
            return;
        }
        for(int j=i; j<s.size(); j++){
            string ss = s.substr(i, j-i+1);
            // cout<<"i"<<i<<" "<<ss<<endl;
            if(isPalin(ss)){
                curr.push_back(ss);
                backtract(s, j+1, curr, ans);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        if(s.size() == 1) return {{s}};
        vector<vector<string>> ans;
        vector<string> curr;
        backtract(s,0,curr,ans);
        return ans;
    }
};
