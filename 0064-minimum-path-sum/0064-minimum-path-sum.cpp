class Solution {
public:
    long long dp[201][201];
    int f(int i,int j,vector<vector<int>>g)
    {
        if(i==g.size()-1 && j==g[0].size()-1)
            return g[i][j];
        if(i>=g.size() || j>=g[0].size())
            return INT_MAX;
        if(dp[i][j]!=-1)
            return dp[i][j];
            
        return dp[i][j]=min(f(i+1,j,g),f(i,j+1,g))+g[i][j];
        
    }
    int minPathSum(vector<vector<int>>& grid) {
        
        dp[0][0]=grid[0][0];
        for(int i = 1;i<grid.size();++i)
            dp[i][0] = dp[i-1][0]+grid[i][0];    
        for(int j = 1;j<grid[0].size();++j)
            dp[0][j]=dp[0][j-1]+grid[0][j];
        
        for(int i = 1;i<grid.size();++i)
            for(int j = 1;j<grid[0].size();++j)
                dp[i][j]=min(dp[i-1][j],dp[i][j-1])+grid[i][j];
            
        return dp[grid.size()-1][grid[0].size()-1];
    }
};