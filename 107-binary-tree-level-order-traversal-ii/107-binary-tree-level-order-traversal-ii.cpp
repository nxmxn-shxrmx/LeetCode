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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>>v;
        if(root==NULL)
            return v;
        
        queue<TreeNode*>q;
        q.push(root);
        v.push_back({root->val});
        while(!q.empty())
        {
            int n = q.size();
            vector<int>g;
            for(int i =0;i<n;++i)
            {
                 TreeNode* r = q.front();
                
                if(r->left)
                    q.push(r->left),g.push_back(r->left->val);
                if(r->right)
                    q.push(r->right),g.push_back(r->right->val);
                
                q.pop();
                
            }
            if(g.size())
                v.push_back(g);
        }
        reverse(v.begin(),v.end());
        return v;
        
    }
};