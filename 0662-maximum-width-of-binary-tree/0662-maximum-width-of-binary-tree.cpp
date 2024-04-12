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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL)return 0;
        queue<pair<TreeNode*,unsigned long long>>q;
        q.push({root,1});
        long long ans = 0;
        while(!q.empty())
        {
            int sz = q.size();
            long long mx = 0;
            long long int mn = 0;
            
            for(int i = 0;i<sz;++i)
            {
                TreeNode* u = q.front().first;
           unsigned    long long   int r = q.front().second;
                q.pop();
                if(i==0)mn = r;
                if(i==sz-1)mx = r;
                
                if(u->left)
                    q.push({u->left,2*r-1});
                if(u->right)
                    q.push({u->right,2*r});
            }
            ans = max(ans,mx-mn+1);
        }
        return ans;
    }
};