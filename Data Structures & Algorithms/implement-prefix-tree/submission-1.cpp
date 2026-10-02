class PrefixTree {
    struct TrieNode{
        unordered_map<char,TrieNode*> mp;
        bool isEnd = false;
        int numChildren = 0;
    };
    TrieNode* root;
public:
    
    PrefixTree() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* node = root;
        for(char c:word){
            if(node->mp.find(c)== node->mp.end()){
                TrieNode* t = new TrieNode();
                node->mp[c] = t;
            }
            node = node->mp[c];
            node->numChildren++;
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode* node = root;
        for(char c:word){
            if(node->mp.find(c)==node->mp.end()){
                return false;
            }
            node = node->mp[c];
        }
        return node->isEnd == true;
    }
    
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for(char c:prefix){
            if(node->mp.find(c)==node->mp.end()){
                return false;
            }
            node = node->mp[c];
        }
        return node->numChildren >= 1;
    }
};
