/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    void dfsClone(Node* n, Node* cn, unordered_map<Node*, Node*>& old2new){
        if(old2new.count(n)) return; // node was already cloned
        old2new[n]=cn;
        for(Node* nei:n->neighbors){
            Node* nn;
            if(!old2new.count(nei)){
                nn = new Node(nei->val);
                //old2new[nei] = nn;
            }
            else nn = old2new[nei];
            cn->neighbors.push_back(nn);//old2new[nei]);
            dfsClone(nei, nn, old2new);
        }
    }
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        unordered_map<Node*, Node*> old2new;
        Node* nn = new Node(node->val);
        // old2new[node]=nn;
        dfsClone(node, nn, old2new);
        return nn;
    }
};
