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
    int m = 0;
    void in(TreeNode* r,bool t,int s)
    {
        if(r==NULL)
            return;
        
        if(t)
        {
            s+=1;
            m =max(s,m);
            in(r->right,false,s);
            in(r->left,true,0);
        }
        else
        {
            s+=1;
            m = max(s,m);
            in(r->left,true,s);
            in(r->right,false,0);
        }
    }
    int longestZigZag(TreeNode* root) {
        if(root==NULL)
            return 0;
        
         in(root->left,true,0);
         in(root->right,false,0);
        return m;
    }
};