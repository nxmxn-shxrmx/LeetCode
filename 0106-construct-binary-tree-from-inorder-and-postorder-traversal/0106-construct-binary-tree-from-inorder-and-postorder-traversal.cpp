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
    TreeNode* sub(vector<int>p,int l,int r,int &i)
    {
        if(l>r)
            return NULL;
        
        int f = m[p[i]];
        TreeNode* ro = new TreeNode(p[i--]);
        ro->right = sub(p,f+1,r,i);
        ro->left  = sub(p,l,f-1,i);
        return ro;
    }
    
    TreeNode* buildTree(vector<int>& in, vector<int>& po) {
        if(in.size()==0)
            return NULL;            
        for(int i = 0;i<in.size();++i)
        {
            m[in[i]]=i;
        }
        int i =po.size()-1;
        return sub(po,0,po.size()-1,i);
    }
};