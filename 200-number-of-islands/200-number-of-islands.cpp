class Solution {
public:
    void dfs(int i,int j,vector<vector<char>>&g)
    {
        if(i<0 || j<0 || j==g[0].size() || i==g.size() || g[i][j]!='1')
            return;
        
        g[i][j]='0';
        dfs(i+1,j,g);
        dfs(i-1,j,g);
         dfs(i,j+1,g);
        dfs(i,j-1,g);
    }
    int numIslands(vector<vector<char>>& g) {
        int c=0;
        for(int i=0;i<g.size();++i)
        {
            for(int j =0;j<g[0].size();++j)
            {
                if(g[i][j]=='1')
                    dfs(i,j,g),c++;
            }
        }
        return c;
    }
};