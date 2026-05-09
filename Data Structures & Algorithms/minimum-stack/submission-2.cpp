class MinStack {
public:
    struct Node{
        int val;
        int minsofar;
        Node* next;
        Node(int v, int m){
            val = v;
            minsofar = m;
            next = NULL;
        }
    };
   
    Node* head;

    MinStack() {
        head = NULL;
    }
    
    void push(int val) {
        if(!head)
            head = new Node(val, val);
        else{
            Node* nnode = new Node(val, min(head->minsofar, val));
            nnode->next = head;
            head = nnode;
        }    
    }
    
    void pop() {
        if(!head) return;
        Node* t = head;
        head = head->next;
        delete(t);
    }
    
    int top() {
        return (head)? head->val : 0;
    }
    
    int getMin() {
        return (head)? head->minsofar: 0;
    }
};
