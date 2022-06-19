class Solution {
public:
    
    vector<bool>b;
    void dfs(int i,vector<vector<int>>&g)
    {
        if(b[i])
            return;
        
        b[i]=true;
        for(auto c:g[i])
        {
            if(!b[c])
            dfs(c,g);
        }
    }
    int makeConnected(int n, vector<vector<int>>& c) {
        b = vector<bool>(n);
        vector<vector<int>>g(n);
        
        if(c.size()<n-1)
            return -1;
        
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
                t++;
                dfs(i,g);
            }
        }
         return t-1;
    }
};