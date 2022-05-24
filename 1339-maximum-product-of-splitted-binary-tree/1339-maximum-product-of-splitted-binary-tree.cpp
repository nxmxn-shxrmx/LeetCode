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
    long long sum= 0;
    long long mod = 1e9+7;
    map<TreeNode*,long long>m;
    long long in(TreeNode* r)
    {
        if(r==NULL)
            return 0;
        m[r] =  r->val+in(r->left)+in(r->right);
        return m[r];
    }
    long long ds(TreeNode* r)
    {
        if(r==NULL)
            return 0;
        long long s = m[r];
        long long h = (sum-s)*s;
        
        h = max(h,max(ds(r->left),ds(r->right)));
        return h;
    }
    int maxProduct(TreeNode* root) {
        
        if(root==NULL)
            return 0;
        sum = in(root);
        
        return (max(ds(root->left),ds(root->right)))%mod;
    }
};