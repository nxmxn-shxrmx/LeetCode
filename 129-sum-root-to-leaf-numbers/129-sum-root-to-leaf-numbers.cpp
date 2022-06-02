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
    long long su = 0;
    
    void in(TreeNode* r,int s)
    {
        if(r->right!=NULL)
            in(r->right,s*10 + r->val);
        if(r->left!=NULL)
            in(r->left,s*10 + r->val);
        if(r->left==NULL && r->right==NULL)
        {
            s=s*10+r->val;
            su+=s;
        }
    }
    int sumNumbers(TreeNode* root) {
        if(root==NULL)
            return NULL;
        
        in(root,0);
        return su;
    }
};