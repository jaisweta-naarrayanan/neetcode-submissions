class WordDictionary {
    struct TrieNode{
        unordered_map<char,TrieNode*> mp;
        bool isEnd = false;
    };
     
    TrieNode* root;

public:

    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* node = root;
        for(char c:word){
            if(node->mp.find(c) == node->mp.end())
                node->mp[c] = new TrieNode();
            node = node->mp[c];    
        }
        node->isEnd = true;
    }

    bool helper(TrieNode* node, string& word, int idx){
        if(idx == word.size()) return node->isEnd;
        char c = word[idx];
        if(c != '.') {
            if(node->mp.find(c) == node->mp.end()) 
                return false;
            return helper(node->mp[c], word, idx+1);
        }

        for(auto [k,n] : node->mp){
           if (helper(n, word, idx+1)) return true; // else continue;
        }
        return false;
    }
    
    bool search(string word) {
        TrieNode* node = root;
        return helper(node, word, 0);
    }
};
