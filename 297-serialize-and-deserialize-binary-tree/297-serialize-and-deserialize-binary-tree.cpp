/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    string s;
    
    void preorder(TreeNode* root)
    {
        if(!root)
        {
            s+='n';
            s+=',';
            return ;
        } 
        
        s+=to_string(root->val);
        s+=',';
        
        preorder(root->left);
        preorder(root->right);
    }
    
    string serialize(TreeNode* root) {
        
        if(!root)
            return "";
        
        s="";
        preorder(root);
        
        return s;
    }

    // Decodes your encoded data to tree.
    int i;
    
    TreeNode* deserialize(string s,int n)
    {
        string t="";
        for(i;i<n;i++)
        {
            if(s[i]==',')
                break;
            
            t+=s[i];
        }
        i++;
        
        if(t=="n")
            return NULL;
        
        TreeNode *root=new TreeNode(stoi(t));
        root->left=deserialize(s,n);
        root->right=deserialize(s,n);
        
        return root;
    }
    
    TreeNode* deserialize(string s) {
        
        if(s.size()==0)
            return NULL;
        
        int n=s.size();  
        i=0;
        return deserialize(s,n);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));