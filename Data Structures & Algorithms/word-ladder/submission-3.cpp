class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, vector<string>> adj;
        unordered_set<string> dict(wordList.begin(), wordList.end());

        wordList.push_back(beginWord);
        for(string s:wordList){
            for(int i=0; i<s.size(); i++){
                string ss = s;
                for(char c='a'; c<='z'; c++){
                    if(c == s[i]) continue;
                    ss[i] = c;
                    if(dict.count(ss)){
                        adj[ss].push_back(s);
                        adj[s].push_back(ss);
                    }
                }
            }
            for(string ts:adj[s]) cout<<s<<" : "<<ts<<" , "<<endl;  
        }
        queue<string> q;
        q.push(beginWord);
        dict.erase(beginWord);
        int d=1;
        while(!q.empty()){
            int sz = q.size();

            while(sz--){
                string u = q.front();
                q.pop();
                
                for(string v:adj[u]){
                    if(dict.count(v)){
                        q.push(v);
                        dict.erase(v);
                        if(v==endWord) {
                            return d+1;
                        }
                    }
                }
            }
            d++;
        }
        cout<<d;
        return 0;
    }
};
