class Solution {
public:
    vector<vector<bool>>b;
    int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
    bool sea(int i,int j,vector<vector<char>>&v,int l,string s)
    {
        if(l==s.size())
            return true;
        
        if(i<0 || j<0 || i>=v.size() || j>=v[0].size() || v[i][j]!=s[l])
            return false;
        
          char t ='*';
        swap(v[i][j],t);
         for(auto c:dir)
         {
             if(sea(i+c[0],j+c[1],v,l+1,s))
                   return true;
         }
 swap(v[i][j],t);
        return false;
        
    }
    bool exist(vector<vector<char>>& v, string w) {
        b = vector<vector<bool>>(v.size(),vector<bool>(v[0].size()));
        for(int i=0;i<v.size();++i)
        {
            for(int j=0;j<v[0].size();++j)
            {
                if(v[i][j]==w[0])
                {
                    
char t ='*';
        swap(v[i][j],t);
                    for(auto c:dir)
                    {
                        if(sea(i+c[0],j+c[1],v,1,w))
                            return true;
                    }
        
        swap(v[i][j],t);
                }
            }
        }
        return false;
    }
};