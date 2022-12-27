class Solution {
public:
    
    int find(int i,vector<int>&m)
    {
        if(m[i]==0)
            return m[i]=i;
        if(m[i]==i)
            return i;
        return m[i]=find(m[i],m);
    }
    void make(int a,int b,vector<int>&m,vector<int>&si)
    {
        if(m[a]==0)
            m[a]=a,si[a]=1;
        
        if(m[b]==0)
            m[b]=b,si[b]=1;
        
        int u = find(a,m);
        int v = find(b,m);
    
        if(u==v)   return;
        
        
        if(si[v]>si[u]) swap(u,v);
        m[v]=u;
        si[u]+=si[v];
    }
    vector<bool> areConnected(int n, int t, vector<vector<int>>& queries) {
        vector<int>m(n+1);
        vector<int>si(n+1);
        for(int i = t+1;i<=n;++i)
        {
            int p = 1;
            p =max(t+1,p);
            for(int j=i+i;j<=n;j=j+i)
                    make(i,j,m,si);
        
        }
        vector<bool>b;
        for(auto c:queries)
        {
            int u = find(c[0],m);
            int v = find(c[1],m);
            if(u==v)
                b.push_back(1);
            else
                b.push_back(0);
        }
       
        return b;
    }
};