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
    map<int,vector<pair<int,int>>>m;
    void reurse(int col ,int row,TreeNode* root)
    {
        if(root==NULL)
            return;
        
        m[col].push_back({row,root->val});
        reurse(col-1,row+1,root->left);
        reurse(col+1,row+1,root->right);
        
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>v;
        reurse(0,0,root);
        for(auto c:m)
        {
            vector<int>p;
            sort(c.second.begin(),c.second.end());
            for(auto x:c.second)
            {
                p.push_back(x.second);
            }
            v.push_back(p);
        }
        return v;
    }
};