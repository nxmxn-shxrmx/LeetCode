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
        
        multiset<int>v;
        ListNode* a = new  ListNode();
        ListNode* q = a;
        
        for(int i =0;i<lists.size();++i)
        {
            ListNode* u = lists[i];
            while(u!=NULL)
            {
                v.insert(u->val);
                u = u->next;
            }
            
        }
        for(auto it = v.begin();it!=v.end();++it)
        {
            a->next = new ListNode(*it);
            a = a->next;
        }
        return q->next;
    }
};