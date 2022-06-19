class Solution {
public:
    vector<pair<int,int>>v;  
    vector<bool>b;
    int e,ver;
    void dfs(int i,vector<vector<int>>&g)
    {
        if(b[i])
            return;
        
        b[i]=true;
        ver++;
        for(auto c:g[i])
        {
            e++;
            if(!b[c])
            dfs(c,g);
        }
    }
    int makeConnected(int n, vector<vector<int>>& c) {
        b = vector<bool>(n);
        vector<vector<int>>g(n);
        for(auto x:c)
        {
            g[x[0]].push_back(x[1]);
            g[x[1]].push_back(x[0]);
        }
        int t=0;
        for(int i = 0;i<n;++i)
        {
            if(!b[i])
            {
                e = 0;
                t++;
                ver =0;
                dfs(i,g);
                v.push_back({e/2,ver});
            }
        }
        int ex = 0;
        for(auto c:v)
            ex+= abs((c.second-1)-c.first);
         return ex>=t-1?t-1:-1;
    }
};