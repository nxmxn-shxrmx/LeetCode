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
    vector<vector<int>>se;
    
    void ro(vector<int>f,int t,int s,TreeNode* r)
    {   
        
        if(r==NULL)
            return;
        
        
        if(r->left==NULL && r->right==NULL)
        { 
            f.push_back(r->val);
            s+=r->val;
            if(s==t)   
                se.push_back(f);
            f.pop_back();
            return;
        }
    
        f.push_back(r->val);
        ro(f,t,s+r->val,r->left);
        ro(f,t,s+r->val,r->right);
        f.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root==NULL)
            return se;
        vector<int>f;
        ro(f,targetSum,0,root);
        return se;
    }
};