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
    int in(TreeNode* root)
    {
        if(root==NULL)
            return 2;
        int l = in(root->left);
        int r = in(root->right);
        
        if(l==0 || r==0)
        {
            c++;
            return 1;
        }
        if(l==1 || r==1)
            return 2;
        
        return 0;
    }
    int minCameraCover(TreeNode* root) {
        if(in(root)<1)
            c++;
    
        return c;
    }
};