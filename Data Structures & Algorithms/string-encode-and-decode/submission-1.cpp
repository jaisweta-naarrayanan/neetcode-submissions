class Solution {
public:

    string encode(vector<string>& strs) {
        string ss = to_string(strs.size()) + "#";
        {/*
            for(string s:strs){
                ss += s+ ",";
            }
            ss.erase(ss.length()-1); // ss.pop();
            */
        }
        for(string s:strs){
            ss+=to_string(s.size())+ "#";
            ss+=s;
        }
        return ss;
    }

    int getnum(string s, int &i){
        int num = 0;
        for(; i<s.size() && s[i]!='#'; i++){
            num = num * 10 + s[i]-'0';
        }
        return num;
    }
    vector<string> decode(string s) {
        vector<string> ans;
        { /*
            stringstream ss(s);
            string token;
            while(getline(ss,token,',')){
                ans.push_back(token);
            }
            */
        }
        int i=0;
        int n = getnum(s,i);
        i++;
        while(n--){
            int sz = getnum(s,i);
            i++;
            ans.push_back(s.substr(i,sz));
            i+=sz;
        }
        return ans;
    }
};
