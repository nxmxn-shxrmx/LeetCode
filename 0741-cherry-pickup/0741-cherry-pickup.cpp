class Solution {
public:
    int dp[51][51][51];
    int e = 0;
    int f(int i,int j,int a,int b,vector<vector<int>>&g)
    {
          if(i>=g[0].size() || j>=g[0].size() || a>=g[0].size() || b>=g[0].size() || g[i][j]==-1 || g[a][b]==-1)
            return -99999;
        if( i==g[0].size()-1 && j==g[0].size()-1)
        {
            e=1;
    
            return g[i][j];
        }
        if(dp[i][j][b]!=-1)
            return dp[i][j][b];
        int ans= 0;
        ans = max(f(i+1,j,a+1,b,g),f(i+1,j,a,b+1,g));
        ans = max(ans,f(i,j+1,a+1,b,g));
        ans = max(ans,f(i,j+1,a,b+1,g));
    
         ans+=g[i][j];
        if(a!=i || j!=b)
            ans+=g[a][b];
        
        return dp[i][j][b]=ans;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
    
        int ans=f(0,0,0,0,grid);
        if(e)
            return ans;
        
        else
            return 0;
    }
};