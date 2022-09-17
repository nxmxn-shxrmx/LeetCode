class Solution {
public:
    
    vector<int>m;
    vector<long long>s;
    void make(int a,int b)
    {
        if(m[a]==-1)
            m[a]=a,s[a]=1;
        if(m[b]==-1)
            m[b]=b,s[b]=1;
        int u = par(a);
        int v = par(b);
        
        if(u!=v)
        {
            if(s[v]>s[u])
                swap(v,u);
            m[v]=u;
            s[u]+=s[v];
        }
    }
    int par(int i)
    {
        if(i==m[i])
            return i;
        return m[i]=par(m[i]);
    }
    int regionsBySlashes(vector<string>& g) {
        m = vector<int>((g.size()+1)*(g.size()+1),-1);
        s = vector<long long>((g.size()+1)*(g.size()+1));
        int n = g.size();
    for(int i=1;i<=n;++i)
        {  
            make(i-1,i);
            make((i-1)*(n+1),i*(n+1));
            make(n*(n+1)+i-1,n*(n+1)+i);
            make((i-1)*(n+1)+n,i*(n+1)+n);
        }
        n++;
        int k= 0;
        for(int i = 0;i<g.size();++i)
        {
            for(int j = 0;j<g[0].size();++j)
            {
                if(g[i][j]=='/')
                {
                    int y = i*n+(j+1);
                    int x = (i+1)*(n)+j;
                    if(m[x]==-1)
                        m[x]=x,s[x]=1;
                    if(m[y]==-1)
                        m[y]=y,s[y]=1;
                    
                    int u =par(x);
                    int v =par(y);
                    if(m[u]==m[v])
                        k++;
                    
                        make(u,v);
                    
                }
                if(g[i][j]=='\\')
                {
                    int y = i*(n)+j;
                    int x = (i+1)*(n)+j+1;
                    if(m[x]==-1)
                        m[x]=x,s[x]=1;
                    if(m[y]==-1)
                        m[y]=y,s[y]=1;
                    
                    int u =par(x);
                    int v =par(y);
                    if(m[u]==m[v])
                        k++;
                    
                        make(u,v);
                    
                }
            }
        }
        
        return k+1;
    }
};

