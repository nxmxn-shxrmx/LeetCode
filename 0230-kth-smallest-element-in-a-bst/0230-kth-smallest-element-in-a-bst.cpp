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
    
    void sub(TreeNode* r,int &ans,int &ct,int k )
    {
        if(r==NULL)
            return ;
        
    
        sub(r->left,ans,ct,k);
        ct++;
        if(ct==k)ans = r->val;
        sub(r->right,ans,ct,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        
        int ans = 0;
        int ct = 0;
        sub(root,ans,ct,k);
        return ans;
 }
};