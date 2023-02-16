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
    int maxDepth(TreeNode* root) {
        if(root==NULL)
            return 0;
        
//         queue<TreeNode*>q;
//       int  c =1;
//         q.push(root);
        
//         while(!q.empty())
//         {
//             int s = q.size();
            
            
//             int r = 0;
//             for(int i =0;i<s;++i)
//             {
//                 TreeNode* w = q.front();
//                     q.pop();
//                 if(w->left!=NULL)
//                 {   r++;
//                     q.push(w->left);
//                 }
//                 if(w->right!=NULL)
//                 {
//                     r++;
//                     q.push(w->right);
//                 }
//             }
//             if(r>0)
//                 c++;

//         }
        return max(maxDepth(root->left),maxDepth(root->right))+1;
    }
};