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
    unordered_map<TreeNode*,int>m; 
    int h(TreeNode* r)
    {
        if(r==NULL)
            return 0;
        if(m.find(r)!=m.end())
            return m[r];
        int h1 =h(r->left);
        int h2 =h(r->right);
        return m[r]=max(h1,h2)+1;
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL)
            return 1;
        if(!isBalanced(root->left) || !isBalanced(root->right))
            return 0;
        int h1 = h(root->left);
        int h2 = h(root->right);
        if(abs(h1-h2)>=2)
            return 0;
        return 1;
    }
};