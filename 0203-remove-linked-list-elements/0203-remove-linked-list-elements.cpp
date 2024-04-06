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
    ListNode* removeElements(ListNode* head, int val) {
        
        // ListNode* u = new ListNode();
        // ListNode* w = u;
        // while(head)
        // {
        //     if(head->val!=val)
        //     {
        //         u->next = new ListNode(head->val);
        //         u = u->next;
        //     }
        //     head = head->next;
        // }
        // return w->next;
        
    if(head==NULL)return NULL;
	
	ListNode* h = removeElements(head->next,val);
	if(head->val==val)return h;
	head->next = h;	
	return head;
    }
};