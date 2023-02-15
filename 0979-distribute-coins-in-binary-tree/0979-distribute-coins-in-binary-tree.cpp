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
        c+=abs(l)+abs(r);
        return root->val+l+r-1;
    }
    int distributeCoins(TreeNode* root) {
        TreeNode* pre = new TreeNode(-1); 
     f(root,pre); 
        return c;
    }
};