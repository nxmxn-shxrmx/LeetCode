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
    bool check(TreeNode* r1,TreeNode* r2,int k)
    {
        if(r1==NULL ||  r2==NULL)
            return false;
        
        if(r1->val+r2->val==k && r1!=r2)
        {
            return true;
        }
        if(r1->val+r2->val>k)
        {
            return check(r1->left,r2,k) || check(r1,r2->left,k);
        }
        else
        {
          return check(r1->right,r2,k) || check(r1,r2->right,k);
        }

    }
    bool findTarget(TreeNode* root, int k) {
        
        return check(root,root->left,k) || check(root,root->right,k) || check(root->left,root->right,k);
    }
};