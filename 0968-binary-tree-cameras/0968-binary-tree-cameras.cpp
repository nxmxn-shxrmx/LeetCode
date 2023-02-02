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
    int ct = 0;
    int f(TreeNode* root)
    {
        if(root==NULL)return 2;
        if(root->left==NULL && root->right==NULL)
            return 0;
        int l = f(root->left);
        int r = f(root->right);
        if(l==0 || r==0)
        {
            ct++;
            return 1;
        }
    
        if(l==1 || r==1)return 2;
        return 0;
    }
    int minCameraCover(TreeNode* root) {
        int u = f(root);
        if(u==0)ct++;
        return ct;
    }
};

// 0 1 2