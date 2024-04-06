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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL)return head;
        
        while(head&&head->next&&head->val==head->next->val)
        {
            int d = -1;
            if(head->val==head->next->val)d = head->val;
        
            while(head&&d==head->val)
            head=head->next;
        }
        if(head==NULL || head->next==NULL)return head;
        ListNode* pre = head;
        ListNode* h=head;
        h = h->next;
       while(h&&h->next)
	    {
		    if(h->next->val==h->val)
		    {
			 int   d = h->val;
			    while(h&&d==h->val)h =h->next;
			
		    }
		else
		{
			pre->next=h;
		pre = pre->next;
			h = h->next;
		}
	}
    pre->next = h;
	return head;
        
    }
};