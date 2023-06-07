class Solution {
public:
    int dp[201][201];
    int f(int i,int j,vector<vector<int>>&v,int t,int m)
    {
        if(i==v.size()-1 && j==v[0].size()-1)
        {
            if(v[i][j]>=0)
                return 0;
            return abs(v[i][j]);
        }
        if(i==v.size() || j==v[0].size())return INT_MAX;
        if(dp[i][j]!=-1)return dp[i][j];
        int p =min(f(i+1,j,v,t,m),f(i,j+1,v,t,m));
        if(v[i][j]>0)
        {
            if(v[i][j]>=p)return dp[i][j]=0;
            return dp[i][j]= p-v[i][j];
        }
        return dp[i][j]=p+abs(v[i][j]);
    }
    int calculateMinimumHP(vector<vector<int>>& d) {
        memset(dp,-1,sizeof(dp));
        
        return f(0,0,d,0,0)+1;
    }
};