/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    map<int,Node*>m;
    Node* f(Node* r)
    {
        if(r==NULL)
            return NULL;
        Node* e = new Node(r->val);
        // cout<<r->val<<" ";
        m[r->val]=e;
        for(auto c:r->neighbors)
        {
            if(m[c->val]==NULL)
            e->neighbors.push_back(f(c)); 
                else
                     e->neighbors.push_back(m[c->val]);
        }
        return e;
    }
    Node* cloneGraph(Node* node) {
       
        return f(node);
    }
};