class Solution {
public:
    int c = 0;
    void dfs(int i,int j,int &t,vector<vector<int>>&g)
    {
        if(i>=g.size() || i<0 || j>=g[0].size() || j<0 || g[i][j]!=1)
        return;
        
        t++;
        c=max(t,c);
        
        g[i][j]=0;
        dfs(i,j+1,t,g);
        dfs(i-1,j,t,g);
        dfs(i+1,j,t,g);
        dfs(i,j-1,t,g);
        
    }
    int maxAreaOfIsland(vector<vector<int>>& g) {
        
        
        for(int i = 0;i<g.size();++i)
        {
            for(int j = 0;j<g[0].size();++j)
            {
                if(g[i][j]==1)
                {
                    int t =0;
                    dfs(i,j,t,g);
                }
               
            }
        
        
        }
        return c;
    }
};