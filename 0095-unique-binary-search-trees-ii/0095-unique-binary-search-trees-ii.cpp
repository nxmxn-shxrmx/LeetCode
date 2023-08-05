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
    map<pair<int,int>,vector<TreeNode*>>m;
    vector<TreeNode*>f(int l,int r)
    {
        if(l>r)return {NULL};
        
        if(l==r)return {new TreeNode(l)};
        
        vector<TreeNode*>ans;
        for(int i = l;i<=r;++i)
        {
            vector<TreeNode*>le;
            if(m.find({l,i-1})!=m.end())le = m[{l,i-1}];
            else le = f(l,i-1);
            vector<TreeNode*>ri;
            if(m.find({i+1,r})!=m.end())ri = m[{i+1,r}];
            else ri = f(i+1,r);
            
            for(auto c:le)
            {
                for(auto x:ri)
                {
                    TreeNode* h =new TreeNode(i);
                    h->left= c;
                    h->right=x; 
                    ans.push_back(h);
                }
            }
        }
        return m[{l,r}]=ans;
        
    }
    vector<TreeNode*> generateTrees(int n) {
        return f(1,n);
    }
};