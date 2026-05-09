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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum = 0;
        ListNode *i1 = l1, *i2 = l2;
        ListNode *l3 = new ListNode(-1), *i3 = l3;
        int carry = 0;
        while(i1!=NULL && i2!=NULL){       
            int sum = carry + i1->val + i2->val;
            if(sum > 9){
                carry = sum/10;
            } else  carry = 0;    
            ListNode* nn = new ListNode(sum%10, NULL);
            i1 = i1->next;
            i2 = i2->next;
            i3->next = nn;
            i3 = i3->next;
        } 
        while(i1!=NULL){
            int sum = carry + i1->val;
            if(sum > 9){
                carry = sum/10;
            }
            else  carry = 0;
            ListNode* nn = new ListNode(sum%10, NULL);
            i1 = i1->next;
            i3->next = nn;
            i3 = i3->next;
        }
        while(i2!=NULL){
            int sum = carry + i2->val;
            if(sum > 9){
                carry = sum/10;
            } else  carry = 0;
            ListNode* nn = new ListNode(sum%10, NULL);
            i2 = i2->next;
            i3->next = nn;
            i3 = i3->next;
        }
        if(carry!=0){
            ListNode* nn = new ListNode(carry, NULL);
            i3->next = nn;
            i3 = i3->next;
        }
        return l3->next;
    }
};
