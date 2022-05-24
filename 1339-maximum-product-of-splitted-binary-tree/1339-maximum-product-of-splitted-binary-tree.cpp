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
    long long res;
    long long mod = 1e9+7;
    long long in(TreeNode* r)
    {
        if(r==NULL)
            return 0;
        long long s=  r->val+in(r->left)+in(r->right);
        
        res = max(res,s*(sum-s));
        
        return s;
    }
   
    int maxProduct(TreeNode* root) {
        
        if(root==NULL)
            return 0;
        sum = in(root);
        in(root);
        return res%mod;
    }
};