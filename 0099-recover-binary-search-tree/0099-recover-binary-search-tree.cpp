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
    vector<int>p;
    void in(TreeNode* r)
    {
        if(r==NULL)return;
        in(r->left);
       
        v.push_back(r->val);
        p.push_back(r->val);
        in(r->right);
    }
    void f(TreeNode* &r,int a,int b)
    {
        if(r==NULL)return;
        
        if(r->val==a)r->val =b;
        else if(r->val==b)r->val =a;
        
        f(r->left,a,b);
        f(r->right,a,b);
    }
    void recoverTree(TreeNode* root) {
        in(root);
      
        sort(p.begin(),p.end());
        int a = 0;
        int b = 0;
        for(int i = 0;i<p.size();++i)
        {
            if(p[i]!=v[i])
            {
                cout<<p[i]<<" ";
                a = p[i];
                b = v[i];
                break;
            }
        }
        f(root,a,b);
        
    }
};
