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
   
        if(root==NULL) return  {};

        vector<int>ans;
        stack<TreeNode*>st;
        TreeNode* r = root;
        while(r||!st.empty())
        {
            while(r)
            {
                st.push(r);
                r =r->left;
            }
            r= st.top();
            st.pop();
            ans.push_back(r->val);
            r = r->right;
        }
        return ans;
    }
};