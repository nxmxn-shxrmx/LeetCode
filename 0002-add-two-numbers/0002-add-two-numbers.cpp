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
#define null NULL 

#define data val
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* f, ListNode* s) {
    	// add your logic here
	ListNode* h = f;
	int c = 0;
	while(f&&s)
	{
		f->data = (f->data+s->data+c);
		c = (f->data)/10;
        f->data%=10;
		if(f->next==NULL)
		{
            f->next = s->next;
			break;
		}
        if(s->next==NULL)  
            break;
        
		f = f->next;
		s = s->next;
	}
    ListNode* u=f;
    f = f->next;
    while(f)
    {
         f->data = (f->data+c);
        c = f->data/10;
        f->data%=10;
        f =f->next;
        u = u->next;
    }
    if(c)u->next = new ListNode(c);
        
    
		return h;
    }
};