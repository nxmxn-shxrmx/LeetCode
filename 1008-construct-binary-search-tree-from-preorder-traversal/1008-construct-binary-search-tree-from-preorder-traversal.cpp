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
    TreeNode* construct(vector<int>&pre,int &i,int mx = INT_MAX)
    {
        if(i>=pre.size()||pre[i]>mx)return  NULL;
        
        TreeNode* r = new TreeNode(pre[i++]);
        
        
        r->left  = construct(pre,i,r->val);
        r->right =  construct(pre,i,mx);
        return r;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
     int i = 0;
     return construct(preorder,i);
    }
};