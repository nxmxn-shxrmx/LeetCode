class Solution {
public:
    int dp[101][101];
    int barr(vector<vector<int>>&v,int i,int j)
    {
        if(i>=v.size() || j>=v[0].size() || i<0 || j<0 || v[i][j]==1)
        return 0;
        
        if(i==v.size()-1 && j==v[0].size()-1)
            return 1;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        return dp[i][j]=barr(v,i+1,j)+barr(v,i,j+1);
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& g) {
        if(g[g.size()-1][g[0].size()-1]==1)
            return 0;
        memset(dp,-1,sizeof(dp));
        return barr(g,0,0);
        
    }
};