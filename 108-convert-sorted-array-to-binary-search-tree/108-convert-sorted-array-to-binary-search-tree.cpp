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
    TreeNode* sre(vector<int>&v,int l,int r)
    {
        if(l<=r)
        {
            int m = (l+r)/2;
            TreeNode* t = new TreeNode(v[m]);
            t->left = sre(v,l,m-1);
            t->right=sre(v,m+1,r);
            return t;
        }
        
        return NULL;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        
        return sre(nums,0,nums.size()-1);
        
    }
};