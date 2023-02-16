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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        priority_queue<int>v;
        ListNode* a = new  ListNode();
        ListNode* q = a;
        
        for(int i =0;i<lists.size();++i)
        {
            ListNode* u = lists[i];
            while(u!=NULL)
            {
                int p= u->val;
                v.push(-p);
                u = u->next;
            }
            
        }
        while(!v.empty()){
            a->next = new ListNode(-v.top()),v.pop();
            a = a->next;
        }
        return q->next;
    }
};