class Solution {
public:
    int dp[51][51][2501];
    int f(int i,int j,int t,vector<vector<int>>&v)
    {
        if(i==v.size()-1 && j==v[0].size()-1)
            return max(t,v[i][j]);
        if(i<0 || j<0 || i>=v.size() || j>=v[0].size() || v[i][j]==-1)
            return INT_MAX;
        if(dp[i][j][t]!=-1)
            return dp[i][j][t];
        int d[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
        
        int p =-1;
        int k = INT_MAX;
        swap(v[i][j],p);
        for(auto c:d)
            k = min(k,f(i+c[0],j+c[1],max(t,p),v));
        swap(v[i][j],p);
        return dp[i][j][t]=k;
    }
    int swimInWater(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        return f(0,0,0,grid);
    }
};