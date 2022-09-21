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
    int sumEvenGrandparent(TreeNode* root,bool l=false,bool t= false) {
        
        if(root==NULL)
            return 0;
        int s = 0;
        if(l)
            s+=root->val;
        if((root->val&1))
            s+=sumEvenGrandparent(root->left,t,false)+sumEvenGrandparent(root->right,t,false);
        
        else
          s+=sumEvenGrandparent(root->left,t,true)+sumEvenGrandparent(root->right,t,true);
            
    return s;
        
    }
};