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
    TreeNode* deleteT(TreeNode* r)
    {
        if(r->left==NULL && r->right==NULL)
            return NULL;
        
        if(r->left==NULL)return r->right;
        if(r->right==NULL)return r->left;
        
        TreeNode* u = r->left;
        while(u->right)
            u = u->right;
        u->right = r->right;
        return r->left;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
     if(root==NULL)return root;
     if(root->val==key)
        return deleteT(root);    
     if(root->val>key)
     root->left = deleteNode(root->left,key);
     else
     root->right= deleteNode(root->right,key);
     return root;
    }
};