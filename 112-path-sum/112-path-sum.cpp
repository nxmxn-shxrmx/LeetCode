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

    bool ins(TreeNode* r,int d)
    {
        if(r==NULL)
            return false;
        if(r->left==NULL && r->right==NULL)
        {
            d-=r->val;
            if(d==0)
                return true;
            return false;
        }
          d-=r->val;
        return ins(r->left,d)|| ins(r->right,d);        
        
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        
        if(root==NULL)
            return false;
        int c =0;
    
        return  ins(root,targetSum);
    }
};