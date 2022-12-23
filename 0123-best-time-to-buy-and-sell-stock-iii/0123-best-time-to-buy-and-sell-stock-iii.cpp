class Solution {
public:
    int dp[100001][2][2];
    int f(int i,int k,int b,vector<int>&v)
    {
        if(i==v.size() || k==2)
            return 0;
        
        if(dp[i][b][k]!=-1)
            return dp[i][b][k];
        if(b)
            return dp[i][b][k]=max(f(i+1,k,0,v)-v[i],f(i+1,k,b,v));
        
        return dp[i][b][k]=max(f(i+1,k+1,1,v)+v[i],f(i+1,k,b,v));
    }
    int maxProfit(vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        return f(0,0,1,prices);
    }
};
