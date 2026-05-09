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
    ListNode* merge2lists(ListNode* l1, ListNode* l2){
        ListNode* h = new ListNode(-1);
        ListNode* curr = h;
        while(l1 && l2){
            if(l1->val <= l2->val){
                curr->next = l1;
                l1 = l1->next;
            }
            else{
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }
        if(l1) curr->next = l1;
        if(l2) curr->next = l2;
        return h->next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {

        if(lists.empty()) return NULL;

        while(lists.size() > 1){
            vector<ListNode*> mergedlist;
            for(int i=0; i<lists.size(); i+=2){
                ListNode* l1 = lists[i];
                ListNode* l2 = (i+1 < lists.size())? lists[i+1] : NULL;
                mergedlist.push_back(merge2lists(l1, l2)); 
            }
            lists = mergedlist;
        }
        return lists[0];
    }
};
