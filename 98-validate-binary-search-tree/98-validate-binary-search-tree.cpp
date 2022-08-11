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
    bool is(TreeNode* r,long long l,long long ri)
    {
        if(r==NULL)
            return true;
        
        if(r->val<ri && r->val>l)
            return is(r->left,l,r->val)&&is(r->right,r->val,ri);
            
    return false;
    }
    bool isValidBST(TreeNode* root) {
        return is(root,LLONG_MIN,LLONG_MAX);
    }
};