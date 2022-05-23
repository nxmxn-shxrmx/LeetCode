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
    int le,ri;
    TreeNode* search(TreeNode* root,int x)
    {
        if(root==NULL)
            return NULL;
        
        if(root->val==x)
            return root;
        
        TreeNode* r = search(root->left,x);
        TreeNode* y = search(root->right,x);
        
        if(r==NULL)
            return y;
        return r;
    }
    int nc(TreeNode* root,int x)
    {
        if(root==NULL)
            return 0;
        
        int ex = nc(root->left,x);
        int ey = nc(root->right,x);
        
        if(root->val==x)
        {
            le = ex;
            ri = ey;
        }
        
        return ex+ey+1;
    }
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        
        int d = nc(search(root,x),x);
        
        int m = max(le,ri);
        m = max(m,n-d);
    
        return m>(n/2);
    }
};