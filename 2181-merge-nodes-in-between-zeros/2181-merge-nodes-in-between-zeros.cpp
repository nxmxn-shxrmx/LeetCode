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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* h = new ListNode();
        ListNode* p = h;
        int u = 0;
        head= head->next;
        while(head)
        {
            if(head->val==0)
            {
                h->next = new ListNode(u);
                h = h->next;
                u = 0;
                head = head->next;
                continue;
            }
            u+=head->val;
            head = head->next;
        }
        return p->next;
    }
};