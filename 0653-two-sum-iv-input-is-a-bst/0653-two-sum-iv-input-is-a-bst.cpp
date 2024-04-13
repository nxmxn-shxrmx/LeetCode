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
    bool check(TreeNode* r1,TreeNode* r2,int k)
    {
        if(r1==NULL)
            return false;
        
        if(k==r1->val && r1!=r2)
            return true;
        
        if(r1->val>k)
            return check(r1->left,r2,k);
        
        
          return check(r1->right,r2,k);
        

    }
    bool dfs(TreeNode* root,TreeNode* cur,int k)
    {
        if(cur==NULL)return 0;
        return check(root,cur,k-cur->val)||dfs(root,cur->left,k)||dfs(root,cur->right,k);
    }
    bool findTarget(TreeNode* root, int k) {
        
        return dfs(root,root,k);
    }
};