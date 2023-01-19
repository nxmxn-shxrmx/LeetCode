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
    bool ans = 1;
    int h(TreeNode* r)
    {
        if(r==NULL)
            return 0;
        
        int h1 = h(r->left);
        int h2 = h(r->right);
        if(abs(h1-h2)>=2)
            ans = 0;
        return max(h1,h2)+1;
    }
    bool isBalanced(TreeNode* root) {
        h(root);
        return ans;
    }
};