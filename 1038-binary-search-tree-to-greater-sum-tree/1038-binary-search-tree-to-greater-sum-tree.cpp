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
    void in(TreeNode* &root,int &c)
    {
        if(root==NULL)
            return;
        in(root->right,c);
        root->val +=c;
        c = root->val;
        in(root->left,c);
    }
    TreeNode* bstToGst(TreeNode* root) {
        int c =0;
        in(root, c);
        return root;
    }
};