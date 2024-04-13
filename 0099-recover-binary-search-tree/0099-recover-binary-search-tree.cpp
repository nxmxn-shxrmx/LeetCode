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
    TreeNode* pre= NULL;
    TreeNode* fir = NULL;
    TreeNode* sec = NULL;
    void in(TreeNode* r)
    {
        if(r==NULL)return;
        in(r->left);
       
        if(pre&&pre->val>r->val)
        {
            if(fir==NULL)fir = pre;
            sec = r;
        }
        pre =r;
        in(r->right);
    }

    void recoverTree(TreeNode* root) {
        in(root);
      
        swap(fir->val,sec->val);
        
        
    }
};
