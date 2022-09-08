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
    
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root==NULL) return ans;
        
         vector<int> ans1 = inorderTraversal(root->left);
        for(auto i:ans1){
            ans.push_back(i);
        }
        ans.push_back(root->val);
         vector<int> ans2 = inorderTraversal(root->right);
        for(auto i:ans2){
            ans.push_back(i);
        }
        return ans;
    }
};