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
    map<int,int>m;
    TreeNode* f(vector<int>&pre,int &i,int l,int r)
    {
        if(l>r || i>=pre.size())return NULL;
        
        TreeNode* root = new TreeNode(pre[i]);
        int pr = pre[i];
    //    cout<<pr<<" "<<i<<"\n";
        if(l<=m[pr]-1)
        root->left= f(pre,++i,l,m[pr]-1);
        if(m[pr]+1<=r)
        root->right =f(pre,++i,m[pr]+1,r);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        for(int  i= 0;i<inorder.size();++i)
        m[inorder[i]]=i;
        int i = 0;
        return f(preorder, i,0,preorder.size()-1);
    }
};