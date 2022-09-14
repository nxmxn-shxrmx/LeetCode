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
    
    int f(TreeNode* r,map<int,int>&m)
    {
     if(r==NULL)
         return 0;
        if(r->right==NULL && r->left==NULL)
        {
            int od=0;
            m[r->val]++;
            for(auto c:m)
                if(c.second%2)
                    od++;
          
    
            m[r->val]--;
            if(od<=1)
        
            return od<=1?1:0;
        }
        
        int s=0;
        m[r->val]++;
        s+=f(r->left,m);
        s+=f(r->right,m);
        m[r->val]--;
        return s;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        map<int,int>m;
        if(root==NULL)
            return 0;
        return f(root,m);
    }
};