/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* &node) {
        if(node==NULL)
            return;
        if(node->next==NULL)
            node = NULL;
        ListNode* p = node;
        while(node->next!=NULL)
        {
            node->val = node->next->val;
            p = node;
            node =node->next;
        }
        p->next = NULL;
        
    }
};