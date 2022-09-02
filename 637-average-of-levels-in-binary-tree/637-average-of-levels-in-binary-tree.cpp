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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double>v;
        if(root==NULL)
            return v;
        
        v.push_back(root->val);
        queue<TreeNode*>q;
        q.push(root);
        
        while(!q.empty())
        {
            int s =q.size();
            double sum =0;
            int l=0;
            while(s--)
            {
                TreeNode* u=q.front();
                q.pop();
                if(u->right!=NULL)
                {
                    sum+=u->right->val;
                    l++;
                    q.push(u->right);
                }
                if(u->left!=NULL)
                {
                    sum+=u->left->val;
                    l++;
                    q.push(u->left);
               }
                
            }
            if(l==0)
                continue;
            v.push_back(sum/l*1.0);
        }
        return v;
    }
};