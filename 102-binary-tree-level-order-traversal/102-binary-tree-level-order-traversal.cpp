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
    vector<vector<int>>w;

    vector<vector<int>> levelOrder(TreeNode* root) {
        
        if(root==NULL)
            return w;
        queue<TreeNode*>q;
        q.push(root);
        vector<int>v;
        v.push_back(root->val);
        w.push_back(v);
        
        while(!q.empty())
        {
           int sz = q.size();
            vector<int>v;
            for(int i =0;i<sz;++i)
            {
                TreeNode* e = q.front();
                q.pop();
                if(e->left!=NULL)
                {
                    q.push(e->left);
                    v.push_back(e->left->val);
                }
                if(e->right!=NULL)
                {
                    q.push(e->right);
                    v.push_back(e->right->val);
                }
            }
            if(v.size()>0)
                w.push_back(v);
        }
        
     return w;   
    }
};