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
        
        Node* t = root;
    
        while(t && t->left)
        {
            Node* r = t;
            Node* w = new Node();
            Node* q=w;
            
            while(r)
            {
                w->next=r->left;
                w = w->next;
                w->next = r->right;
                w = w->next;
                r = r->next;
            }
                
            t = q->next;
        }
        
        return root;
    }
};