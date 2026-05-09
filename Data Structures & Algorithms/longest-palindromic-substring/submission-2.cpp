class Solution {
public:

    string longestPalindrome(string s) {
        int n = s.size();
        int maxlind = 0, maxlen = 1;
        //string maxres = "";
        for(int i=0; i<n; i++){
            // odd len palin
            int l = i, r=i;
            int len = 0;
            //string res = "";
            while(l>=0 && r<n && s[l]==s[r]){
                len = r-l+1;
                if(len > maxlen){
                    maxlind = l;
                    maxlen = max(maxlen, len);
                    cout<<"odd max: "<<maxlen;
                }
                l--;
                r++;
            }
            // even len palin
            l = i, r=i+1;
            len = 0;
            //string res = "";
            while(l>=0 && r<n && s[l]==s[r]){
                len = r-l+1;
                if(len > maxlen){
                    maxlind = l;
                    maxlen = max(maxlen, len);
                    cout<<"evn max: "<<maxlen;
                }
                l--;
                r++;
            }
        }
        return s.substr(maxlind, maxlen);
    }
};
