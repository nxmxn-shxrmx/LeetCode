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
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next==NULL)
            return NULL;
        ListNode* f = head;
        ListNode* s = head;
        ListNode* p = NULL;
        while(f!=NULL && f->next!=NULL)
        {
            p =s;
            s = s->next;
            f = f->next;
            f = f->next;
        }
        p->next = p->next->next;
        return head;
    }
};