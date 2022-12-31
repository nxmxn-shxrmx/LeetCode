class Solution {
public:
    vector<vector<int>>vis;
    
    int f(int i,int j ,vector<vector<int>>&grid,int p)
    {
        if(i<0 || j<0 || i==grid.size() || j==grid[0].size() || grid[i][j]==-1 || vis[i][j])
            return 0;
        if(grid[i][j]==2)
        {
            if(p==0)
            return 1;
            
            return 0;
        }
        vis[i][j]=1;
        if(grid[i][j]==0)
            p--;
        int d[5]={1,0,-1,0,1};
        int k = 0;
        for(int c = 1;c<5;++c)
            k+=f(i+d[c-1],j+d[c],grid,p);
        vis[i][j]=0;
        return k;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int p = 0;
        int x = 0;
        int y = 0;
        vis = vector<vector<int>>(grid.size(),vector<int>(grid[0].size()));
        for(int i = 0;i<grid.size();++i)
        {
            for(int j = 0;j<grid[0].size();++j)
            {
                if(grid[i][j]==0)
                    p++;
                if(grid[i][j]==1)
                x = i,y=j; 
            }
        }
      
        return f(x,y,grid,p);
    }
};