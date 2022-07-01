class Solution {
public:
    map<char,char>m;
    map<char,long long>size;
    char find(char v)
    {
        if(m[v]==v)
            return v;
        
        return m[v]=find(m[v]);
    }
    void make(char a,char b)
    {
        
        if(m.find(a)==m.end() && m.find(b)==m.end())
        {
            if(a==b)
                return;
            m[a]=a;
            m[b]=a;
            size[a]+=2;
        }
        else if(m.find(a)==m.end())
        {
            char u = find(b);
            m[a]=u;
            size[u]+=1;
        }
        else if(m.find(b)==m.end())
        {
            char u = find(a);
            m[b]=u;
            size[u]+=1;
        }
        else
        {
            char u = find(a);
            char v = find(b);
            if(size[u]<size[v])
                swap(u,v);
            
            m[v]=u;
            size[u]+=size[v];
        }
    }
    bool equationsPossible(vector<string>& eq) {
        
        for(auto c:eq)
        {
            char a = c[0];
            char b = c[3];
        
            if(c[1]=='!')
            {
                if(a==b)
                    return false;
                if(m.find(a)==m.end() && m.find(b)==m.end())
                {
                    m[a]=a;
                    m[b]=b;
                    
                    size[a]=1;
                    size[b]=1;
                }
                else if(m.find(a)==m.end())
                {
                    m[a]=a;
                    size[a]+=1;
                }
                else if(m.find(b)==m.end())
                {
                    m[b]=b;
                    size[b]+=1;
                }
                else
                {
                    char u = find(a);
                    char v = find(b);
                    if(u==v)
                        return false;
                }
            }
            else
                make(a,b);
        }
        
        
        for(auto c:eq)
        {
            char a= c[0];
            char b = c[3];
            char u = find(a);
            char v = find(b);
            
            if(c[1]=='!')
            {
                if(u==v)
                    return false;
            }
            else
            {
                if(u!=v)
                    return false;
            }
        }
        return true;
    }
};