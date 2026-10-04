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
    Node* dfsClone(Node* n, unordered_map<Node*, Node*>& old2new){
        if(old2new.count(n)) return old2new[n]; // node was already cloned
        Node* nn = new Node(n->val);
        old2new[n] = nn;
        for(Node* nei:n->neighbors){
            Node* nnei = dfsClone(nei, old2new);
            nn->neighbors.push_back(nnei);//old2new[nei]);
        }
        return nn;
    }
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        unordered_map<Node*, Node*> old2new;
        return dfsClone(node, old2new);
    }
};
