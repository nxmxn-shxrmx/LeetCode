/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL)
            return NULL;
        
        Node* p = root;
        
        while(p)
        {
            Node* t = new Node();
            Node* w = t;
            while(p)
            {
                if(p->left)
                    t->next = p->left,t=t->next;
                if(p->right)
                    t->next = p->right,t = t->next;
                
                p = p->next;
            }
            p = w->next;
        }
        return root;
    }
};