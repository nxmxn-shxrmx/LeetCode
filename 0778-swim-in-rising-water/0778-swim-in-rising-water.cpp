class Solution {
public:
    int ans =INT_MAX;
    vector<vector<int>>vis;
    bool check(int i,int j,vector<vector<int>>&v,int m)
    {
      
        if(i==v.size()-1 && j==v.size()-1)
            return 1;
        
        
        vis[i][j]=1;
        int d[4][2]={{1,0},{-1,0},{0,-1},{0,1}};
        for(auto c:d)
    if(i+c[0]>=0 && j+c[1]>=0 && i+c[0]<v.size() && j+c[1]<v.size() && !vis[i+c[0]][j+c[1]] && v[i+c[0]][c[1]+j]<=m)
    {
            if(check(i+c[0],j+c[1],v,m))
                return 1;
    }
      
        return 0;
    }
    int swimInWater(vector<vector<int>>& grid) {
        int l = max(grid[0][0],grid[grid.size()-1][grid.size()-1]);
        int r = grid.size()*grid.size()-1;
      
        while(l<=r)
        {
            int m = l+(r-l)/2;
            vis = vector<vector<int>>(grid.size(),vector<int>(grid.size()));
            if(check(0,0,grid,m))
                r = m-1,ans=m;
            else
                l = m+1;
        }
        return ans;
    }
};