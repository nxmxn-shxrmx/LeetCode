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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*>q;
      int ans = 1;
        long long l = INT_MIN;
        q.push(root);
        int i =1;
        while(!q.empty())
        {
            long long u =  0;
            int sz= q.size();
            while(sz--)
            {
                auto it = q.front();
                q.pop();
                u+=it->val;
                if(it->left)q.push(it->left);
                if(it->right)q.push(it->right);
                
            }
    if(l<u)
    {
        l= u;
        ans =i;
    }
            ++i;
        }
     
      
        return ans;
    }
};