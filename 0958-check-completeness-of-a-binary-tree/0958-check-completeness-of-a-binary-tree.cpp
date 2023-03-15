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
    bool isCompleteTree(TreeNode* root) {
        int h = 0;
        if(root->left==0 && root->right==NULL)return 1;
        TreeNode* u = root;
        while(root->left!=NULL)
        root= root->left,h++;
        bool k =0;
        h-=1;
        queue<TreeNode*>q;
        q.push(u);
        while(!q.empty() && h--)
        {
            int sz = q.size();
            while(sz--)
            {
                TreeNode *p= q.front();
                q.pop();
            
                if(p->left ==NULL)return 0;
                if(p->right ==NULL)return 0;
                q.push(p->left);
                q.push(p->right);
            }
        }
    
        int sz =q.size();
        while(sz--)
        {
           TreeNode* p = q.front();
            q.pop();
            if(p->left &&k)return 0;
            if(p->left==NULL)k = 1;
            else q.push(p->left);
            if(p->right && k)return 0;
            if(p->right ==NULL)k =1;
            else q.push(p->right);
        }
        sz = q.size();
        while(sz--)
        {
            TreeNode* p = q.front();
            q.pop();
            if(p->left)return 0;
            if(p->right)return 0;
        }
        return 1;
    }
};