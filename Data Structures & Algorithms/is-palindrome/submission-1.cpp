class Solution {
public:
    bool isalpha(char a){
        if((a >= 'A' && a<= 'Z') || (a>='a' && a<='z') || (a>='0' && a<='9'))
            return true;
        return false;
    }
    bool isPalindrome(string s) {
        int n = s.length();
        int i=0, j=n-1;
        while(i<j){
            if(!isalpha(s[i])) { cout<<"i:"<<s[i]<<endl; i++; continue;}
            if(!isalpha(s[j])) { cout<<"j:"<<s[j]<<endl; j--; continue;}
            if(tolower(s[i]) != tolower(s[j]))
                return false;
            i++; j--;
        }
        return true;
    }
};
