class Solution {
public:
    int dp[71][71][71];
    int f(int i,int j,int k,vector<vector<int>>&g)
    {
        if(i==g.size())
            return 0;
        
        if(j<0 || k<0 || j>=g[0].size() || k>=g[0].size())
            return 0;
        if(dp[i][j][k]!=-1)
            return dp[i][j][k];
        if(j==k)
            return dp[i][j][k]=max(max(f(i+1,j-1,k,g),f(i+1,j,k+1,g)),f(i+1,j-1,k+1,g))+g[i][j];
        
        int p =0;
        for(int x = j-1;x<=j+1;++x)
        {
            for(int y = k-1;y<=k+1;++y)
            p = max(p,f(i+1,x,y,g));
        }
            p+= g[i][k]+g[i][j];
        return  dp[i][j][k]=p;
    }
    int cherryPickup(vector<vector<int>>& g){
        int n = g.size();
        int m = g[0].size();
        memset(dp,-1,sizeof(dp));
        return f(0,0,m-1,g);
    }
};