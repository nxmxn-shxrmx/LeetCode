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
    int c = INT_MIN;
    int in(TreeNode* r)
    {
        if(!r)
            return 0;
        int l = max(in(r->left),0);
        int re = max(in(r->right),0);
        
        c = max(c,r->val + l +re);
        
        return r->val+max(l,re);
    }
    int maxPathSum(TreeNode* root) {
        in(root);
        return c;
    }
};