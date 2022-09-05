/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        
        if(root==NULL)
            return {};
        vector<vector<int>>v;
        queue<Node*>q;
        q.push(root);
        v.push_back({root->val});
        while(!q.empty())
            {
            int sz=q.size();
             vector<int>s;
            while(sz--)
            {
            Node* r=q.front();
            q.pop();
           
            for(auto c:r->children)
                {
                s.push_back(c->
val);
                if(c->children.size())
                    q.push(c);
                    
            }
                
                }
            if(s.size())
            v.push_back(s);
            }
        
       return v;
    }
};