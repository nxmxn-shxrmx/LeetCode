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
    int c =0;
    int f(TreeNode* &root,TreeNode* &pre)
    {
        if(root==NULL)return 0;
        int l = f(root->left,root);
        int r = f(root->right,root);
        
        c+=l+r;
        if(l<=(root->val))
            root->val-=l,l=0;
        else
            l-=root->val,root->val=0;
         if(r<=(root->val))
            root->val-=r,r=0;
        else
            r-=root->val,root->val=0;
        
        pre->val +=max(0,root->val-1);
        c+=max(0,root->val-1);
        if(root->val==0)
            l++;
        return l+r;
    }
    int distributeCoins(TreeNode* root) {
        TreeNode* pre = new TreeNode(-1); 
     f(root,pre); 
        return c;
    }
};