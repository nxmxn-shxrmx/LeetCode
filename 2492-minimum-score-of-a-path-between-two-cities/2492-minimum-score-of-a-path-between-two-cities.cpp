class Solution {
public:
    vector<int>par;
    vector<int>size;
    vector<int>mh;
    int find(int i)
    {
        if(par[i]==-1)
        {
            return par[i]=i;
        }
        if(par[i]==i)return i;
        return par[i] =find(par[i]);
    }
    int minScore(int n, vector<vector<int>>& roads) {
        par = vector<int>(n+1,-1);
        size= vector<int>(n+1);
        vector<int>mh(n+1,INT_MAX);
        for(auto c:roads)
        {
            int x = c[0];
            int y = c[1];
            int cos = c[2];
            
            int u = find(c[0]);
            int v = find(c[1]);
            if(u==v)
                mh[u]= min(mh[u],cos);
            
            else
            {
                if(size[v]>size[u])swap(u,v);
                par[v]=u;
                size[u]+=size[v];
                mh[u] = min(mh[u],mh[v]);
                mh[u] = min(mh[u],cos);
            }
        }
        return mh[find(1)];
    }
};