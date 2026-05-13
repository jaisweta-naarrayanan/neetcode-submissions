class Solution {
public:
    void backtract(int n, string curr, vector<string>& ans, int opens, int closes){
        if(curr.size() == n*2){ //&& opens == closes
            ans.push_back(curr);
            return;
        }
        if(opens < n){
            cout<<"opens when (: "<<opens<<endl;
            backtract(n, curr + '(', ans, opens+1, closes);
        }
        if(closes < opens){
            cout<<"opens when ): "<<opens<<endl;
            backtract(n, curr+')', ans, opens, closes+1);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string curr = "";
        backtract(n, curr, ans, 0, 0);
        return ans;
    }
};
