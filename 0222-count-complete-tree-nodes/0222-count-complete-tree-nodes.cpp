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
    int countNodes(TreeNode* root) {
        if(root==NULL)return 0;
        int h1 = 0;
        int h2 = 0;
        TreeNode* r = root;
        while(r)
            h1++,r=r->left;
        r =root;
        while(r)
            h2++,r=r->right;
        
        if(h1==h2)
            return pow(2,h1)+0.25-1;
        return countNodes(root->left)+countNodes(root->right)+1;
    }
};