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
    vector<int>v;
    void in(TreeNode* r)
    {
        if(r==NULL)
            return;
        in(r->left);
        v.push_back(r->val);
        in(r->right);
    }
    bool ki,si;
    void on(TreeNode* &r,int mx,int mn)
    {
        if(r==NULL)
            return;
        
        if(r->val==mn)
            r->val =mx,ki = true;
        else if(r->val==mx)
            r->val = mn,si = true;
        if(ki && si)
            return;
        on(r->left,mx,mn);
        on(r->right,mx,mn);
        
    }
    void recoverTree(TreeNode* root) {
        in(root);
        int mx=INT_MIN,mn=INT_MAX;
        set<int>s(v.begin(),v.end());
        auto it = s.begin();
        for(int i =0;i<v.size();++i)
        {
            if(*it!=v[i])
            {
                mx = *it;
                mn = v[i];
                break;           
            }
                ++it;
        }
        on(root,mx,mn);
    }
};