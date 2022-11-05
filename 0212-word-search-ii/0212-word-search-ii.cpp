struct Node
{
    Node* link[26];
    string flag;
};
class Solution {
public:
    
     vector<string>v;
    void f(int i ,int j ,Node* r,vector<vector<char>>&b)
    {
        if(r->flag.size())
    v.push_back(r->flag),r->flag ="";
    
        if(i<0 || j<0 || i>=b.size() || j>=b[0].size() || b[i][j]=='.')
            return;
        
        int d[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
        char y = '.';
        if(r->link[b[i][j]-'a']!=NULL)
        {
                    
                    swap(y,b[i][j]);
                    for(auto c:d)
                    f(i+c[0],j+c[1],r->link[y-'a'],b);
                    swap(y,b[i][j]); 
        }
        
    }
     Node* g = new Node();
    vector<string> findWords(vector<vector<char>>& b, vector<string>& words) {
       
        Node* root = g;
        
        for(auto c:words)
        {
            root = g;
            for(auto x:c)
            {
                if(root->link[x-'a']==NULL)
                    root->link[x-'a']=new Node();
                
                    root = root->link[x-'a'];
            }
            root->flag=c;
        }
        root=g;
        for(int i = 0;i<b.size();++i)
        {
            for(int j = 0 ;j<b[0].size();++j)
            {
            
                int d[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
                char y = '.';
                if(root->link[b[i][j]-'a']!=NULL)
                {
                    string p="";
                    p+=b[i][j];
                    swap(y,b[i][j]);
                    for(auto c:d)
                    f(i+c[0],j+c[1],root->link[y-'a'],b);
                    swap(y,b[i][j]); 
                }
            }
                
        }
        
        return v;
        
    }
};