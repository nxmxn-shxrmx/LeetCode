class Solution {
public:
    long long ans = 0;
    vector<int>par;
    vector<int>size;
    int find(int i)
    {
        if(par[i]==-1)
            return par[i] =i;
        if(par[i]==i)return i;
        return par[i] =find(par[i]);
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        
        par =vector<int>(n,-1);
        size = vector<int>(n,1);
        for(auto c:edges)
        {
            int u= find(c[0]);
            int v = find(c[1]);
            if(u!=v)
            {
                if(size[v]>size[u])swap(u,v);
                size[u]+=size[v];
                par[v] = u;
            }
        }
        int p = n;
        for(int i = 0;i<n;++i)
        {
            if(size[find(i)])
            {
                long long u = p-size[find(i)];
                long long v = size[find(i)];
                ans = ans + u*v;
                p-=size[find(i)];
                size[find(i)]=0;
            }
        }
        return ans;
    }
};