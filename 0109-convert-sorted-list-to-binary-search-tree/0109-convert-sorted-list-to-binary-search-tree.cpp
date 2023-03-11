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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(head==NULL)return NULL;
        if(head->next==NULL)return new TreeNode(head->val);
        
        ListNode* sl = head;
        ListNode* fs = head;
        ListNode* pre =NULL;
        while(fs!=NULL && fs->next!=NULL)
        {
            pre = sl;
            sl = sl->next;
            fs = fs->next;
            fs = fs->next;
        }
        TreeNode* r =new TreeNode(sl->val);
        pre->next = NULL;
        r->left = sortedListToBST(head);
        r->right=sortedListToBST(sl->next);
        return r;
    }
};