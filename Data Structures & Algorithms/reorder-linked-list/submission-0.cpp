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
    void reorderList(ListNode* head) {
        ListNode *th = head, *s=head, *f = head;
        while(f!=NULL && f->next!=NULL){
            f = f->next->next;
            s = s->next;
        }
        ListNode *curr = s->next; 
        s->next = NULL;
        ListNode *prev = NULL;

        while(curr!=NULL){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        ListNode* rcurr = prev; // is the revlist head;
        while(th != NULL && rcurr !=NULL){
            ListNode* temp = th->next;
            ListNode* rtemp = rcurr->next;
            th->next = rcurr;
            rcurr->next = temp;
            th = temp;
            rcurr = rtemp;
        }
        //return head;
    }
};
