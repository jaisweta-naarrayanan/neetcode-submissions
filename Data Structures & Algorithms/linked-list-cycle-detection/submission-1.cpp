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
    bool hasCycle(ListNode* head) {
        // fast and slow pointers
        if(head == NULL || head->next == NULL) return false;
        if (head->next == head) return true;
        ListNode *s = head->next, *f = head->next->next;
        while(f!=NULL && f->next != NULL){
            if(s==f){
                return true;
            }
            f = f->next->next;
            //else return false;
            s = s->next;
        }
        return false;
    }
};
