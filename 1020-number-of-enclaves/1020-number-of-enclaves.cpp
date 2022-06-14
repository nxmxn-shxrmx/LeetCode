class Solution {
public:
    int u = 0;
    bool dfs(int i,int j,int &t,vector<vector<int>>&g)
    {
        if(i<0 || j<0 || i>=g.size() || j>=g[0].size())
            return true;
        if(g[i][j]==0)
            return false;
        g[i][j]=0;
        t++;

        u =max(t,u);
        bool k =dfs(i+1,j,t,g),l = dfs(i-1,j,t,g) ,m = dfs(i,j+1,t,g),n = dfs(i,j-1,t,g);
    
        return k||l||m||n;
    }
    int numEnclaves(vector<vector<int>>& g) {
        int c = 0;
        for(int i = 0;i<g.size();++i)
        {
            for(int j =0;j<g[0].size();++j)
            {
                int t =0;
                if(g[i][j]==1 && !dfs(i,j,t,g))
                    c+=u;
                u =0;
            }
        }

        return c;
    }
};