class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        //char [] = {'(','{','['};
        for(char c:s){
            // cout<<c;
            if(c == '(' || c == '{' || c =='['){
                st.push(c);
                cout<<"pushed";
                continue;
            }
            if(st.empty())
                return false;
            else if((c == ')' && st.top() == '(')
            || (c == '}' && st.top() == '{')
            || (c == ']' && st.top() == '[')){
                st.pop();    
                cout<<"popped";
            }
            else return false;
            
        }
        if(st.empty()) return true;
        return false;
    }
};
