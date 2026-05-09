/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        /*{
            int len = 1;
            ListNode* f = head;
            while(f!= NULL && f->next != NULL){
                len+=2;
                f=f->next->next;
            }
            if(f==NULL) len-=1;
            if(len == 1) return NULL;
            cout<<len;
            ListNode *prev = NULL, *curr = head;

            for(int i=1; i<=len-n && curr!=NULL; i++){
                prev = curr;
                curr = curr->next;
            }
            cout<<curr->val;
            if(prev!= NULL) prev->next = curr->next;
            else return head->next;
            return head;
        }*/
        ListNode* l = new ListNode(0,head);
        ListNode* r = head;
        while(n){
            r = r->next;
            n--;
        }

        while(r!=NULL){
            l = l->next;
            r = r->next;
        }
        ListNode *t = l->next;
        if(t==head) return t->next;
        l->next = t->next;
        delete(t);
        return head;
    }
};
