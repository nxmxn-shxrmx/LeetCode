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
    
    map<int,vector<pair<pair<int,int>,int>>>m;
    void in(TreeNode* root,int r,int c)
    {
        if(root==NULL)
            return;
        m[r].push_back({{c,r},root->val});
        in(root->left,r-1,c+1);
        in(root->right,r+1,c+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>v;
        in(root,0,0);
        for(auto c:m)
        {
            vector<int>f;
            sort(c.second.begin(),c.second.end());
            for(auto x:c.second)
            {
                f.push_back(x.second);
            }
            v.push_back(f);
            
        }
        return v;
    }
};