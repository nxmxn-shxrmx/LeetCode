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
    long long c = 0;
    int in(TreeNode* r)
    {
        if(r==NULL)
            return 2;
        
        int l = in(r->left);
        int re = in(r->right);
        if(l==0 || re==0)
        {
            c+=1;
            return 1;
        }
        return l==1 || re==1 ? 2:0;
        
    }
    int minCameraCover(TreeNode* root) {
        if(root==NULL)
            return 0;
        if(root->left==NULL && root->right==NULL)
            return 1;
        return (in(root)==0?1:0)+ c;
    }
};