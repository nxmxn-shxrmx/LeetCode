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
    TreeNode* f(vector<int>&pre,vector<int>&in,int l,int r,int &ind)
    {
        if(ind==pre.size()||l>r)return NULL;
        
        TreeNode* root = new TreeNode(pre[ind++]);
        
        int ans = l;
        while(ans<=r)
        {
            if(in[ans]==root->val)
                break;
            ans++;
        }
        root->left = f(pre,in,l,ans-1,ind);
        root->right = f(pre,in,ans+1,r,ind);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int l =0;
        int r = inorder.size()-1;
        
        int inx = 0;
        return f(preorder,inorder,l,r,inx);
 }
};