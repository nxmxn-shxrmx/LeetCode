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
    map<string,vector<TreeNode*>>m;
    vector<TreeNode*>f(string s)
    {
        if(s.size()==0)
            return {NULL};
        if(s.size()==1)
            return {new TreeNode(s[0]-'0')};
        vector<TreeNode*>p;
        for(int i = 0;i<s.size();++i)
        {
            vector<TreeNode*>le;
            if(m.find(s.substr(0,i))!=m.end())le = m[s.substr(0,i)];
            else le = f(s.substr(0,i));
            vector<TreeNode*>ri;  
                if(m.find(s.substr(i+1))!=m.end())ri = m[s.substr(i+1)];
            else ri = f(s.substr(i+1));
            for(auto c:le)
            {
                for(auto x:ri)
                {
                    TreeNode *q = new TreeNode(s[i]-'0');
                    q->left = c;
                    q->right = x;
                    p.push_back(q);
                    
                }
            }
        }
        return p;
    }
    vector<TreeNode*> generateTrees(int n) {
        string s = "";
        for(int i =1;i<=n;++i)
            s+=to_string(i);
        return f(s);
    }
};