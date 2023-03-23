class Solution {
public:
    vector<int>par;
    vector<int>size;
    int find(int i)
    {
        if(par[i]==-1)return par[i]=i;
        if(par[i]==i)return i;
        return par[i] =find(par[i]);
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        par = vector<int>(n,-1);
        size = vector<int>(n,1);
        if((n-1)>(connections.size()))return -1;
        
        int ct = 0;
        for(auto c:connections)
        {
            int u = find(c[0]);
            int v = find(c[1]);
            
            if(u==v)
                continue;
            else
            {
                if(size[v]>size[u])swap(u,v);
                par[v]=par[u];
                size[u]+=size[v];
            }
        }
        for(int i = 0;i<n;++i)
        {
            int g = find(i);
            if(size[g]!=0)
            {
                size[g]=0;
                ct++;
            }
        }
        return ct-1;
            
    }
};