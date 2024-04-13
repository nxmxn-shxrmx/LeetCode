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
    TreeNode* construct(vector<int>&pre,int &i,int ri)
    {
        if(i>ri)return  NULL;
        
        TreeNode* r = new TreeNode(pre[i++]);
        
        int j= i;
        while(j<=ri&&pre[j]<r->val)++j;
        r->left  = construct(pre,i,j-1);
        r->right =  construct(pre,i,ri);
        return r;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
     int i = 0;
     return construct(preorder,i,preorder.size()-1);
    }
};