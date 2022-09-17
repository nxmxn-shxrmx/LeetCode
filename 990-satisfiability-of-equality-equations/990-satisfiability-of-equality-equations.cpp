class Solution {
public:
    map<char,char>m;
    map<char,long long>s;
    
    char par(char c)
    {
        if(m[c]==c)
            return c;
        return m[c]=par(m[c]);
    }
    bool equationsPossible(vector<string>& e) {
        
        for(auto c:e)
        {
            char a = c[0];
            char b = c[3];
            
            if(c[1]=='=')
            {
                if(m.find(a)==m.end() && m.find(b)==m.end())
                {
                    m[a]=a;
                    s[a]+=2;
                    m[b]=a;
                }
                else if(m.find(a)==m.end())
                {
                    char x=par(b);
                    m[a]=x;
                    s[x]+=1;
                }
                else if(m.find(b)==m.end())
                {
                    char x=par(a);
                    m[b]=x;
                    s[x]+=1;
                }
                else
                {
                    char x =par(a);
                    char y = par(b);
                    if(x==y)
                        continue;
                    if(s[y]>s[x])
                        swap(x,y);
                    m[y]=x;
                    s[x]+=s[y];
                }
            }
            
            else
            {
                if(a==b)
                    return false;
                 if(m.find(a)==m.end() && m.find(b)==m.end())
                {
                    m[a]=a;
                    s[a]=1;
                    s[b]=1;
                    m[b]=b;
                }
                else if(m.find(a)==m.end())
                {
                    char x=par(b);
                    m[a]=a;
                    s[a]+=1;
                }
                else if(m.find(b)==m.end())
                {
                    m[b]=b;
                    s[b]=1;
                }
                else
                {
                    char x =par(a);
                    char y = par(b);
                    if(x==y)
                        return false;
                }
            }
        }
        for(auto c:e)
        {
            char a = par(c[0]);
            char b = par(c[3]);
        
            if(c[1]=='=')
                if(a!=b)
                return false;
            if(c[1]=='!')
                if(a==b)
                return false;
                
        }
        return true;
    }
};