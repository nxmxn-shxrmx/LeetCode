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
    int c = 0;
    int in(TreeNode* r)
    {
        if(r==NULL)
            return 0;
        int l = in(r->left);
        int ri = in(r->right);
        c += abs(l)+abs(ri);
        
        return r->val+l+ri-1;
    }
    int distributeCoins(TreeNode* root) {
     in(root);
        return c;
    }
};