class Solution {
public:
    void backtract(string &digits, int i, string &curr, unordered_map<int,string> &mp, vector<string> &ans){
        if(i==digits.size()){
            ans.push_back(curr);
            return;
        }
        //cout<<digits[i]-'0'<<" ";
        for(char c:mp[digits[i]-'0']){
            curr.push_back(c);
            backtract(digits, i+1, curr, mp, ans);
            curr.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size() < 1) return {};
        unordered_map<int, string> mp;
        mp[2]="abc";
        mp[3]="def";
        mp[4]="ghi";
        mp[5]="jkl";
        mp[6]="mno";
        mp[7]="pqrs";
        mp[8]="tuv";
        mp[9]="wxyz";
        vector<string> ans;
        string curr;
        backtract(digits, 0, curr, mp, ans);
        return ans;
    }
};
