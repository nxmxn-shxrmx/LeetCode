class Solution {
public:
    bool dfs(int i,int j,vector<vector<int>>&g)
    {
        if(i<0 || j<0 || i>=g.size() || j>=g[0].size())
            return false;
        
        if(g[i][j]==1)
            return 1;
        g[i][j]=1;
       bool h = dfs(i-1,j,g);
    bool k =dfs(i+1,j,g),y = dfs(i,j-1,g),m = dfs(i,j+1,g);  
        
        return h&&k&&m&&y;
        
    }
    int closedIsland(vector<vector<int>>& g) {
        int c =0;
        for(int i = 1;i<g.size()-1;++i)
        {
            for(int j = 1;j<g[0].size()-1;++j)
            {
                if(g[i][j]==0)
                {
                    if(dfs(i,j,g))
                        c++;
                }
            }
        }
        return c;
    }
};