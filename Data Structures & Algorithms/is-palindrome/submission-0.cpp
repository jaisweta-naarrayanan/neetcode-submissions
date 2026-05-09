class Solution {
public:
    bool isAlpha(char a){
        if((a >= 'A' && a<= 'Z') || (a>='a' && a<='z') || (a>='0' && a<='9'))
            return true;
        return false;
    }
    bool isPalin(string &s, int st, int e, bool &flag){
        if(flag == false) 
            return false;
        if(st >= e){
            return true;
        }
        if(!isAlpha(s[st]))
            return isPalin(s, st+1, e, flag);
        if(!isAlpha(s[e]))
            return isPalin(s, st, e-1, flag);
        if(tolower(s[st]) != tolower(s[e]))
            return flag = false;
        else {
            return isPalin(s, st+1, e-1, flag);
        }
    }
    bool isPalindrome(string s) {
        int n = s.size();
        bool flag = true;
        return isPalin(s,0,n-1,flag);
    }
};
