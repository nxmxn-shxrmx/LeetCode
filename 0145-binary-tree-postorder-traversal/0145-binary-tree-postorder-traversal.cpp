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
    
    void a(vector<int>&v,TreeNode* root)
    {
        if(root==NULL)
            return;
        
       
        a(v,root->left);
        a(v,root->right);
        
         v.push_back(root->val);
            
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>v;
        stack<TreeNode*>st;
        TreeNode* cur= root;
        TreeNode* las = nullptr;
        while(cur||!st.empty())
        {
            if(cur)
            {
                st.push(cur);
                cur = cur->left;
            }
            else
            {
                TreeNode* u = st.top();        
                if(u->right && u->right!=las)
                    cur = u->right;
                else
                {
                    v.push_back(st.top()->val);
                    las = st.top();
                    st.pop();
                }
            }
        }


    return v;
    }
};