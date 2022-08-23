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
    ListNode* reus(ListNode* &u)
    {
        if(u==NULL || u->next==NULL)
            return u;
        
        swap(u->val,u->next->val);
        reus(u->next->next);
        return u;
    }
    ListNode* swapPairs(ListNode* head) {
        reus(head);    
        return head;
    }
};