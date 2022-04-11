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
    map<int,int>m;
    TreeNode* sub(vector<int>pre,int pl,int pr,int &ind)
    {
        if(pl>pr)
        return NULL;
               
        TreeNode* t = new TreeNode(pre[ind++]);
        int f = m[t->val];
    
         t->left = sub(pre,pl,f-1,ind);
         t->right = sub(pre,f+1,pr,ind);
             return t;
        
    }
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        for(int i = 0;i<in.size();++i)
            m[in[i]]=i;
        
        int ind = 0;
        return sub(pre,0,pre.size()-1,ind);
    }
};