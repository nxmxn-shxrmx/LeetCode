class Solution {
public:
    vector<int>co;
    vector<int>ans;
    void dfs(int i,int pre,vector<vector<int>>&g)
    {
        for(auto c:g[i])
        {
            if(pre!=c)
            {
                dfs(c,i,g);
                co[i]+=co[c];
                ans[i]+=co[c]+ans[c];
            }
        }
    }
     void dfs1(int i,int pre,vector<vector<int>>&g)
    {
        for(auto c:g[i])
        {
            if(pre!=c)
            {
                ans[c]=ans[i]-co[c]+g.size()-co[c];
                dfs1(c,i,g);
            }
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>>g(n);
        for(auto c:edges)
        {
            g[c[0]].push_back(c[1]);
            g[c[1]].push_back(c[0]);
        }
    co = vector<int>(n,1);
        ans = vector<int>(n);
       dfs(0,-1,g);
       dfs1(0,-1,g);
        return ans;
    }
};
