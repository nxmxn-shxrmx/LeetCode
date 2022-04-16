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
    int sum(TreeNode *root,int x)
    {
        if(root==NULL)
            return 0;
        if(root->val>x)
            return sum(root->right,x)+root->val+sum(root->left,x);
        
        return sum(root->right,x);
    }
    TreeNode* sub(TreeNode* root,TreeNode* r)
    {
        if(r==NULL)
            return NULL;
        int x = r->val;
        x+=sum(root,x);
        TreeNode* u = new TreeNode(x);
        u->left =  sub(root,r->left);
        u->right = sub(root,r->right);
        
        return u;
    }
    TreeNode* convertBST(TreeNode* root) {
        if(root==NULL)
            return NULL;
        
        return sub(root,root);
        
    }
};