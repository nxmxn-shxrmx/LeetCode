class Solution {
public:
    map<int,int>m;
    map<int,long long>s;
    int find(int v)
    {
        if(m[v]==v)
            return v;
        return m[v]=find(m[v]);
    }
    void make(int a,int b)
    {
        if(m.find(a)==m.end())
            m[a]=a,s[a]=1;
        if(m.find(b)==m.end())
            m[b]=b,s[b]=1;
        
        int u =find(a);
        int v =find(b);
        
        if(s[v]>s[u])
            swap(v,u);
        
        m[v]=u;
        s[u]+=s[v];
    }
    
    int regionsBySlashes(vector<string>& g) {
     
        if(g.size()==0)
            return 0;
        int n=g.size();
        for(int i=1;i<=n;++i)
        {  
            make(i-1,i);
            make((i-1)*(n+1),i*(n+1));
            make(n*(n+1)+i-1,n*(n+1)+i);
            make((i-1)*(n+1)+n,i*(n+1)+n);
        }
        int c=0;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)
            {
                if(g[i][j]==' ')
                    continue;
                if(g[i][j]=='/')
                {
                    int co = i*(n+1)+(j+1);
                    int ro = (i+1)*(n+1)+j;
                    
                    if(m.find(co)==m.end())
                    {
                        m[co]=co;
                        s[co]=1;
                    }
                    if(m.find(ro)==m.end())
                    {
                        m[ro]=ro;
                        s[ro]=1;
                    }
                    int u = find(co);
                    int v = find(ro);
                    if(m[u]==m[v])
                        c++;
                    make(ro,co);
                }
                else
                {
                    int co = i*(n+1)+j;
                    int ro = (i+1)*(n+1)+j+1;
                       if(m.find(co)==m.end())
                    {
                        m[co]=co;
                        s[co]=1;
                    }
                    if(m.find(ro)==m.end())
                    {
                        m[ro]=ro;
                        s[ro]=1;
                    }
                    int u = find(co);
                    int v = find(ro);
                    if(m[u]==m[v])
                        c++;
                    make(ro,co);
                }
            }
        }
        
        return c+1;   
    }
};